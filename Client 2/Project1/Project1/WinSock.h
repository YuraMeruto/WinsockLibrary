#pragma once
#include<string>
#include <stdio.h>
#include <winsock2.h>
#include<stdlib.h>
#include<WS2tcpip.h>
#include<tchar.h>
#include<iostream>
#define LOCAL_HOST_NAME 50
class Winsock
{
private:
	WSADATA wsadata;
	sockaddr_in server, client, local;
	struct in_addr local_addr;
	SOCKET sendsocket, tcpsocket,Instancesock;
	DWORD dwSize;
	PHOSTENT localhostnet;//���[�J���z�X�g
	struct	hostent *hs;
	char localhostipadress[16];//�����̃A�h���X;
	char LocalHostName[256];
	struct sockaddr *sa;
	struct addrinfo hint, *res;
	char RecvBuf[1000];
public:

	Winsock(int x, int y)
	{
		WSAStartup(MAKEWORD(x, y), &wsadata);
	}

	void TCPServerConect(std::string ServerIPAdress, int PortNumber)
	{
		tcpsocket = socket(AF_INET, SOCK_STREAM, 0);
		inet_pton(AF_INET, ServerIPAdress.c_str(), &server.sin_addr);
		server.sin_family = AF_INET;
		server.sin_port = htons(PortNumber);
		connect(tcpsocket, (sockaddr *)&server, sizeof(server));
	}
	void TCPFromServerRecv()
	{
		memset(RecvBuf, 0, sizeof(RecvBuf));
		recv(tcpsocket, RecvBuf, sizeof(RecvBuf), 0);
	}

	void GetMyIPAdress()
	{
		/*
		IN_ADDR in;
		socklen_t salen = NULL;
		gethostname(LocalHostName, sizeof(LocalHostName));
		getaddrinfo(LocalHostName, NULL, &hint, &res);
		dwSize = sizeof(LocalHostName);
		std::cout << res->ai_addr << std::endl;
		std::cout << res << std::endl;
		getnameinfo((sockaddr FAR *)&local, salen, localhostipadress, dwSize, localhostipadress, dwSize, 0);
		*/
	}

	void TCPInstanceSocet()
	{
		Instancesock = socket(AF_INET,SOCK_STREAM,0);	
	}
	void PrintRecv()
	{
		std::cout << RecvBuf << std::endl;
	}
};