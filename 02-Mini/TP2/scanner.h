#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

void scan(char *input, size_t len);

/// @brief 
typedef enum {
    ESTADO_INICIAL,
    IDENTIFICADOR,
    CONSTANTE,
    OPERADOR_SUMA,
    OPERADOR_RESTA,
    OPERADOR_PRODUCTO,
    OPERADOR_DIVISOR,
    OPERADOR_PORCENTAJE,
    ERROR_ASIGNACION,
    ASIGNACION,
    PARENTESIS_ABRIR,
    PARENTESIS_CERRAR,
    COMA,
    PUNTO_COMA,
    END_OF_FILE,
    ERROR,
    ERROR_IDENTIFICADOR,
    ERROR_CONSTANTE,

    FDT
} t_token;

#endif // SCANNER_H