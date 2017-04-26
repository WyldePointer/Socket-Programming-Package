/* Socket Programming with C
* ========================================
* [] File Name : JPG_PROCESSOR_SERVER.c
*
* [] Creation Date : APRIL 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
/* Exclusive Headers */
/* Needed for file reading purposes */
#include <fstream.h>
#include <iostream.h>

int main()
{
  /* Needed for socket connections */
  int sockDsc;
  /* Needed for client and server entities */
  struct sockaddr_in client, server;

  /* Create a socket */
  socketDsc = socket(AF_INET, SOCK_STREAM, 0);
  if(socketDsc < 0)
  {
    /* Socket creation failed */
    perror("Socket creation failed.");
    return 1;
  }
  


  return 0;
}
