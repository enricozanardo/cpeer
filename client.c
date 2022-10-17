#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h> // sockaddr_in
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


#include "client.h"



bool init_client(char* message) {
    #define SERVER_ADD() ("78.46.177.239")

    int my_socket;
    struct sockaddr_in server;
    char server_reply[2000]; 

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

    // invia una richiesta di tipo GET al server
    if (send(my_socket, message, strlen(message), 0) < 0) {
        return false;
    } else {
         puts("Invio richesta GET al server..\n");
    }

   

    // ricevi la risposta dal server
    if (recv(my_socket, server_reply, 2000, 0) < 0) {
        return false;
    } else {
        puts("Risposta dal server \n");
        puts(server_reply);
        puts("\n");
    }

    #undef SERVER_ADD

    // chiudi il socket
    close(my_socket);

    return true;
}



