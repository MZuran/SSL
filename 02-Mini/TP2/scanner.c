#include "scanner.h"

bool debo_parar(t_token estado) {
    switch (estado) {
    case ERROR:
        return true;

    default:
        return false;
    }
}

bool centinela(t_token estado) {
    switch (estado) {
    case ERROR:
        return true;

    default:
        return false;
    }
}

void scan(char *input, size_t len) {
    for (int i = 0; input[i] != '\0'; i++) {
        printf("Caracter en la posición %d: %c\n", i, input[i]);
    }
}