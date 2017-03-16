/* Socket Programming with C
* ========================================
* [] File Name : SOCKET_CLIENT.c
*
* [] Creation Date : March 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

struct inAddress
{
	unsigned long socketAddress;
};

struct socketAddressIn
{
	short family;		//Address Family(AF_INET)
	unsigned short port;		//Port Number
	struct inAddress address;
	char zero[8];
};

int main(int argc,char* argv[])
{
	/* socket system call
	*  Address Familiy - AF_INET(IP Ver 4)
	*  Type - SOCK_STREAM(connection oriented TCP Protocol)
	*  Protocol - 0(IP Protocol)  
	*  return value: socket descriptor
	*/
	int socketDsc = socket(AF_INET,SOCK_STREAM,0);
	/* This is used as the data to be sent over the socket */
	char *message;
	char *server_response[2000];
	
	struct socketAddressIn server;
	if(socketDsc == -1)
		printf("Cannot create a socket.");
		
	server.address.socketAddress = inet_addr("216.58.211.110");
	server.family = AF_INET;
	server.port = htons(80);
	
	/* Client side connecton to the server: https://google.com */
	if(connect(socketDsc, (struct sockaddr *)&server, sizeof(server)) < 0)
		{
			puts("Connection Error");
			return 1;
		}
	puts("Connected");
	
	/* Sending data over the socket */
	message = "Hi, My name is hello world :D";
	if(send(socketDsc, message, strlen(message), 0) < 0)
		{
			puts("Sent Failed");
			return 1;
		}
	puts("Message Sent");
	
	/* Recieve data from the server */
	if(recv(socketDsc, server_response, 2000, 0) < 0)
		puts("recieve failed");
	puts("server responded: ");
	puts(server_response);
	
	close(socketDsc);
	
	return 0;
}


