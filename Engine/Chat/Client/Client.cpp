#include "Client.h"
#include "PacketStructs.h"
#include <Ws2tcpip.h> //for inet_pton
#pragma comment(lib,"ws2_32.lib") //Required for WinSock


void Client::ClientThread(Client& _client)
{
	PacketType packettype; 
	while (true)
	{
		if (_client.m_terminateThreads)
		{
			break;
		}
		if (!_client.GetPacketType(packettype))
		{
			break;
		}
		if (!_client.ProcessPacket(packettype))
		{
			break;
		}
	}
	_client.conState = Disconnected;
	_client.m_terminateThreads = true;
}

void Client::PacketSenderThread(Client& _client)
{
	while (true)
	{
		if (_client.m_terminateThreads == true)
			break;
		if (_client.m_pm.HasPendingPackets())
		{
			std::shared_ptr<Packet> p = _client.m_pm.Retrieve();
			if (!_client.SendAll((const char*)(&p->m_buffer[0]), p->m_buffer.size()))
				break;
		}
	}
}

void Client::Update()
{
	if (!m_terminateThreads)
	{
		if (conState == Disconnected)
		{
			Disconnect();
			conState = Idle;
		}
	}
}

bool Client::RequestFile(const std::string& _fileName)
{
	if (m_isConnected)
	{
		if (m_file.m_transferInProgress)
		{
			chatLog->UpdateLog("Client", "UHOH: Function(Client::RequestFile) - File Transfer already in progress.\n");
			return false;
		}
		m_file.m_transferInProgress = true;
		//std::string path = "ClientDownloads\\";
		m_file.m_outfileStream.open(/*path +*/ _fileName, std::ios::binary);
		chatLog->UpdateLog("Client", "Opening " + /*path +*/ _fileName + " for writing file to.");

		if(!m_file.m_outfileStream.is_open())
		{
			chatLog->UpdateLog("Client", "File " + /*path +*/ _fileName + " Is not open.");
			m_file.m_outfileStream.open(/*path +*/ _fileName, std::ios::binary);
		}
		m_file.m_fileName = _fileName;
		m_file.m_bytesWritten = 0;
		if (!m_file.m_outfileStream.is_open())
		{
			chatLog->UpdateLog("Client", "UHOH: Function(Client::Requestfile) - Unable to open file: " + _fileName + " for writing.\n");
			return false;
		}
		chatLog->UpdateLog("Client", "Requesting file from server: " + _fileName);
		Packet requestFilePacket;
		requestFilePacket.Append(PacketType::FileTransferRequestFile);
		requestFilePacket.Append(m_file.m_fileName.size());
		requestFilePacket.Append(m_file.m_fileName.c_str(), m_file.m_fileName.size());
		m_pm.Append(std::make_shared<Packet>(requestFilePacket));
		chatLog->UpdateLog("Client", "Received file name: " + _fileName + " from server.");
		return true;
	}
	else
	{
		chatLog->UpdateLog("UHOHS", "ERROR: USER IS A DUMBER THAN DIRT, TRIED TO GET A FILE WHILE NOT CONNECTED TO ANYTHING.");
		return false;
	}
}

bool Client::SendFile(const std::string& _fileName)
{
	if (m_isConnected)
	{
		Packet ClientSendFile;
		ClientSendFile.Append(PacketType::ClientSendFileRequest);
		ClientSendFile.Append(_fileName.size());
		ClientSendFile.Append(_fileName.c_str(), _fileName.size());
		m_pm.Append(std::make_shared<Packet>(ClientSendFile));
		return true;
	}
	else
	{
		chatLog->UpdateLog("UHOHS", "Wow, user tried to send a file while not connected to anything.");
		return false;
	}
}

void Client::SetName(const std::string _name)
{
	if (m_isConnected)
	{
		Packet ClientSendFile;
		ClientSendFile.Append(PacketType::ClientSetName);
		ClientSendFile.Append(_name.size());
		ClientSendFile.Append(_name.c_str(), _name.size());
		m_pm.Append(std::make_shared<Packet>(ClientSendFile));
		userName = _name;
		chatLog->UpdateLog("Client", "Set name on server to " + _name);
	}
	else
	{
		chatLog->UpdateLog("UHOHS", "You can't set your name on a server you aren't connected to. Kill yourself.");
	}
}

void Client::HandleInput(const std::string& _message)
{	
	switch (_message[0])
	{
	case '/':
	{
		if (_message == "/exit" || _message == "/Exit")
		{
			chatLog->OutputLog();
			Disconnect();
			exit(0);
		}
		else
		{
			chatLog->UpdateLog("Client", "That isn't a // command. Take a dump on the floor.");
		}

		break;
	}
	default:
		if (_message.size() < 1)
			break;
		chatLog->UpdateLog(userName, _message);
		SendString(":" + _message);
		break;
	}
}