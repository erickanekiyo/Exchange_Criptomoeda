#include "include/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Usuario usuario;
    Carteira carteira;
    Cotacoes cotacoes;
    Taxas taxas;


    usuario.cpf = 12345678900;
    usuario.senha = 1234;

    strcpy(usuario.nome, "Eric H. Kanekiyo");


    menu(&usuario, &carteira, &cotacoes, &taxas);

    return 0;
}
