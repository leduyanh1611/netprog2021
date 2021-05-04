#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    struct hostent *n;

    if (argc < 2) {
        char a[200];//a is hostname
        printf("Enter hostname: ");
        scanf("%s",a);
        n = gethostbyname(a);
    }//if argc < 2 -> Enter a
    else{
        n = gethostbyname(argv[1]);
    }//else argc >= 2 -> n = gethostbyname at argv i = 1
    if (n == NULL) {
       printf("No gethostbyname()\n");
    } //if n is NULL
    else {
         printf("IP address has been resolved %s:\n", n->h_name);
         unsigned int index = 0;
         while ( n -> h_addr_list[index] != NULL) {
             printf( "\t-%s\n ", inet_ntoa( *( struct in_addr*)( n -> h_addr_list[index])));
              index ++;
     	 }//while (n NOT NULL)
         printf("\tEnd!\n");
    }//else

}//main
