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
        printf("Verificando usuario %d: %lld com CPF: %lld e senha: %d\n", i, usuarios[i].cpf, cpf, usuarios[i].senha);
        if (usuarios[i].cpf == cpf && usuarios[i].senha == senha) {
            return i;
        }
    }
    return -1;
}

int main() {
    Usuario usuarios[MAX_USUARIOS];
    Carteira carteira;
    Cotacoes cotacoes;
    Taxas taxas;

    int total_usuarios = carregar_todos_os_usuarios(usuarios, MAX_USUARIOS);

    long long cpf_input;
    int senha_input;
    int indice = -1;

    printf("=====================================================\n");
    printf("======================= LOGIN =======================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");

    while (indice == -1) {
        printf("CPF: ");
        scanf("%lld", &cpf_input);

        printf("Senha: ");
        scanf("%d", &senha_input);

        indice = verificar_usuario(usuarios, total_usuarios, cpf_input, senha_input);

        if (indice == -1) {
            system("cls || clear");
            printf("=====================================================\n");
            printf("======================= LOGIN =======================\n");
            printf("=====================================================\n\n");
            printf("-----------------------------------------------------\n\n");

            printf("           XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
            printf("           XX CPF ou senha incorretos XX\n");
            printf("           XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
        }
    }

    Usuario usuario = usuarios[indice];

    printf("Usuario selecionado após login: %s - CPF: %lld\n", usuario.nome, usuario.cpf);

    char nome_arquivo_usuario[] = "data/dados.txt";
    carregar_dados_usuario(nome_arquivo_usuario, &usuario, &carteira);

    char nome_arquivo_extrato[64];
    snprintf(nome_arquivo_extrato, sizeof(nome_arquivo_extrato), "data/extrato_%lld.txt", usuario.cpf);

    char extrato[100][256];
    int total_linhas = 0;
    carregar_extrato(nome_arquivo_extrato, extrato, &total_linhas);


    printf("Bem-vindo, %s!\n\n", usuario.nome);
    printf("Exibindo extrato:\n");
    for (int i = 0; i < total_linhas; i++) {
        printf("%s", extrato[i]);
    }

    menu(&usuario, &carteira, &cotacoes, &taxas);

    salvar_dados_usuario(&usuario, &carteira);

    return 0;
}
