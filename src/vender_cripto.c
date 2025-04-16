#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vender_cripto.h"
#include "../include/salvar_dados.h"
#include "../include/consultar_saldo.h"

void tela_vender() {
    printf("=====================================================\n");
    printf("================= VENDER CRIPTOMOEDA ================\n");
    printf("=====================================================\n");
    printf("\n-----------------------------------------------------\n\n");
}

void invalidacao_venda() {
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf(">>>>> Valor maior do que o presente na carteira <<<<<\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
}

void invalido_venda() {
    printf("\n               XXXXXXXXXXXXXXXXXXXX\n");
    printf("               XXXXX INVÁLIDO XXXXX\n");
    printf("               XXXXXXXXXXXXXXXXXXXX\n\n");
}

void vender_cripto(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas) {
    int senha;

    tela_vender();

    while (1) {
        int tipo_moeda;
        float vender_valor, valor_retirado, float_cota, conversao, taxa, valor_vendido;

        printf("CARTEIRA:\n");
        consultando(usuario, carteira);

        printf("\nCOTACAO:\n");
        printf("1. Bitcoin: R$%.2f\n", cotacoes->bitcoin);
        printf("2. Ethereum: R$%.2f\n", cotacoes->ethereum);
        printf("3. Ripple: R$%.2f\n", cotacoes->ripple);
        printf("0. Sair\n");

        printf("\n-----------------------------------------------------\n");
        printf("Digite o numero da moeda: ");
        scanf("%d", &tipo_moeda);

        if (tipo_moeda == 0) return;

        if (tipo_moeda < 1 || tipo_moeda > 3) {
            system("cls || clear");
            tela_vender();
            invalido_venda();
            continue;
        }

        printf("\nDigite o valor a ser vendido: ");
        scanf("%f", &vender_valor);

        if (vender_valor == 0) return;

        switch (tipo_moeda) {
            case 1:
                valor_retirado = carteira->bitcoin - vender_valor;
                if (valor_retirado < 0) {
                    system("cls || clear");
                    tela_vender();
                    invalidacao_venda();
                    continue;
                }
                float_cota = cotacoes->bitcoin;
                taxa = (vender_valor * float_cota) * taxas->v_bitcoin;
                conversao = vender_valor * float_cota;
                valor_vendido = conversao - taxa;
                carteira->bitcoin = valor_retirado;
                break;

            case 2:
                valor_retirado = carteira->ethereum - vender_valor;
                if (valor_retirado < 0) {
                    system("cls || clear");
                    tela_vender();
                    invalidacao_venda();
                    continue;
                }
                float_cota = cotacoes->ethereum;
                taxa = (vender_valor * float_cota) * taxas->v_ethereum;
                conversao = vender_valor * float_cota;
                valor_vendido = conversao - taxa;
                carteira->ethereum = valor_retirado;
                break;

            case 3:
                valor_retirado = carteira->ripple - vender_valor;
                if (valor_retirado < 0) {
                    system("cls || clear");
                    tela_vender();
                    invalidacao_venda();
                    continue;
                }
                float_cota = cotacoes->ripple;
                taxa = (vender_valor * float_cota) * taxas->v_ripple;
                conversao = vender_valor * float_cota;
                valor_vendido = conversao - taxa;
                carteira->ripple = valor_retirado;
                break;
        }

        printf("\n\n   || Insira sua senha para confirmar a compra ||\n\n");
        printf("0. Sair\n\n");
        printf("                 SENHA: ");
        scanf("%d", &senha);

        if (senha == 0) {
            return;
        }
        
        while (senha != usuario->senha) {
            invalido_venda();
            printf("                 SENHA: ");
            scanf("%d", &senha);
            if (senha == 0) {
                return;
            }
        }

        system("cls || clear");
        tela_vender();

        carteira->reais += valor_vendido;

        salvar_dados_usuario(usuario, carteira);

        const char* nome_moeda = tipo_moeda == 1 ? "BTC" : tipo_moeda == 2 ? "ETH" : "XRP";
        char linha[300];
        snprintf(
            linha, sizeof(linha),
            "-%.8f %s CT: %.1f  TX: %.2f REAL: %.2f BTC: %.8f ETH: %.8f XRP: %.2f", vender_valor, nome_moeda, float_cota, taxa, carteira->reais, carteira->bitcoin, carteira->ethereum, carteira->ripple
        );
        salvar_extrato(usuario, linha);

        system("cls || clear");
        tela_vender();

        printf("VENDA EFETUADA!\n\n");
        printf("<[%.8f]>%s  ==> <[R$%.2f - TX:%.2f]>\n\n", vender_valor, nome_moeda, valor_vendido, taxa);
        consultando(usuario, carteira);
        return;
    }
}