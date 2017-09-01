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
#include <unistd.h>
#include <string.h>

int main()
{
	int socketDsc, newSocketDsc, temp_size;
	struct sockaddr_in client, server;
	char *message = "Hi mr client. I just recieved your connection request";
	
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
	
	/* Bind the socket to a port */
	if(bind(socketDsc, (struct sockaddr*)&server, sizeof(server)) < 0)
		puts("bind failed");
	else
		puts("bind done");

	/* Listen for connections with backlog queue size = 5 */
	listen(socketDsc,5);
	
	/* Accept the incoming connections */
	puts("Waiting for incoming connections");
	newSocketDsc = accept(socketDsc, (struct sockaddr*)&client, (socklen_t*)&temp_size);
	if(newSocketDsc < 0)
		perror("Accepting failed...");
	else
		puts("Connection accepted...");
		
	/* Reply to the client */
	write(newSocketDsc,message,strlen(message));
	

return 0;
}

