#pragma once
#include "PacketType.h"
#include "Packet.h"
#include "FileTransferData.h" //for FileTransferData::buffersize
#include <string> //for std::string
#include <memory> //for std::shared_ptr

namespace PS
{
	class ChatMessage
	{
	public:
		ChatMessage(const std::string & str);
		std::shared_ptr<Packet> toPacket();
	private:
		std::string m_message;
	};

	class FileDataBuffer
	{
	public:
		std::shared_ptr<Packet> toPacket();
		char m_dataBuffer[FileTransferData::m_bufferSize];
		int m_size;
	};
}