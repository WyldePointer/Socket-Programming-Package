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
#include <pthread.h>	// multithreading
#include <stdlib.h>		// free()

/* Connection handler */
void *connection_handler(void *);

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
	/* will be used on pthread_create calling */
	int *new_sock;
	while((newSocketDsc = accept(socketDsc, (struct sockaddr*)&client, (socklen_t*)&temp_size)))
	{
		puts("Connection Accepted");
		/* Reply to the client */
		char *message;
		message = "Hi mr client. I just recieved your connection request";
		write(newSocketDsc,message,strlen(message));
		
		/* Create a new thread for that new socket (client) */
		pthread response_thread;
		new_sock = malloc(1);
		*new_sock = newSocketDsc;
		
		if(pthread_create(&response_thread,NULL,connection_handler,(void*)new_sock) < 0)
		{
			perror("Could not create the thread");
			return 1;
		}
		
		/* join the thread , so that we dont terminate before the thread */
		pthread_join(response_thread,NULL);
		puts("Handler assigned");
		
	}
	
	if(newSocketDsc < 0)
	{
		perror("Accepting failed...");
		return 1;
	}
	
			
return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socketDsc)
{
    //Get the socket descriptor
    int sock = *(int*)socketDsc;
     
    char *message;
     
    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    write(sock , message , strlen(message));
     
    message = "Its my duty to communicate with you";
    write(sock , message , strlen(message));
     
    //Free the socket pointer
    free(socketDsc);
     
    return 0;
}

