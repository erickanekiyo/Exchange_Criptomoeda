#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/consultar_extrato.h"
#include "../include/format_cpf.h"

void tela_extrato() {
    printf("=====================================================\n");
    printf("====================== EXTRATO ======================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");
}

void ver_extrato(Usuario* usuario) {
    int senha;
    tela_extrato();

    printf("                 SENHA: ");
    scanf("%d", &senha);

    while (senha != usuario->senha) {
        printf("               XXXXXXXXXXXXXXXXXXXX\n");
        printf("               XXXXX INVÁLIDO XXXXX\n");
        printf("               XXXXXXXXXXXXXXXXXXXX\n");

        printf("                 SENHA: ");
        scanf("%d", &senha);
    }


    system("cls || clear");

    char cpf_formatado[15];

    formatar_cpf(usuario->cpf, cpf_formatado);

    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %s\n\n", cpf_formatado);

    char nome_arquivo[50];
    sprintf(nome_arquivo, "data/extrato_%lld.txt", usuario->cpf);

    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Nenhum extrato encontrado.\n");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}
