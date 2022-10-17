#include <stdio.h>
#include <stdbool.h>

#include "client.h"
#include "server.h"


int main() {
    printf("*** Beez Node ***\n");
    printf("Server o Client?");

    char selection;

    /* ask user to choose color */
    printf("Please select the type: (c = client, s = server): ");
    scanf("%c", &selection);

    /* print out the result */
    switch (selection)
    {
    case 'c':
        printf("Client \n");
        char* message = "GET / HTTP/1.1\r\n\r\n";

        bool is_connected = init_client(message);

        printf("Funziona il client? %s\n", is_connected ? "si" : "no");

        break;
    case 's':
        printf("Server\n");

         // server
        // char* hostname = "stellab.it";
        // bool is_getting_ipaddr = get_hostname(hostname);

        bool is_server_working = init_server();

        printf("Funziona il server? %s\n", is_server_working ? "si" : "no");

        break;
    default:
        printf("you did not choose any type\n");
    }


    
   

}