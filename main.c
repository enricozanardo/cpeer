#include <stdio.h>
#include <stdbool.h>

#include "client.h"

int main() {
    printf("Ciao Beez Server\n");

    char* message = "GET / HTTP/1.1\r\n\r\n";

    bool is_connected = init_socket(message);

    printf("È connesso? %s\n", is_connected ? "si" : "no");
}