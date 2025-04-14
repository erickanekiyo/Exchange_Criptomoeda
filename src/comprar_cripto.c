#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/comprar_cripto.h"
#include "../include/format_cpf.h"
#include "../include/consultar_saldo.h"

void tela_comprar() {
    printf("=====================================================\n");
    printf("================ COMPRAR CRIPTOMOEDA ================\n");
    printf("=====================================================\n");
    printf("\n-----------------------------------------------------\n\n");
}

void invalidacao() {
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf(">>>>> Valor maior do que o presente na carteira <<<<<\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
}

void invalido() {
    printf("               XXXXXXXXXXXXXXXXXXXX\n");
    printf("               XXXXX INVALIDO XXXXX\n");
    printf("               XXXXXXXXXXXXXXXXXXXX\n");
}

void comprar_cripto(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas) {
    char id_compra[] = "compra_criptoid";
    int senha;

    tela_comprar();
    printf("                 SENHA: ");
    scanf("%d", &senha);
    
    while (senha != usuario->senha) {
        invalido();
        printf("                 SENHA: ");
        scanf("%d", &senha);
    }

    system("cls");
    tela_comprar();

    while (1) {
        int tipo_moeda;
        float comprar_valor, taxa = 0.0f, valor_retirado, float_cota, conversao;

        printf("CARTEIRA: R$%.2f\n\n", carteira->Reais);

        printf("COTACAO:\n");
        printf("1. Bitcoin: R$%.2f\n", cotacoes->Bitcoin);
        printf("2. Ethereum: R$%.2f\n", cotacoes->Ethereum);
        printf("3. Ripple: R$%.2f\n", cotacoes->Ripple);

        printf("\nDigite o numero da moeda: ");
        scanf("%d", &tipo_moeda);

        if (tipo_moeda < 1 || tipo_moeda > 3) {
            system("cls");
            tela_comprar();
            invalido();
            continue;
        }

        printf("Digite o valor a ser usado: R$");
        scanf("%f", &comprar_valor);

        switch (tipo_moeda) {
            case 1:
                taxa = comprar_valor * taxas->c_bitcoin;
                float_cota = cotacoes->Bitcoin;
                break;
            case 2:
                taxa = comprar_valor * taxas->c_ethereum;
                float_cota = cotacoes->Ethereum;
                break;
            case 3:
                taxa = comprar_valor * taxas->c_ripple;
                float_cota = cotacoes->Ripple;
                break;
        }

        valor_retirado = comprar_valor + taxa;

        if (carteira->Reais < valor_retirado) {
            system("cls");
            tela_comprar();
            invalidacao();
            continue;
        }

        conversao = comprar_valor / float_cota;

        switch (tipo_moeda) {
            case 1:
                carteira->Bitcoin = conversao;
                break;
            case 2:
                carteira->Ethereum = conversao;
                break;
            case 3:
                carteira->Ripple = conversao;
                break;
        }

        carteira->Reais -= valor_retirado;
        system("cls");
        tela_comprar();

        const char* nome_moeda = tipo_moeda == 1 ? "BTC" : (tipo_moeda == 2 ? "ETH" : "XRP");
        printf("COMPRA EFETUADA!\n");
        printf("<[R$%.2f + TX: %.2f]>  ==> <[%.8f]>%s\n\n", comprar_valor, taxa, conversao, nome_moeda);

        consultando(usuario, carteira);
        return;
    }
}
