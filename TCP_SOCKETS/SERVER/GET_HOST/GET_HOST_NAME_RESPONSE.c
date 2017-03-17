/* Socket Programming with C
* ========================================
* [] File Name : GET_HOST_NAME_RESPONSE.c
*
* [] Creation Date : March 2017
*
* [] Created By : Ali Gholami (aligholami7596@gmail.com)
* ========================================
*/

#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char *host_name = "www.google.com";
	char ip[100];
	
	/* Function gethostbyname gets a parameter as host name and returns
	 * an struct which is called hostent.
	 * hostnet provides the ip information and it's in the netdb.h file
	 * here is an overall look at the hostent struct:
	 * struct hostent {
	 * char *h_name;  (The official host name)
	 * char **h_aliases (The list of host aliases)
	 * int h_addrtype;	(The host address type)
	 * int h_length;	(The host address length)
	 * char **h_addr_list; (List of addresses from that server)
	 * } */
	 
	 /* ip information */ 
	 struct hostent *he;
	 
	 /* struct in_addr{
	  * unsigned long s_addr;
	  * } */
	 
	 /* Address list result will be copied here */
	 struct in_addr **address_list;
	 /* A simple counter */
	 int i = 0;
	 
	 if ((he = gethostbyname(host_name)) == NULL)
		{
			/* gethostbyname has been failed */
			herror("gethostbyname");
			return 1;
		}
	
	/* Cast long ing h_addr_list to unsigned long in in_addr */
	address_list = (struct in_addr **)he->h_addr_list;
	 
	 for (i = 0; address_list[i] != NULL; i++)
	 {
		 /* Copy the first address in that list to the ip */
		 /* the function inet_ntoa will convert the ip in long
		  * format to the dotted format.
		  * */
		 strcpy(ip, inet_ntoa(*address_list[i]));
	 }
	 
	 printf("%s resolved to %s", host_name, ip);
	 return 0;
	 
	 
}
