#include <netdb.h>
#include <stdbool.h>
#include <stdio.h> // NULL
#include <netdb.h> //hostent
#include <string.h> // strcpy
#include <arpa/inet.h> // inet_ntoa
#include <sys/socket.h> // sockaddr_in
#include <unistd.h> // write

#include "server.h"


bool get_hostname(char *hostname) {

    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if( (he = gethostbyname(hostname)) == NULL ) {
        return false;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++) {
        // Ritorna il primo valore
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }

    printf("%s risolto in: %s\n", hostname, ip);

    return true;
}


bool init_server() {
    printf("Init the server\n");

    char* message;

    int my_socket, number_connections, nuovo_socket;
    struct sockaddr_in server, client;

    // crea il socket
    my_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (my_socket == -1) {
        return false;
    }

    // Prepara la struttura del sockadd_in
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    // Bind -> collega address a porta per il socket
    if ( bind(my_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return false;
    } else {
        puts("Bind riuscito");
    }

    // Metti in ascolto il socket
    listen(my_socket, 3);

    // Accetta connessioni in ingresso
    puts("Attesa connessioni in arrivo ...");
    number_connections = sizeof(struct sockaddr_in);

    nuovo_socket = accept(my_socket, (struct sockaddr *)&client, (socklen_t*)&number_connections);

    if (nuovo_socket < 0) {
        return false;
    }

    puts("Connessione accettata");

    // Scrivi nel socket la risposta del server al client
    message = "Connessione rivevuta ma ora devo andare, ciao\n";
    write(nuovo_socket, message, strlen(message));


    return true;
}