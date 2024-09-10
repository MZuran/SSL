#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int indice;
    int token;
    char lexema[32];
}t_respuesta_scan;

t_respuesta_scan scan(char *input, int indice_inicial);

typedef enum {
    //INTERMEDIOS
    ESTADO_INICIAL,
    ESTADO_IDENTIFICADOR,
    ESTADO_CONSTANTE,
    ESTADO_ASIGNACION,
    LEXEMA_INVALIDO,
    //MISC
    ESPACIO,
    FDT,
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
} t_token;

typedef enum {
    C_LETRA,
    C_DIGITO,
    C_MAS,
    C_MENOS,
    C_POR,
    C_DIVISION,
    C_PORCENTAJE,
    C_DOS_PUNTOS,
    C_IGUAL,
    C_PARENTESIS_ABRE,
    C_PARENTESIS_CIERRA,
    C_COMA,
    C_PUNTO_COMA,
    C_ESPACIO,
    C_FDT,
    C_OTRO,
} t_caracter;

char *interpretar_estado(t_token estado);

#endif // SCANNER_H