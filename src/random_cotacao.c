#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/tipos.h"

void variacao(Cotacoes* cotacoes) {
    srand(time(NULL));

    float fator_btc = 0.95f + ((float)rand() / RAND_MAX) * 0.10f;
    float fator_eth = 0.95f + ((float)rand() / RAND_MAX) * 0.10f;
    float fator_xrp = 0.95f + ((float)rand() / RAND_MAX) * 0.10f;

    cotacoes->bitcoin  *= fator_btc;
    cotacoes->ethereum *= fator_eth;
    cotacoes->ripple   *= fator_xrp;
}