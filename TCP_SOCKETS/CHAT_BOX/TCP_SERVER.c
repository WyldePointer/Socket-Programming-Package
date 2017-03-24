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




int main()
{
	/* Define variables */
	int sockDsc, newsockDsc;
	int bindRet,len;
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
	
	
	


}

	
