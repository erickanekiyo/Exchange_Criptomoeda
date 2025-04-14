#ifndef TIPOS_H
#define TIPOS_H

#define MAX_NOME 100

enum { BITCOIN = 0, ETHEREUM, RIPPLE };

typedef struct {
    char nome[MAX_NOME];
    long long cpf;
    int senha;
} Usuario;

typedef struct {
    double reais;
    double bitcoin;
    double ethereum;
    double ripple;
} Carteira;

typedef struct {
    double cotacoes[3];
} Cotacoes;

typedef struct {
    double compra[3];
    double venda[3];
} Taxas;

#endif
