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
    double bitcoin;
    double ethereum;
    double ripple;
} Carteira;

typedef struct Cotacoes {
    double cotacoes[3];
    double bitcoin;
    double ethereum;
    double ripple;
} Cotacoes;

typedef struct Taxas {
    double compra[3];
    double venda[3];
typedef struct {
    float c_bitcoin;
    float v_bitcoin;
    float c_ethereum;
    float v_ethereum;
    float c_ripple;
    float v_ripple;
} Taxas;

#endif
