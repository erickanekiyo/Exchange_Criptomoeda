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
    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %s\n", formatar_cpf(usuario->cpf));
    printf("\nReais: R$ %.2f\n", carteira->Reais);
    printf("Bitcoin: BTC %.8f\n", carteira->Bitcoin);
    printf("Ethereum: ETH %.8f\n", carteira->Ethereum);
    printf("Ripple: XRP %.2f\n", carteira->Ripple);
}

void verificacao(Usuario* usuario, Carteira* carteira) {
    tela_saldo();

    int senha;
    printf("                 SENHA: ");
    scanf("%d", &senha);

    while (senha != usuario->senha) {
        printf("               XXXXXXXXXXXXXXXXXXXX\n");
        printf("               XXXXX INVALIDO XXXXX\n");
        printf("               XXXXXXXXXXXXXXXXXXXX\n\n");
        printf("                 SENHA: ");
        scanf("%d", &senha);
    }

    system("cls || clear");
    tela_saldo();
    consultando(usuario, carteira);
}