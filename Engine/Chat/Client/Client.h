#pragma once
#include <WinSock2.h> //For SOCKET
#include <string> //For std::string
#include "FileTransferData.h" //For FileTransferData class
#include "PacketManager.h" //For PacketManager class
#include "..\ChatLog.h"

class Client
{
public:
	enum ConnectionState
	{
		Idle,
		Connected,
		Disconnected
	};
	Client(std::string _yesORno, const int _PORT, ChatLog& _log);
	void Update();
	bool Connect(std::string IP = "127.0.0.1");
	void Disconnect();
	bool CloseConnection();
	void SendString(const std::string& _string);
	bool RequestFile(const std::string& _fileName);
	bool SendFile(const std::string& _fileName);
	void SetName(const std::string _name);
	void HandleInput(const std::string& _message);
	ChatLog& GetChatLog() { return *chatLog; };
	~Client();
private:
	//-- Processing methods
	bool ProcessPacket(const PacketType _packettype);

	//-- Thread methods
	static void ClientThread(Client& _client);
	static void PacketSenderThread(Client& _client);
	
	//-- Send methods
	bool SendAll(const char* _data, const int _totalBytes);

	//-- Get methods
	bool GetAll(char* data, const int _totalBytes);
	bool GetInt32_t(std::int32_t& _int32_t);
	bool GetPacketType(PacketType &_packettype);
	bool GetString(std::string &_string);
private:
	FileTransferData m_file;
	PacketManager m_pm;
	SOCKADDR_IN m_addr;
	SOCKET m_connection;
	ConnectionState conState;
	bool m_terminateThreads = false;
	bool m_isConnected = false;
	std::thread m_pst; //Create thread to send packets
	std::thread m_ct; //Create thread to listen to server

	std::string userName;
	ChatLog* chatLog;
};