#include <stdio.h>
#include <winsock2.h>
#include<winsock.h>
#include<stdlib.h>
#include<WS2tcpip.h>
//�z��̏ꏊ�n��
int
main()
{
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	int x = 12345;
	char buf[32];

	// winsock2�̏�����
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	// �\�P�b�g�̍쐬
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// �ڑ���w��p�\���̂̏���
	inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(x);
	// �T�[�o�ɐڑ�
	connect(sock, (struct sockaddr *)&server, sizeof(server));

	// �T�[�o����f�[�^����M
	memset(buf, 0, sizeof(buf));
	int n = recv(sock, buf, sizeof(buf), 0);


	printf("%d, %s\n", n, buf);

	// winsock2�̏I������
	WSACleanup();
	system("pause");
	return 0;
}
