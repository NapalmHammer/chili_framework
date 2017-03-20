#pragma once
#include <fstream> //for std::ifstream and std::ofstream
#include "Packet.h" //for Packet
#include <memory> //for std::shared_ptr

struct FileTransferData
{
	static const int m_bufferSize = 16384;
	std::string m_fileName; 
	int m_bytesWritten;
	int m_fileOffset;
	std::streamoff m_fileSize;
	int m_remainingBytes;
	std::ifstream m_infileStream;
	std::ofstream m_outfileStream;
	bool m_transferInProgress = false;
	char m_buffer[m_bufferSize];
	bool Initialize(const std::string & fileName, std::string & errMsg);
	std::shared_ptr<Packet> getOutgoingBufferPacket(int& bytes, std::string& msg);
};