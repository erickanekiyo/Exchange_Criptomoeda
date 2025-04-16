#include <stdio.h>
#include <stdlib.h>
#include "../include/atualizar_cotacao.h"
#include "../include/salvar_dados.h"
#include "../include/random_cotacao.h"

void tela_atualizar() {
    printf("=====================================================\n");
    printf("================= ATUALIZAR COTACAO =================\n");
    printf("=====================================================\n");
    printf("\n-----------------------------------------------------\n\n");
}

void atualizar_cotacao(Cotacoes* cotacoes, Taxas* taxas) {
    int opcao;

    while (1) {
        tela_atualizar();
        printf("Bitcoin:  R$%.2f\n", cotacoes->bitcoin);
        printf("Ethereum: R$%.2f\n", cotacoes->ethereum);
        printf("Ripple:   R$%.2f\n", cotacoes->ripple);

        printf("\n1. ATUALIZAR\n");
        printf("2. VOLTAR\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            system("cls || clear");
            variacao(cotacoes);
            salvar_cotacoes(cotacoes);
        } else if (opcao == 2) {
            return;
        } else {
            printf("Opcao invalida.\n");
        }
    }
}
