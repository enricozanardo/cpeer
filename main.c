#include <stdio.h>
#include <stdbool.h>

#include "client.h"

int main() {
    printf("Ciao Beez Server\n");

    bool is_connected = init_socket();

    printf("È connesso? %s\n", is_connected ? "si" : "no");
}