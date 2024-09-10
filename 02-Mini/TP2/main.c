#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

int main() {

    char *input = NULL; // Puntero para almacenar la dirección de la memoria del buffer
    size_t len = 0;     // Inicializa el tamaño del buffer a 0
    size_t read;

    printf("Introduzca una cadena de caracteres: ");
    read = getline(&input, &len, stdin);

    if (read != -1) {
        if (input[read - 1] == '\n')
        { input[read - 1] = '\0'; }
        else
        { return 1; }
    }

    t_respuesta_scan respuesta = scan(input, 0);
    printf("Este es el lexema de la respuesta %s \n", respuesta.lexema);

    return 0;
}