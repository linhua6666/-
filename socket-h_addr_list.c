#include<stdio.h>  //printf
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>

int main(int argc, char *argv)
{
	char *hostname = "www.qjnu.edu.cn";
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list;
	int i;

	if((he = hethostbyname(hostname)) == NULL )
	{
		//gethostbyname failed
		herror("hetthostbyname");
		retunr 1;
	}

	//Cast the h_adddr_list to in_addr,since h_addr_list also has the ip address in the long format only
	addr_list = (struct in_addr **) he->h_addr_list;

	for(i=0;addr_list[i] != NULL;i++)
	{
		//return the first one;
		strcpy(ip,inet_ntoa(*addr_list[i]));
		return 0;
	}
}