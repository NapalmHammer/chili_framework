#include "Client.h"
#pragma comment(lib,"ws2_32.lib") 
#include "PacketStructs.h"
bool Client::GetAll(char* _data, int _totalBytes)
{
	int bytesReceived = 0;
	while (bytesReceived < _totalBytes)
	{
		int retnCheck = recv(m_connection, _data + bytesReceived, _totalBytes - bytesReceived, NULL);
		if (retnCheck == SOCKET_ERROR || retnCheck == 0)
			return false;
		bytesReceived += retnCheck;
	}
	return true;
}

bool Client::SendAll(const char* _data, const int _totalBytes)
{
	int bytesSent = 0;
	while (bytesSent < _totalBytes)
	{
		int retnCheck = send(m_connection, _data + bytesSent, _totalBytes - bytesSent, NULL);
		if (retnCheck == SOCKET_ERROR)
			return false;
		bytesSent += retnCheck;
	}
	return true;
}

bool Client::GetInt32_t(std::int32_t& _int32_t)
{
	if (!GetAll((char*)&_int32_t, sizeof(std::int32_t)))
		return false;
	//-- Convert from network-byte-order to host-byte-order --\/
	_int32_t = ntohl(_int32_t); 
	return true;
}

bool Client::GetPacketType(PacketType &_packettype)
{
	int32_t packetType_int;
	if (!GetInt32_t(packetType_int))
		return false; 
	_packettype = (PacketType)packetType_int;
	return true;
}

void Client::SendString(const std::string& _string)
{
	PS::ChatMessage message(_string);
	m_pm.Append(message.toPacket());
}

bool Client::GetString(std::string& _string)
{
	int32_t bufferlength;
	if (!GetInt32_t(bufferlength))
		return false; 
	if (bufferlength == 0) return true;
	_string.resize(bufferlength); //resize string to fit message
	return GetAll(&_string[0], bufferlength);
}