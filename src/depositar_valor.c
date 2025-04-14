#include <stdio.h>
#include <stdlib.h>
#include "../include/tipos.h"
#include "../include/format_cpf.h"
#include "../include/consultar_saldo.h"

void tela_depositar() {
    printf("=====================================================\n");
    printf("===================== DEPOSITAR =====================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");
}

void qtd_carteira(Carteira* carteira) {
    printf("                   <[ R$%.2f ]>\n", carteira->Reais);
}

void depositar(Usuario* usuario, Carteira* carteira) {
    tela_depositar();
    qtd_carteira(carteira);

    double valor;
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &valor);

    carteira->Reais += valor;

    system("cls || clear");
    tela_depositar();

    printf("   DEPOSITO REALIZADO!  <[ R$%.2f ]>\n", valor);
    consultando(usuario, carteira);
}