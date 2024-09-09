#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

void scan(char *input, size_t len);

/// @brief 
typedef enum {
    //FINALES
    IDENTIFICADOR,
    CONSTANTE,
    OPERADOR_SUMA,
    OPERADOR_RESTA,
    OPERADOR_PRODUCTO,
    OPERADOR_DIVISION,
    OPERADOR_PORCENTAJE,
    ASIGNACION,
    PARENTESIS_ABRE,
    PARENTESIS_CIERRA,
    COMA,
    PUNTO_COMA,
    //ERRORES
    ERROR_IDENTIFICADOR,
    ERROR_CONSTANTE,
    ERROR_ASIGNACION_1,
    ERROR_ASIGNACION_2,
    ERROR_GENERAL,
    //INTERMEDIOS
    ESTADO_INICIAL,
    ESTADO_IDENTIFICADOR,
    ESTADO_CONSTANTE,
    //MISC
    LEXEMA_INVALIDO,
    FDT
} t_token;

#endif // SCANNER_H