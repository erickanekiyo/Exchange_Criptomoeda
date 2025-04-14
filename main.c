#include <stdio.h>
#include <stdlib.h>
#include "../include/tipos.h"
#include "../include/format_cpf.h"
#include "../include/menu.h"
#include "../include/consultar_saldo.h"


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
