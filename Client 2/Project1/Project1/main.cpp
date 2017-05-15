#include <stdio.h>
#include <winsock2.h>
#include<winsock.h>
#include<stdlib.h>
#include<WS2tcpip.h>
#include"Test.h"
//配列の場所渡し
int
main()
{
	Winsock win =  Winsock(2,0);
	win.GetMyIPAdress();
	system("pause");
	/*
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	int x = 12345;
	char buf[32];

	// winsock2の初期化
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	// ソケットの作成
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// 接続先指定用構造体の準備
	inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(x);
	// サーバに接続
	connect(sock, (struct sockaddr *)&server, sizeof(server));

	// サーバからデータを受信
	memset(buf, 0, sizeof(buf));
	int n = recv(sock, buf, sizeof(buf),0);

	printf("%d, %s\n", n, buf);

	// winsock2の終了処理
	WSACleanup();
	system("pause");
	return 0;
	*/
}
