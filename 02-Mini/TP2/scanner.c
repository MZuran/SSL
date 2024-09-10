#include "scanner.h"
#include "tabla.h"

bool debo_parar(t_token estado) {
    return (estado > 4);
}

bool es_centinela(t_token estado) {
    switch (estado) {
    case ERROR_GENERAL:
    case ERROR_IDENTIFICADOR:
    case ERROR_CONSTANTE:
    case ERROR_ASIGNACION_1:
    case CONSTANTE:
    case IDENTIFICADOR:
        return true;

    default:
        return false;
    }
}

bool es_letra(char i) {
    return (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z');
}


bool es_digito(char c) {
    return (c >= '0' && c <= '9');
}

bool es_aceptor(t_token estado) {
    return (estado >= 5 && estado <= 18);
}

t_caracter interpretar_caracter(char c) {
    if (es_letra(c)) { return C_LETRA; };
    if (es_digito(c)) { return C_DIGITO; };

    switch (c) {
    case '+':
        return C_MAS;
    case '-':
        return C_MENOS;
    case ':':
        return C_DOS_PUNTOS;
    case '=':
        return C_IGUAL;
    case '*':
        return C_POR;
    case '/':
        return C_DIVISION;
    case '%':
        return C_PORCENTAJE;
    case '(':
        return C_PARENTESIS_ABRE;
    case ')': 
        return C_PARENTESIS_CIERRA;
    case ',':
        return C_COMA;
    case ';':
        return C_PUNTO_COMA;
    case '\0':
        return C_FDT;
    case ' ':
    case '_':
    case '\n':
    case '\t':
        return C_ESPACIO;
    default:
        break;
    }
    return C_OTRO;
}

char *interpretar_estado(t_token estado) {
    switch (estado)
    {
    // INTERMEDIOS
    case ESTADO_INICIAL:
        return "Estado Inicial";
    case ESTADO_IDENTIFICADOR:
        return "Estado Intermedio Identificador";
    case ESTADO_CONSTANTE:
        return "Estado Intermedio Constante";
    case ESTADO_ASIGNACION:
        return "Estado Intermedio Asignación";
    case LEXEMA_INVALIDO:
        return "Lexema Inválido";

    // MISC
    case ESPACIO:
        return "Espacio";
    case FDT:
        return "Fin de Texto";

    // FINALES
    case IDENTIFICADOR:
        return "Identificador";
    case CONSTANTE:
        return "Constante";
    case OPERADOR_SUMA:
        return "Operador Suma";
    case OPERADOR_RESTA:
        return "Operador Resta";
    case OPERADOR_PRODUCTO:
        return "Operador Producto";
    case OPERADOR_DIVISION:
        return "Operador División";
    case OPERADOR_PORCENTAJE:
        return "Operador Porcentaje";
    case ASIGNACION:
        return "Asignación";
    case PARENTESIS_ABRE:
        return "Paréntesis Abre";
    case PARENTESIS_CIERRA:
        return "Paréntesis Cierra";
    case COMA:
        return "Coma";
    case PUNTO_COMA:
        return "Punto y Coma";

    // ERRORES
    case ERROR_IDENTIFICADOR:
        return "Error Identificador";
    case ERROR_CONSTANTE:
        return "Error Constante";
    case ERROR_ASIGNACION_1:
        return "Error Asignación por dos puntos solo";
    case ERROR_ASIGNACION_2:
        return "Error Asignación por igual solo";
    case ERROR_GENERAL:
        return "Error General";

    default:
        return "Estado Desconocido";
    }
}


t_respuesta_scan scan(char *input, int indice_inicial) {
    int estado = ESTADO_INICIAL;
    int indice_caracter = indice_inicial;

    t_respuesta_scan respuesta = {0, 0, ""};

    while (!debo_parar(estado))
    {
        char caracter = input[indice_caracter]; 
        respuesta.lexema[indice_caracter - indice_inicial] = caracter;

        int caracter_interpretado = interpretar_caracter(caracter);
        estado = TABLA[estado][caracter_interpretado];
        indice_caracter++;

        //printf("Mi estado es %s \n", interpretar_estado(estado));
    }

    if(es_centinela(estado)){
        indice_caracter--;
        respuesta.lexema[indice_caracter - indice_inicial] = '\0';
    }

    respuesta.indice = indice_caracter;
    respuesta.token = estado;
    
    //printf("El caracter entero es %s \n", input);
    return respuesta;
}