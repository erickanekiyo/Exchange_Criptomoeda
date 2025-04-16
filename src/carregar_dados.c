#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tipos.h"

int carregar_dados_usuario(const char* nome_arquivo, Usuario* usuario, Carteira* carteira) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de dados do usuário");
        return 0;
    }

    char linha[256];
    long long cpf_atual = 0;
    int senha_temp;
    char nome_temp[100];
    double reais, bitcoin, ethereum, ripple;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "nome:", 5) == 0) {
            sscanf(linha, "nome: %[^\n]", nome_temp);
        } else if (strncmp(linha, "cpf:", 4) == 0) {
            sscanf(linha, "cpf: %lld", &cpf_atual);
        } else if (strncmp(linha, "senha:", 6) == 0) {
            sscanf(linha, "senha: %d", &senha_temp);
        } else if (strncmp(linha, "Reais:", 6) == 0) {
            sscanf(linha, "Reais: %lf", &reais);
        } else if (strncmp(linha, "Bitcoin:", 8) == 0) {
            sscanf(linha, "Bitcoin: %lf", &bitcoin);
        } else if (strncmp(linha, "Ethereum:", 9) == 0) {
            sscanf(linha, "Ethereum: %lf", &ethereum);
        } else if (strncmp(linha, "Ripple:", 7) == 0) {
            sscanf(linha, "Ripple: %lf", &ripple);

            if (cpf_atual == usuario->cpf) {
                strncpy(usuario->nome, nome_temp, sizeof(usuario->nome) - 1);
                usuario->cpf = cpf_atual;
                usuario->senha = senha_temp;

                carteira->reais = reais;
                carteira->bitcoin = bitcoin;
                carteira->ethereum = ethereum;
                carteira->ripple = ripple;
                
                fclose(arquivo);
                return 1;
            }
        }
    }

    fclose(arquivo);
    return 0;
}


int carregar_extrato(const char* nome_arquivo, char extrato[][256], int* total_linhas) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de extrato");
        return 0;
    }

    int linha_idx = 0;
    while (fgets(extrato[linha_idx], 256, arquivo) && linha_idx < 100) {
        linha_idx++;
    }

    *total_linhas = linha_idx;

    fclose(arquivo);
    return 1;
}

int carregar_todos_os_usuarios(Usuario usuarios[], int max_usuarios) {
    FILE* arquivo = fopen("data/dados.txt", "r");
    if (!arquivo) {
        perror("Erro ao abrir dados.txt");
        return 0;
    }

    int total = 0;
    while (total < max_usuarios &&
        fscanf(arquivo, "nome: %[^\n]\ncpf: %lld\nsenha: %d\nReais: %*f\nBitcoin: %*f\nEthereum: %*f\nRipple: %*f\n",
            usuarios[total].nome, &usuarios[total].cpf, &usuarios[total].senha) == 3) {
        printf("Usuario carregado: %s - CPF: %lld - Senha: %d\n", usuarios[total].nome, usuarios[total].cpf, usuarios[total].senha);
        total++;
    }

    fclose(arquivo);
    return total;
}}

int carregar_cotacoes(const char* nome_arquivo, Cotacoes* cotacoes) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de cotações");
        return 0;
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "Bitcoin:", 8) == 0) {
            sscanf(linha, "Bitcoin: %lf", &cotacoes->bitcoin);
        } else if (strncmp(linha, "Ethereum:", 9) == 0) {
            sscanf(linha, "Ethereum: %lf", &cotacoes->ethereum);
        } else if (strncmp(linha, "Ripple:", 7) == 0) {
            sscanf(linha, "Ripple: %lf", &cotacoes->ripple);
        }
    }

    fclose(arquivo);
    return 1;
}
