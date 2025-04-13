#include "include/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NOME 50

struct Usuario {
    char nome[MAX_NOME];
    long long cpf;
    int senha;
};

struct Carteira {
    double reais;
    double cripto[3];
};

struct Cotacoes {
    double cotacoes[3];
};

struct Taxas {
    double compra[3];
    double venda[3];
};

void login(struct Usuario* usuario, struct Carteira* carteira, struct Cotacoes* cotacoes, struct Taxas* taxas) {
    long long cpf;
    int senha;

    printf("CPF: ");
    scanf("%lld", &cpf);

    while (cpf != usuario->cpf) {
        printf("CPF inválido. Tente novamente: ");
        scanf("%lld", &cpf);
    }

    printf("Senha: ");
    scanf("%d", &senha);

    while (senha != usuario->senha) {
        printf("Senha inválida. Tente novamente: ");
        scanf("%d", &senha);
    }

    system("cls");
    menu(usuario, carteira, cotacoes, taxas);
}

int main() {
    struct Usuario usuario = {"Eric H. Kanekiyo", 12345678900, 123456};
    struct Carteira carteira = {0, {0, 0, 0}};
    struct Cotacoes cotacoes = {{385.747, 14.229, 2.94}};
    struct Taxas taxas = {{0.02, 0.01, 0.01}, {0.03, 0.02, 0.01}};

    login(&usuario, &carteira, &cotacoes, &taxas);
    return 0;
}
