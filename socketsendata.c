#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message;

    //create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1)
    {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("10.1.8.65");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    //connect to remote server
    if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0 )
    {
        puts("connect error");
        return 1;
    }
    puts("connected\n");

    //send some data
    message = "GET /HTTP/1.1\r\nHost:www.qjnu.edu.cn\r\nconnection:close\r\n\r\n";
    if(send(socket_desc, message, strlen(message) , 0) < 0 )
    {
        puts("send failed");
        return 1;
    }
    puts("data send\n");

    return 0;
}