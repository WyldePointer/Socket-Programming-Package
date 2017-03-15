/*Socket Programming with C
* ========================================
* [] File Name : TCP_SOCKET_PROGRAMMING.c
*
* [] Creation Date : March 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/

#include <stdio.h>
#include <sys/socket.h>

int main(int argc,char argv*[])
{
	/* socket system call
	*  Address Familiy - AF_INET(IP Ver 4)
	*  Type - SOCK_STREAM(connection oriented TCP Protocol)
	*  Protocol - 0(IP Protocol)  
	*  return value: socket descriptor
	*/
	int socketDsc = socket(AF_INET,SOCK_STREAM,0);
}


