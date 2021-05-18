« 05.practical.work.server.turn.c »
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

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
    }/if bind() < 0

    if (listen(sockfd, 5) < 0) {
        printf("No listen\n");
        exit(1);//Exit failure
    }//if listen() < 0

    clen=sizeof(caddr);
    acceptCreate=accept(server_family,(struct sockaddr*)&caddr,&clen);
    if (acceptCreate < 0) {
        printf("No accept connection\n");
        exit(1);//Exit failure
    }//if accept create < 0

    else{
    printf("Accept client. Congrat\n");
    }//else 
    return 1;

    char buffer[100];
    FILE *fp;
    read(connfd,buffer,100);
    fp=fopen("add1.txt","w");
    fprintf(fp,"%s",buffer);
    sleep(10);//wait 10s
    printf("the new file created is ' Vì cách mà em gọi anh, không có "u" và thiếu "y dài" (Ê) '"); //sry sir i'm just admire this punchline
}