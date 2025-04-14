#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/format_cpf.h"

char* formatar_cpf(long long cpf) {
    static char formatado[15];
    snprintf(formatado, sizeof(formatado), "%03lld.%03lld.%03lld-%02lld",
             (cpf / 100000000) % 1000,
             (cpf / 100000) % 1000,
             (cpf / 100) % 1000,
             cpf % 100);
    return formatado;
}