#include <stdio.h>
#include <stdlib.h>
#include "../include/tipos.h"
#include "../include/salvar_dados.h"
#include "../include/consultar_saldo.h"

void tela_sacar() {
    printf("=====================================================\n");
    printf("======================= SACAR =======================\n");
    printf("=====================================================\n");
    printf("\n-----------------------------------------------------\n\n");
}

void sacar_valor(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas) {
    float sacar_valor, novo_valor;

    tela_sacar();
    printf("                   <[ R$%.2f ]>\n\n", carteira->reais);

    while (1) {
        printf("Digite o valor a ser sacado: R$");
        scanf("%f", &sacar_valor);

        novo_valor = carteira->reais - sacar_valor;

        if (novo_valor <= 0) {
            system("cls || clear");
            tela_sacar();
            printf("                   <[ R$%.2f ]>\n\n", carteira->reais);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf(">>>>> Valor maior do que o presente na carteira <<<<<\n");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
            continue;
        }

        carteira->reais = novo_valor;

        salvar_dados_usuario(usuario, carteira);
        char linha[300];
        snprintf(
            linha, sizeof(linha),
            "-%.2f REAL CT: %.1f  TX: %.2f REAL: %.2f BTC: %.8f ETH: %.8f XRP: %.2f", sacar_valor, 0.0, 0.00, carteira->reais, carteira->bitcoin, carteira->ethereum, carteira->ripple
        );

        salvar_extrato(usuario, linha);

        system("cls || clear");
        tela_sacar();
        printf("   SAQUE REALIZADO!  <[ R$%.2f ]>\n\n", sacar_valor);
        consultando(usuario, carteira);
        return;
    }
}
