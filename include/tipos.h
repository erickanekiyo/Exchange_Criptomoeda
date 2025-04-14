#ifndef TIPOS_H
#define TIPOS_H

#define MAX_NOME 50

typedef struct Usuario {
    char nome[MAX_NOME];
    long long cpf;
    int senha;
} Usuario;

typedef struct Carteira {
    double Reais;
    double Bitcoin;
    double Ethereum;
    double Ripple;
} Carteira;

typedef struct Cotacoes {
    double Bitcoin;
    double Ethereum;
    double Ripple;
} Cotacoes;

typedef struct Taxas {
    double c_bitcoin;
    double v_bitcoin;
    double c_ethereum;
    double v_ethereum;
    double c_ripple;
    double v_ripple;
} Taxas;

#endif
