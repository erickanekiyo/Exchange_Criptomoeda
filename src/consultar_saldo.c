#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tipos.h"
#include "../include/format_cpf.h"

void tela_saldo() {
    printf("=====================================================\n");
    printf("======================= SALDO =======================\n");
    printf("=====================================================\n");
    printf("\n");
    printf("-----------------------------------------------------\n\n");
}

void consultando(Usuario* usuario, Carteira* carteira) {
    char cpf_formatado[15];
    formatar_cpf(usuario->cpf, cpf_formatado);

    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %s\n", cpf_formatado);
    printf("\nReais: R$ %.2f\n", carteira->reais);
    printf("Bitcoin: BTC %.8f\n", carteira->bitcoin);
    printf("Ethereum: ETH %.8f\n", carteira->ethereum);
    printf("Ripple: XRP %.2f\n", carteira->ripple);
}

void verificacao(Usuario* usuario, Carteira* carteira) {
    tela_saldo();
    consultando(usuario, carteira);
}
