#include "Client.h"
#include <Ws2tcpip.h> //for inet_pton
#pragma comment(lib,"ws2_32.lib") 

Client::Client(std::string _yesORno, int _PORT, ChatLog& _log)
{
	//-- Assigning variables default values --\/
	chatLog = &_log;
	conState = Idle;
	//----------------------------------------//
	//-- Winsock startup \/
	WSADATA wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(0);
	}

	m_addr.sin_port = htons(_PORT); //Port 
	m_addr.sin_family = AF_INET; //IPv4 Socket
}

bool Client::Connect(std::string IP)
{
	if (m_isConnected)
		return false;

	std::string temp = IP;
	int i = inet_pton(AF_INET, temp.c_str(), &m_addr.sin_addr.s_addr); //Server Address [127.0.0.1] = localhost

	m_connection = socket(AF_INET, SOCK_STREAM, 0);
	int sizeofaddr = sizeof(m_addr);
	if (connect(m_connection, (SOCKADDR*)&m_addr, sizeofaddr) != 0)
	{
		chatLog->UpdateLog("Client", "Failed to connect to server. Winsock Error: " + std::to_string(WSAGetLastError()));
		MessageBoxA(NULL, "Failed to Connect", "Big Uh Oh", MB_OK | MB_ICONERROR);
		return false;
	}
	conState = Connected;
	m_isConnected = true;
	m_terminateThreads = false;
	chatLog->UpdateLog("Client", "Connected to server!");

	if (m_pst.joinable())
		m_pst.join();
	if (m_ct.joinable())
		m_ct.join();
	m_pst = std::thread(PacketSenderThread, std::ref(*this)); //Create thread to send packets
	m_ct = std::thread(ClientThread, std::ref(*this)); //Create thread to listen to server
	return true;
}

void Client::Disconnect()
{
	if (m_isConnected)
	{
		CloseConnection();
		m_pm.Clear();
		if (m_pst.joinable())
			m_pst.join();
		if (m_ct.joinable())
			m_ct.join();
		if (m_file.m_infileStream.is_open())
			m_file.m_infileStream.close();
		if (m_file.m_outfileStream.is_open())
			m_file.m_outfileStream.close();
		m_file.m_transferInProgress = false;
		m_isConnected = false;

		chatLog->UpdateLog("Client", "Disconnected from server");
	}
	else
	{
		chatLog->UpdateLog("UHOHS", "Dummy, You can't disconnect if the socket isn't connected to anything. Git gud.");
	}

}

bool Client::CloseConnection()
{
	m_terminateThreads = true;
	if (closesocket(m_connection) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAENOTSOCK)
			return true;

		std::string ErrorMessage = "Failed to close socket. Winsock Error: " + std::to_string(WSAGetLastError()) + ".";
		MessageBoxA(NULL, ErrorMessage.c_str(), "UHOHS", MB_OK | MB_ICONERROR);
		return false;
	}
	return true;
}

Client::~Client()
{
	CloseConnection();
	if (m_ct.joinable())
		m_ct.join();
	if(m_pst.joinable())
		m_pst.join();
}