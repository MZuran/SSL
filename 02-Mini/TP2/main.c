#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

int main() {

    char *input = NULL; // Puntero para almacenar la dirección de la memoria del buffer
    size_t len = 0;     // Inicializa el tamaño del buffer a 0
    size_t read;

    t_respuesta_scan respuesta;
    respuesta.token = ESTADO_INICIAL;

    while (respuesta.token != FDT)
    {
        printf("Introduzca una cadena de caracteres: ");
        read = getline(&input, &len, stdin);
        int size = (int)read;
        int indice = 0;

        if (read != -1) {
            if (input[read - 1] == '\n')
            { input[read - 1] = '\0'; }
            else
            { return 1; }
        }

        //Termino de leer

        while (indice <= size) {
            
            t_respuesta_scan nueva_respuesta;
            respuesta = nueva_respuesta;

            //printf("Hice un scan y este es mi indice %d \n", indice);
            respuesta = scan(input, indice);
            indice = respuesta.indice;

            if(respuesta.lexema[0] == ' ' || respuesta.lexema[0] == '\0'){
                //printf("TRATE DE HACER UN BREAK");
                continue;
            }

            printf("%s '%s' \n", interpretar_estado(respuesta.token) , respuesta.lexema);
        }

        //printf("Este es el lexema de la respuesta %s \n", respuesta.lexema);
    }


    return 0;
}