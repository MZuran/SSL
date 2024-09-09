#include "scanner.h"

bool debo_parar(t_token estado) {
    switch (estado) {
    case ERROR_GENERAL:
        return true;

    default:
        return false;
    }
}

bool centinela(t_token estado) {
    switch (estado) {
    case ERROR_GENERAL:
        return true;

    default:
        return false;
    }
}

bool es_letra(char i) {
    return (i >= 'a' && i <= 'z');
}

bool es_digito(char c) {
    return (c >= '0' && c <= '9');
}

void scan(char *input, size_t len) {
    for (int i = 0; input[i] != '\0'; i++) {
        printf("Caracter en la posición %d: %c\n", i, input[i]);
    }
}