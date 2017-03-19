/* Socket Programming with C
* ========================================
* [] File Name : MULTIPLE_SOCKETS_HANDLING.c
*
* [] Creation Date : March 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>		// write()
#include <string.h>		// strlen()

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
	
	/* Bind the socket to a port */
	if(bind(socketDsc, (struct sockaddr*)&server, sizeof(server)) < 0)
		puts("bind failed");
	else
		puts("bind done");

	/* Listen for connections with backlog queue size = 5 */
	listen(socketDsc,5);
	
	/* Accept the incoming connections */
	puts("Waiting for incoming connections");
	int newSocketDsc;
	int temp_size;
	struct sockaddr_in client;
	while((newSocketDsc = accept(socketDsc, (struct sockaddr*)&client, (socklen_t*)&temp_size)))
	{
		puts("Connection Accepted");
		/* Reply to the client */
		char *message;
		message = "Hi mr client. I just recieved your connection request";
		write(newSocketDsc,message,strlen(message));
	}
	
	if(newSocketDsc < 0)
	{
		perror("Accepting failed...");
		return 1;
	}
	
			
return 0;
}
