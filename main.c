#include <stdio.h>
#include <stdbool.h>

#include "client.h"
#include "server.h"

int main() {
    printf("Ciao Beez Server\n");

    // client

    char* message = "GET / HTTP/1.1\r\n\r\n";

    bool is_connected = init_client(message);

    printf("Funziona il client? %s\n", is_connected ? "si" : "no");

    // server
    char* hostname = "stellab.it";

    bool is_getting_ipaddr = get_hostname(hostname);

    bool is_server_working = init_server();

     printf("Funziona il server? %s\n", is_server_working ? "si" : "no");

}