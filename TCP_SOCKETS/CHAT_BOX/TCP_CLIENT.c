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
	
	
	
}
