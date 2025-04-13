#ifndef TIPOS_H
#define TIPOS_H

#define MAX_NOME 50

typedef struct Usuario {
    char nome[MAX_NOME];
    long long cpf;
    int senha;
} Usuario;

typedef struct Carteira {
    double reais;
    double cripto[3];
} Carteira;

typedef struct Cotacoes {
    double cotacoes[3];
} Cotacoes;

typedef struct Taxas {
    double compra[3];
    double venda[3];
} Taxas;

#endif
