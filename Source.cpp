#include<iostream>
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")//winsock libary
#include<windows.h>
#include<stdlib.h>
#include<thread>
#include<chrono>
#include<cstdlib>
#include<windows.h>
#include<gdiplus.h>
#include<WinUser.h>
#include <tchar.h>

using namespace std;
int main()
{
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequired = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequired, &wsaData);//startup
	if (wsaerr != 0)
	{
		cout << "ddl not loading itz dum" << wsaData.szSystemStatus << endl;
	}
	else
	{
		cout << "ddl loaded" << endl;
	}
	SOCKET boi = INVALID_SOCKET;//the socket
	boi = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//create socket
	if (boi == INVALID_SOCKET)
	{
		cout << "socket not created monke" << endl;
	}
	else
	{
		cout << "socket created" << endl;
	}
	sockaddr_in kono;//ip info
	kono.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &kono.sin_addr.s_addr);
	kono.sin_port = htons(3948);
	connect(boi, (struct sockaddr*)&kono,sizeof(kono));
	char buffer[1024];
	while (true)
	{
		recv(boi, buffer, sizeof(buffer), 0);
		cout << buffer << endl;
	}
	WSACleanup();
}