#pragma once
#include<string>
#include <stdio.h>
#include <winsock2.h>
#include<winsock.h>
#include<stdlib.h>
#include<WS2tcpip.h>

class Acsess
{
private:
	WSADATA wsadata;
	sockaddr_in server,client;
	SOCKET sendsocket,tcpsocket;

public:
Acsess(int x,int y)
{
	WSAStartup(MAKEWORD(x,y),&wsadata);
}

void TCPServerConect(std::string ServerIPAdress ,int PortNumber)
{
	tcpsocket = socket(AF_INET,SOCK_STREAM,0);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(PortNumber);
	connect(tcpsocket,(sockaddr *)&server,sizeof(server));
}
};