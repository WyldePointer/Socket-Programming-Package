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
#include <stdib.h>

#define PORT 4444
#define BUF_SIZE 2000
#define CLADDR_LEN 100


int main()
{
	/* Define variables */
	int sockDsc, newsockDsc;
	int bindRet,len, pthreadRet;		// len is client address size 
	struct sockaddr_in addr, client_addr;
	char buffer[BUF_SIZE];
	pid_t childpid;
	char clientAddr[CL_ADDR_LEN];
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
	newsockDsc = accept(sockDsc,(struct sockaddr *)&client_addr,&len);
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
	pthreadRet = pthread_create(&thread,NULL,recieveMessage,(void *)newsockDsc);
	/* Handle errors */
	if(pthreadRet < 0)
	{
		printf("ERROR: return code form pthread_create() is  %d\n",pthreadRet);
		return 1;
	}
	
	

}

	
