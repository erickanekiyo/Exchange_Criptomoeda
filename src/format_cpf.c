#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/format_cpf.h"

void formatar_cpf(long long cpf, char* destino) {
    snprintf(destino, 15, "%03lld.%03lld.%03lld-%02lld",
             (cpf / 100000000) % 1000,
             (cpf / 100000) % 1000,
             (cpf / 100) % 1000,
             cpf % 100);
}