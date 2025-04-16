#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "format_cpf.h"
#include "menu.h"
#include "consultar_saldo.h"
#include "carregar_dados.h"
#include "salvar_dados.h"

#define MAX_USUARIOS 10

int verificar_usuario(Usuario usuarios[], int total_usuarios, long long cpf, int senha) {
    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].cpf == cpf && usuarios[i].senha == senha) {
            return i;
        }
    }
    return -1;
}

void tela_login() {
    printf("=====================================================\n");
    printf("======================= LOGIN =======================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");
}

int main() {
    system("cls || clear");
    Usuario usuarios[MAX_USUARIOS];
    Carteira carteira;
    Cotacoes cotacoes;
    Taxas taxas;

    taxas.c_bitcoin = 0.02;
    taxas.v_bitcoin = 0.03;
    taxas.c_ethereum = 0.01;
    taxas.v_ethereum = 0.02;
    taxas.c_ripple = 0.01;
    taxas.v_ripple = 0.01;

    int total_usuarios = carregar_todos_os_usuarios(usuarios, MAX_USUARIOS);

    long long cpf_input;
    int senha_input;
    int indice = -1;

    tela_login();

    while (indice == -1) {
        printf("CPF: ");
        scanf("%lld", &cpf_input);

        printf("Senha: ");
        scanf("%d", &senha_input);

        indice = verificar_usuario(usuarios, total_usuarios, cpf_input, senha_input);

        if (indice == -1) {
            system("cls || clear");

            tela_login();

            printf("           XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
            printf("           XX CPF ou senha incorretos XX\n");
            printf("           XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
        }
    }

    Usuario usuario = usuarios[indice];

    char nome_arquivo_usuario[] = "data/dados.txt";
    carregar_dados_usuario(nome_arquivo_usuario, &usuario, &carteira);

    char nome_arquivo_extrato[64];
    snprintf(nome_arquivo_extrato, sizeof(nome_arquivo_extrato), "data/extrato_%lld.txt", usuario.cpf);

    char extrato[100][256];
    int total_linhas = 0;
    carregar_extrato(nome_arquivo_extrato, extrato, &total_linhas);
    carregar_cotacoes("data/cotacoes.txt", &cotacoes);

    system("cls || clear");
    tela_login();

    printf("Bem-vindo, %s!\n\n", usuario.nome);

    menu(&usuario, &carteira, &cotacoes, &taxas);

    salvar_dados_usuario(&usuario, &carteira);

    return 0;
}
