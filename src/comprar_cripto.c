#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/comprar_cripto.h"
#include "../include/format_cpf.h"
#include "../include/consultar_saldo.h"
#include "../include/salvar_dados.h"

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
    printf("               XXXXXXXXXXXXXXXXXXXX\n\n");
}

void comprar_cripto(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas) {
    char id_compra[] = "compra_criptoid";
    int senha;

    tela_comprar();
    
    while (1) {
        int tipo_moeda;
        float comprar_valor, taxa = 0.0f, valor_retirado, float_cota, conversao;

        printf("CARTEIRA: R$%.2f\n\n", carteira->reais);

        printf("COTACAO:\n");
        printf("1. Bitcoin: R$%.2f\n", cotacoes->bitcoin);
        printf("2. Ethereum: R$%.2f\n", cotacoes->ethereum);
        printf("3. Ripple: R$%.2f\n", cotacoes->ripple);
        printf("0. Sair\n\n");

        printf("Digite o numero da moeda: ");
        scanf("%d", &tipo_moeda);

        if (tipo_moeda < 0 || tipo_moeda > 3) {
            system("cls || clear");
            tela_comprar();
            invalido();
            continue;
        }

        printf("\nDigite o valor a ser usado: R$");
        scanf("%f", &comprar_valor);

        switch (tipo_moeda) {
            case 1:
                taxa = comprar_valor * taxas->c_bitcoin;
                float_cota = cotacoes->bitcoin;
                break;
            case 2:
                taxa = comprar_valor * taxas->c_ethereum;
                float_cota = cotacoes->ethereum;
                break;
            case 3:
                taxa = comprar_valor * taxas->c_ripple;
                float_cota = cotacoes->ripple;
                break;
        }

        if (tipo_moeda == 0) {
            return;
        }

        valor_retirado = comprar_valor + taxa;

        if (carteira->reais < valor_retirado) {
            system("cls || clear");
            tela_comprar();
            invalidacao();
            continue;
        }

        conversao = comprar_valor / float_cota;

        switch (tipo_moeda) {
            case 1:
                carteira->bitcoin = conversao;
                break;
            case 2:
                carteira->ethereum = conversao;
                break;
            case 3:
                carteira->ripple = conversao;
                break;
        }

        if (comprar_valor == 0) {
            return;
        }

        printf("\n\n   || Insira sua senha para confirmar a compra ||\n\n");
        printf("0. Sair\n\n");
        printf("                 SENHA: ");
        scanf("%d", &senha);

        if (senha == 0) {
            return;
        }
        
        while (senha != usuario->senha) {
            invalido();
            printf("                 SENHA: ");
            scanf("%d", &senha);
            if (senha == 0) {
                return;
            }
        }

        system("cls || clear");
        tela_comprar();


        carteira->reais -= valor_retirado;
        system("cls || clear");
        tela_comprar();

        const char* nome_moeda = tipo_moeda == 1 ? "BTC" : (tipo_moeda == 2 ? "ETH" : "XRP");
        printf("COMPRA EFETUADA!\n\n");
        printf("<[R$%.2f + TX: %.2f]>  ==> <[%.8f]>%s\n\n", comprar_valor, taxa, conversao, nome_moeda);

        char linha[300];
        snprintf(
            linha, sizeof(linha),
            "-%.2f REAL CT: %.1f  TX: %.2f REAL: %.2f BTC: %.8f ETH: %.8f XRP: %.2f", comprar_valor, float_cota, taxa, carteira->reais, carteira->bitcoin, carteira->ethereum, carteira->ripple
        );
        salvar_extrato(usuario, linha);
        salvar_dados_usuario(usuario, carteira);
        consultando(usuario, carteira);
        return;
    }
}