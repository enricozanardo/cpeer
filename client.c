#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#include "client.h"



bool init_socket() {
    #define SERVER_ADD() ("78.46.177.239")

    int my_socket;
    struct sockaddr_in server;

    // crea il socket
    my_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (my_socket == -1 ) {
        return false;
    }

    // crea la connessione 
    server.sin_addr.s_addr = inet_addr(SERVER_ADD());
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    // conneti il socket al server remoto
    if (connect(my_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return false;
    }

    #undef SERVER_ADD    
    return true;
}



