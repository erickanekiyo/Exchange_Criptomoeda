#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/consultar_saldo.h"
#include "../include/depositar_valor.h"
#include "../include/comprar_cripto.h"


void menu(struct Usuario* usuario, struct Carteira* carteira, struct Cotacoes* cotacoes, struct Taxas* taxas) {
void menu(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas) {
    int opcao;
    while (1) {
        printf("=====================================================\n");
        printf("======================= OPCOES ======================\n");
        printf("=====================================================\n\n");

        printf("                1. Consultar saldo\n");
        printf("                2. Consultar extrato\n");
        printf("                3. Depositar\n");
        printf("                4. Sacar\n");
        printf("                5. Comprar criptomoedas\n");
        printf("                6. Vender criptomoedas\n");
        printf("                7. Atualizar cotacao\n");
        printf("                8. Sair\n\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);

        system("cls || clear");

        switch (opcao) {
            case 1: verificacao(usuario, carteira); break;
            case 2: ver_extrato(usuario); break;
            case 3: depositar(usuario, carteira); break;
            case 4: printf("==> Sacar\n"); break;
            case 5: printf("==> Comprar criptomoedas\n"); break;
            case 5: comprar_cripto(usuario, carteira, cotacoes, taxas); break;
            case 6: printf("==> Vender criptomoedas\n"); break;
            case 7: printf("==> Atualizar cotacao\n"); break;
            case 8: printf("Saindo...\n"); exit(0);
            default: printf("Opcao invalida.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar(); getchar();
        system("cls || clear");
    }
}
