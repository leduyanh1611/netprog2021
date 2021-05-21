06.practical.work.server.turn.c 
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
    }//if bind() < 0

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

    char dr[8386];
    /*memset(dr, 0, 8386);//memset(dr,0,sizeof(dr))
    fgets(dr, 8386, stdin);//read
    printf("Client dr: %s", dr);
    printf();
    write(sockfd, dr, strlen(dr));
    read(sockfd, dr, strlen(dr));
    printf("Server dr: %s", dr);
    printf();
    //server received and send*/

    char buf[333];
    send(clientfd, dr, sizeof(dr), 0);
    printf("Connect server");
    int  n = 0;

    while (fgets(buf, 333, stdin) != 0){ 
        if (scanf("%333[^\n]", buf) == 1) //scan everything put into buff until /n {
            printf("Found %s\n", buf);
        }//if
    }//while

    nr = read(clientfd, dr, sizeof(dr), 0);
    if (nr < 0){
        printf("Socket not read/n");
    }//if

    printf("Client: %s\n",buf);
    close(clientfd);
    close(sockfd);
    return 0;
}//main