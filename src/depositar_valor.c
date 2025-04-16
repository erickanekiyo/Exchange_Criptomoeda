#include <stdio.h>
#include <stdlib.h>
#include "../include/tipos.h"
#include "../include/format_cpf.h"
#include "../include/consultar_saldo.h"
#include "../include/salvar_dados.h"

void tela_depositar() {
    printf("=====================================================\n");
    printf("===================== DEPOSITAR =====================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");
}

void qtd_carteira(Carteira* carteira) {
    printf("                   <[ R$%.2f ]>\n", carteira->reais);
}

void depositar(Usuario* usuario, Carteira* carteira) {
    tela_depositar();
    qtd_carteira(carteira);

    double valor;
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &valor);

    carteira->reais += valor;

    system("cls || clear");
    tela_depositar();

    printf("   DEPOSITO REALIZADO!  <[ R$%.2f ]>\n", valor);
    consultando(usuario, carteira);
    salvar_dados_usuario(usuario, carteira);

    char linha[300];
    snprintf(
        linha, sizeof(linha),
        "+%.2f REAL CT: %.1f  TX: %.2f REAL: %.2f BTC: %.8f ETH: %.8f XRP: %.2f", valor, 0.0, 0.00, carteira->reais, carteira->bitcoin, carteira->ethereum, carteira->ripple
    );

    salvar_extrato(usuario, linha);
}
