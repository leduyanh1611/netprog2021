06.practical.work.client.turn.c  
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>


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
    }//else connectServer >= 0

    char dr[8386];
    /*memset(dr,0, 8386);//memset(dr,0,sizeof(dr))
    fgets(dr,8386,stdin);//read
    printf("Client dr: %s", dr);
    printf();
    write(sockfd, dr, strlen(dr));
    read(sockfd, dr, strlen(dr));
    printf("Server dr: %s", dr);
    printf();
    //client received and send*/

    char buf[333];
    printf("Enter dr: ");
    bzero(buf,333);//bzero (&saddr, sizeof(saddr))
    fgets(buf,333,stdin);//read
    int write(sockfd, buf, strlen(buf)) = 0;            
    write(sockfd, buf, strlen(buf)) = nw;//n=0
    while (fgets(buf, 333, stdin) != 0){ 
        if (scanf("%333[^\n]", buf) == 1) //scan everything put into buff until /n {
            printf("Found %s\n", buf);
        }//if
    }//while

    if (nw < 0) {
        printf("Socket not written");
    }//if write(sockfd, buf, strlen(buf)) < 0

    bzero(buf,333);//
    nr = read(sockfd, buf, 333);
    if (nr < 0) {
        printf("Socket not read");
    }//if read(sockfd, buf, 333) < 0

    printf("%s\n", buf);
    close(sockfd);
    return 0;
}//main
