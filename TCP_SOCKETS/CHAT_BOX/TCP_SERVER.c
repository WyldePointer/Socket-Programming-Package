/* Socket Programming with C
* ========================================
* [] File Name : TCP_SERVER.c
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
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>


#define PORT 4444
#define BUF_SIZE 2000
#define CLADDR_LEN 100

/* pthread connection handler */
void * recieveMessage(void *);

int main()
{
	/* Define variables */
	int sockDsc, newsockDsc;
	int *newSock;
	int bindRet,len, pthreadRet;		// len is client address size 
	struct sockaddr_in addr, client_addr;
	char buffer[BUF_SIZE];
	char clientAddr[CLADDR_LEN];
	pthread_t thread;
	
	/* Create the socket */
	sockDsc = socket(AF_INET, SOCK_STREAM, 0);
	if(sockDsc < 0)
	{
		perror("Error creating the socket");
		return 1;
	}
	printf("Socket created successfully");
	
	/* Set the properties */
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = PORT;
	
	/* Bind the server to the addr */
	bindRet = bind(sockDsc,(struct sockaddr*)&addr,sizeof(addr));
	if (bindRet < 0)
	{
		perror("Binding failed!");
		return 1;
	}
	printf("binding done");
	
	/* Listen to new connections */
	printf("\nWaiting for a new connection...\n");
	listen(sockDsc,5);
	
	
	/* Accept new connections */
	len = sizeof(client_addr);
	newsockDsc = accept(sockDsc,(struct sockaddr *)&client_addr,(socklen_t*)&len);
	if (newsockDsc < 0)
	{
		perror("Error accepting the connection");
		return 1;
	}
	
	/* Convert IP from long to string in internet standard format */
	inet_ntop(AF_INET, &(client_addr.sin_addr), clientAddr, CLADDR_LEN);
	printf("Connection accepted from %s...\n", clientAddr); 
	
	
	/* Recieve messages */
	memset(buffer, 0, BUF_SIZE);
	printf("Enter your messages one by one and hit enter");
	/* Create a thread to grab the messages from the client */
	
	/* Removes warnings */
	newSock = malloc(1);
	*newSock = newsockDsc;
	pthreadRet = pthread_create(&thread,NULL,recieveMessage,(void *)newSock);
	/* Handle errors */
	if(pthreadRet < 0)
	{
		printf("ERROR: return code form pthread_create() is  %d\n",pthreadRet);
		return 1;
	}
	
	close(newsockDsc);
	close(sockDsc);
	pthread_exit(NULL);
	return 0;

}

void * recieveMessage(void * socket)
{
	/* Variables and Conversions */
	int sockDsc, ret;
	char buffer[BUF_SIZE];
	sockDsc = *(int *)socket;
	memset(buffer,0,BUF_SIZE);
	
	/* Recieve messages from client in the thread */
	for(;;)
	{
		ret = recvfrom(sockDsc,buffer,BUF_SIZE,0,NULL,NULL);
		if(ret < 0)
			printf("Error recieving data!\n");
		else
		{
			printf("client: ");
			fputs(buffer,stdout);
			printf("\n");
		}
	}
}


	
