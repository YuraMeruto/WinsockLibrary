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
	PHOSTENT localhostnet;//ローカルホスト
	struct	hostent *hs;
	char localhostipadress[16];//自分のアドレス;
	char LocalHostName[256];
	struct sockaddr *sa;
	struct addrinfo hint, *res;
	char RecvBuf[1000];
public:
	int portnumber = 12345;
public:

	Winsock(int x, int y)
	{
		WSAStartup(MAKEWORD(x, y), &wsadata);
	}
	void TCPInstanceSocet()
	{
		Instancesock = socket(AF_INET, SOCK_STREAM, 0);
	}
	void TCPBindSock()
	{
		bind(Instancesock, (struct sockaddr *)&local_addr, sizeof(local_addr));
	}
	void TCPServerConect(std::string ServerIPAdress)
	{
		inet_pton(AF_INET, ServerIPAdress.c_str(), &server.sin_addr);
		server.sin_family = AF_INET;
		server.sin_port = htons(portnumber);
		connect(Instancesock, (sockaddr *)&server, sizeof(server));
	}
	void TCPFromServerRecv()
	{
		memset(RecvBuf, 0, sizeof(RecvBuf));
		recv(Instancesock, RecvBuf, sizeof(RecvBuf), 0);
	}

	void TCPSendSocekt(std::string sendstring)
	{
		send(Instancesock,sendstring.c_str(),sizeof(sendstring),0);
	}

	void SocketDestroy()
	{
		delete this;
	}

	void PrintRecv()
	{
		std::cout << RecvBuf << std::endl;
	}

};