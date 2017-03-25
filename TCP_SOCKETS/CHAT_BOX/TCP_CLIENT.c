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

#define PORT 4444 
#define BUF_SIZE 2000

void * receiveMessage(void *);

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
	ret = connect(sockDsc, (struct sockaddr *) &addr, sizeof(addr));  
	if (ret < 0)
	{  
		perror("Error connecting to the server!");  
		exit(1);  
	}  
	printf("Connected to the server...\n");
	
	/* recieving the messages from the server */
	memset(buffer,0,BUF_SIZE);
	printf("Enter your message and press enter");
	/* Create a new thread to grab the messages from the server */
	ret = pthread_create(&thread,NULL,receiveMessage,(void*)sockDsc);
	if(ret)
	{
		printf("ERROR: Return code from pthread_create() is %d\n",ret);
		return 1;
	}
	
	/* While user is sending messages to the server,
	 * send them to the server! */
	 while(fgets(buffer,BUF_SIZE,stdin) != NULL)
	 {
		 ret = sendto(sockDsc,buffer,BUF_SIZE,0,(struct sockaddr *)&addr,sizeof(addr));
		 if(ret < 0)
		 {
			 printf("Error sending the data!\n\t-%s",buffer);
		 }
	 }
	 
	 /* wrap-up everything */
	 close(sockDsc);
	 pthread_exit(NULL);
	 return 0;
}
 
void *receiveMessage(void * socket)
{
	int sockDsc,ret;
	char buffer[BUF_SIZE];
	sockDsc = *(int *)socket;
	memset(buffer,0,BUF_SIZE);
	
}
