#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"


void menu(struct Usuario* usuario, struct Carteira* carteira, struct Cotacoes* cotacoes, struct Taxas* taxas) {
    int opcao;
    while (1) {
        printf("=====================================================\n");
        printf("======================= OPÇÕES ======================\n");
        printf("=====================================================\n");

        printf("                1. Consultar saldo\n");
        printf("                2. Consultar extrato\n");
        printf("                3. Depositar\n");
        printf("                4. Sacar\n");
        printf("                5. Comprar criptomoedas\n");
        printf("                6. Vender criptomoedas\n");
        printf("                7. Atualizar cotação\n");
        printf("                8. Sair\n");

        printf("Digite a opção: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1: printf("==> Consultar saldo\n"); break;
            case 2: printf("==> Consultar extrato\n"); break;
            case 3: printf("==> Depositar\n"); break;
            case 4: printf("==> Sacar\n"); break;
            case 5: printf("==> Comprar criptomoedas\n"); break;
            case 6: printf("==> Vender criptomoedas\n"); break;
            case 7: printf("==> Atualizar cotação\n"); break;
            case 8: printf("Saindo...\n"); exit(0);
            default: printf("Opção inválida.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar(); getchar();
        system("cls");
    }
}
