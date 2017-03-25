/* Socket Programming with C
* ========================================
* [] File Name : TCP_CLIENT.c
*
* [] Creation Date : March 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

int main()
{
	/* Define variables */
	struct sockaddr_in addr,client_addr;
	int sockDsc,ret;
	char buffer[BUF_SIZE];
	char *serverAddr;
	pthread_t thread;
	
	/* create the client socket */
	sockDsc = socket(AF_INET,SOCK_STREAM,0);
	if(sockDsc < 0)
	{
		perror("Error occured while creating the socket");
		return 1;
	}
	printf("Socket created");
	
	/* Configure the socket */
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(serverAddr);
	addr.sin_port = PORT;
	
	/* Connect the socket to the server */
	ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));  
	if (ret < 0)
	{  
		perror("Error connecting to the server!");  
		exit(1);  
	}  
	printf("Connected to the server...\n");
	
	/* recieving the messages to the server */
	memset(buffer,0,BUF_SIZE);
	printf("Enter your message and press enter");
	/* Create a new thread to grab the messages from the server */
	ret = pthread_create(&thread,NULL,receiveMessage,(void*)sockDsc);
	if(ret)
	{
		printf("ERROR: Return code from pthread_create() is %d\n",ret);
		return 1;
	}
	
	
	
	
	
}
