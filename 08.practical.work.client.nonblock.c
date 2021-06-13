#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
#define PORT 8784
#define MAX 100


void func(int sockfd)
{
	int n = 0, char buff[MAX];
	for (;;) {
		int bzero(buff, sizeof(buff));

		printf("Enter str : ");

		while ((buff[n++] = getchar()) != '\n');//copy client mess 

		write(sockfd, buff, sizeof(buff));//send mess buff to client

		bzero(buff, sizeof(buff));
		read(sockfd, buff, sizeof(buff));//read mess client to buffer

		printf("From Server : %s", buff);
		
        if ((strncmp(buff, "/quit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}//If mess "/quit" then server exit then quit chat
	}//infinity for loop chat
}//Func chat server and client

int main(int argc, char const *agrv[]){
    struct hostent *host;
    if (argc < 2) {
        char hostName[2000];
        printf("Enter the hostname: ");
        scanf("%s",hostName);
        host = gethostbyname(hostName);
    }//if argc < 2 -> enter hostname
    else {
        host = gethostbyname(agrv[1]);
    }//else argc >= 2

    if (host == NULL) {
       printf("No gethostbyname()\n");
    }// if host !null
    else {
       printf("Resolved IP address of %s:\n", host->h_name);
       unsigned int i=0;
       while ( host -> h_addr_list[i] != NULL) {
          printf( "\t-%s\n ", inet_ntoa( *( struct in_addr*)( host -> h_addr_list[i])));
          i++;
       }//while host != null
    printf("\n");
    }//else

    int sockfd;
    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) <0){
        printf("No create socket\n");
        exit(1);//Exit failure
    }//if sockfd < 0
    //Client for socket 
    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char *) &saddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    saddr.sin_port = htons(8784);

    int connectSever=connect(sockfd,(struct sockaddr *)&addr,sizeof(addr));//declare assign values connectServer
    if (connectServer < 0) {
        printf("No connect\n");
        perror("Connected\n");
    }//if connectServer < 0
    else{
        printf("Success connect to server");
        setsockopt(sockfd, SOL_SOCKET , SO_REUSEADDR , &(int){1}, sizeof(int));
        fcntl(sockfd,F_GETFL,O_NONBLOCK);//nonblocking
    }//else connectServer >= 0
}//main


 