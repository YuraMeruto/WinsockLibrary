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
	sockaddr_in server,client,local;
	struct in_addr local_addr;
	SOCKET sendsocket,tcpsocket;
	DWORD dwSize;
	PHOSTENT localhostnet;//ローカルホスト
	LPADDRINFO lpAddrInfo;
	struct	hostent *hs;
	char localhostipadress[16];//自分のアドレス;
	char LocalHostName[256];//ホスト名
	struct addrinfo *hint,*res;
public:
	
	Winsock(int x,int y)
{
	WSAStartup(MAKEWORD(x,y),&wsadata);
}

void TCPServerConect(std::string ServerIPAdress ,int PortNumber)
{

	tcpsocket = socket(AF_INET,SOCK_STREAM,0);
	inet_pton(AF_INET,ServerIPAdress.c_str(),&server.sin_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(PortNumber);
	connect(tcpsocket,(sockaddr *)&server,sizeof(server));
}

void TCPRecv(int num,char *recvbuf)
{
	memset(recvbuf,0,sizeof(recvbuf));
	recv(tcpsocket,recvbuf,sizeof(recvbuf),0);
}

void GetMyIPAdress()
{

	IN_ADDR in;
	gethostname(LocalHostName,(int)sizeof(LocalHostName));
	
	gethostname(LocalHostName,sizeof(LocalHostName));
	 getaddrinfo(LocalHostName, NULL , hint, &res);
	dwSize = sizeof(LocalHostName);
	std::cout << LocalHostName << std::endl;
	///strcpy(localhostipadress,inet_ntoa(in));
	//inet_ntop(AF_INET, (PVOID)in.S_un.S_addr, localhostipadress, sizeof(localhostipadress));

}



};