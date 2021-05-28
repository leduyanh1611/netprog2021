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
	int n ,char buff[MAX];
	for (;;) {
		int bzero(buff, MAX);
		
        read(sockfd, buff, sizeof(buff));//read mess client to buffer
		printf("From client: %s\t To client : ", buff);
		bzero(buff, MAX);
		n = 0;
		
        while ((buff[n++] = getchar()) != '\n');//copy server mess 
		
        write(sockfd, buff, sizeof(buff));//send mess buff to client
		
        if (strncmp("/dc", buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}//If mess "exit" then server exit then disconnect chat
	}//infinity for loop chat
}//Func chat server and client

int main(int argc, char const *agrv[]){
    int sockfd;
    int clen;
    int clientfd;
    int acceptCreate;
    struct sockaddr_in saddr, caddr;
    unsigned short port = 8784;
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    //declaration
    
    if (sockfd < 0) {
      printf("No create socket\n");
      exit(1);
    }//if

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
        printf("No bind\n");
        exit(1);//Exit failure
    }//if bind() < 0

    if (listen(sockfd, 5) < 0) {
        printf("No listen\n");
        exit(1);//Exit failure
    }//if listen() < 0


    //create nonblocking
    clen=sizeof(caddr);
    acceptCreate=accept(server_family,(struct sockaddr*)&caddr,&clen);
    if (acceptCreate < 0) {
        printf("No accept connection\n");
        exit(1);//Exit failure
    }//if 
    else{
        printf("Accept client. Congrat\n");//Enable nonblocking for client
        int nonblocking_option = fcntl(accept_create, F_GETFL, 0);
        nonblocking_option |=O_NONBLOCK;
        fcntl(accept_create, F_SETFL, nonblocking_option); 
    }//else accept create < 0 -> nonblocking for client 
    return 1;

    printf("Client: %s\n",buf);
    close(clientfd);
    close(sockfd);
    return 0;
}//main