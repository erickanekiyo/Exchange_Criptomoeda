#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/tipos.h"

#define MAX_USUARIOS 10

void salvar_dados_usuario(Usuario* usuario, Carteira* carteira) {
    Usuario usuarios[MAX_USUARIOS];
    Carteira carteiras[MAX_USUARIOS];
    int total = 0;

    FILE* arquivo = fopen("data/dados.txt", "r");
    if (arquivo) {
        while (fscanf(arquivo, "nome: %[^\n]\ncpf: %lld\nsenha: %d\nReais: %lf\nBitcoin: %lf\nEthereum: %lf\nRipple: %lf\n",
                      usuarios[total].nome, &usuarios[total].cpf, &usuarios[total].senha,
                      &carteiras[total].reais, &carteiras[total].bitcoin, &carteiras[total].ethereum, &carteiras[total].ripple) == 7) {
            total++;
            if (total >= MAX_USUARIOS) break;
        }
        fclose(arquivo);
    }

    int encontrado = 0;
    for (int i = 0; i < total; i++) {
        if (usuarios[i].cpf == usuario->cpf) {
            usuarios[i] = *usuario;
            carteiras[i] = *carteira;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado && total < MAX_USUARIOS) {
        usuarios[total] = *usuario;
        carteiras[total] = *carteira;
        total++;
    }

    arquivo = fopen("data/dados.txt", "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de dados");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "nome: %s\n", usuarios[i].nome);
        fprintf(arquivo, "cpf: %lld\n", usuarios[i].cpf);
        fprintf(arquivo, "senha: %d\n", usuarios[i].senha);
        fprintf(arquivo, "Reais: %.2f\n", carteiras[i].reais);
        fprintf(arquivo, "Bitcoin: %.8f\n", carteiras[i].bitcoin);
        fprintf(arquivo, "Ethereum: %.8f\n", carteiras[i].ethereum);
        fprintf(arquivo, "Ripple: %.2f\n", carteiras[i].ripple);
    }

    fclose(arquivo);
}


void salvar_extrato(Usuario* usuario, const char* linha) {
    char nome_arquivo[50];
    snprintf(nome_arquivo, sizeof(nome_arquivo), "data/extrato_%lld.txt", usuario->cpf);


    FILE* arquivo = fopen(nome_arquivo, "a");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de extrato");
        return;
    }

    int num_registros = 0;
    char linha_temp[256];
    FILE* verificar_arquivo = fopen(nome_arquivo, "r");
    if (verificar_arquivo) {
        while (fgets(linha_temp, sizeof(linha_temp), verificar_arquivo)) {
            num_registros++;
        }
        fclose(verificar_arquivo);
    }

    if (num_registros >= 100) {
        FILE* arquivo_temp = fopen("data/temp.txt", "w");
        if (!arquivo_temp) {
            perror("Erro ao abrir arquivo temporario");
            fclose(arquivo);
            return;
        }

        verificar_arquivo = fopen(nome_arquivo, "r");
        if (!verificar_arquivo) {
            perror("Erro ao abrir o arquivo de extrato para reescrita");
            fclose(arquivo);
            fclose(arquivo_temp);
            return;
        }

        fgets(linha_temp, sizeof(linha_temp), verificar_arquivo);

        while (fgets(linha_temp, sizeof(linha_temp), verificar_arquivo)) {
            fputs(linha_temp, arquivo_temp);
        }
        
        fclose(arquivo_temp);
        fclose(verificar_arquivo);

        remove(nome_arquivo);
        rename("data/temp.txt", nome_arquivo);
    }

    time_t agora = time(NULL);
    struct tm* t = localtime(&agora);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%d-%m-%Y %H:%M:%S", t);

    fprintf(arquivo, "%s %s\n", timestamp, linha);

    fclose(arquivo);
}

void salvar_cotacoes(const Cotacoes* cotacoes) {
    FILE* arquivo = fopen("data/cotacoes.txt", "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de cotações");
        return;
    }

    fprintf(arquivo, "Bitcoin: %.2f\n", cotacoes->bitcoin);
    fprintf(arquivo, "Ethereum: %.2f\n", cotacoes->ethereum);
    fprintf(arquivo, "Ripple: %.2f\n", cotacoes->ripple);

    fclose(arquivo);
}