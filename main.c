#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "format_cpf.h"
#include "menu.h"
#include "consultar_saldo.h"


int main() {
    Usuario usuario;
    Carteira carteira;
    Cotacoes cotacoes;
    Taxas taxas;


    usuario.cpf = 12345678900;
    usuario.senha = 1234;

    taxas.c_bitcoin = 0.02;
    taxas.v_bitcoin = 0.03;
    taxas.c_ethereum = 0.015;
    taxas.v_ethereum = 0.025;
    taxas.c_ripple = 0.01;
    taxas.v_ripple = 0.02;

    cotacoes.Bitcoin = 385.747;
    cotacoes.Ethereum = 14.229;
    cotacoes.Ripple = 2.94;

    strcpy(usuario.nome, "Eric H. Kanekiyo");


    menu(&usuario, &carteira, &cotacoes, &taxas);

    return 0;
}