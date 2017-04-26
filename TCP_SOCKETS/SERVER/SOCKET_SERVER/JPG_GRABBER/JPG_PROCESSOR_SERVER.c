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

  /* Configure sockaddr_in */
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8890);

  /* Bind the socket to the port */
  if(bind(sockDsc,(struct * sockaddr)&server,sizeof(server)) < 0)
  {
    /* Binding failed */
    perror("Binding failed.");
    return 1;
  }
  printf("binding done.\n");

  /* Listen for connections */
  listen(socketDsc,3);
  /* Accept incoming connections */
  printf("Waiting for any connections...\n");
  if(newsocketDsc = accept(socketDsc,(struct * sockaddr)&client,(socklen_t *)&c))
  {
      /* Connection accepted */
      puts("Connection accepted");
  }

  return 0;
}
