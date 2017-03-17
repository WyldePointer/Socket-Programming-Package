/* Socket Programming with C
* ========================================
* [] File Name : SOCKET_SERVER.c
*
* [] Creation Date : March 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
	int socketDsc;
	struct sockaddr_in server;
	
	/* Create the socket server */
	socketDsc = socket(AF_INET, SOCK_STREAM, 0);
	if(socketDsc == -1)
	{
		printf("Cannot create the socket");
		return 1;
	}
	
	/* Configure the socket */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);
	
	
	
}

