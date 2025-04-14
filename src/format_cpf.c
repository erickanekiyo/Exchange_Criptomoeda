#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/format_cpf.h"

void formatar_cpf(long long cpf, char* destino) {
    char temp[12];
    snprintf(temp, sizeof(temp), "%011lld", cpf);

    // Monta a string formatada
    snprintf(destino, 15, "%c%c%c.%c%c%c.%c%c%c-%c%c",
        temp[0], temp[1], temp[2],
        temp[3], temp[4], temp[5],
        temp[6], temp[7], temp[8],
        temp[9], temp[10]
    );
}
