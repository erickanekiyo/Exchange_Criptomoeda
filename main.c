#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "format_cpf.h"
#include "menu.h"
#include "consultar_saldo.h"

#define MAX_USUARIOS 10

int verificar_usuario(Usuario usuarios[], int total_usuarios, long long cpf, int senha) {
    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].cpf == cpf && usuarios[i].senha == senha) {
            return i;
        }
    }
    return -1;
}

int main() {
    Usuario usuario;
    Carteira carteira;
    Cotacoes cotacoes;
    Taxas taxas;

    Usuario usuarios[MAX_USUARIOS] = {
        {"Eric H. Kanekiyo", 12345678900, 1234},
        {"Joao Silva", 98765432100, 4321},
        {"Maria Oliveira", 45678912300, 1111},
        {"Carlos Souza", 11223344556, 2222},
        {"Ana Lima", 99887766554, 3333},
        {"Felipe Rocha", 10293847566, 4444},
        {"Juliana Costa", 66554433221, 5555},
        {"Bruno Martins", 77889900112, 6666},
        {"Larissa Mendes", 33445566778, 7777},
        {"Rafael Barbosa", 88776655443, 8888}
    };

    long long cpf_input;
    int senha_input;
    int indice = -1;

    printf("=====================================================\n");
    printf("======================= LOGIN =======================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");

    while(indice == -1) {
        printf("CPF: ");
        scanf("%lld", &cpf_input);

        printf("Senha: ");
        scanf("%d", &senha_input);

        indice = verificar_usuario(usuarios, MAX_USUARIOS, cpf_input, senha_input);

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
    
    usuario = usuarios[indice];
    system("cls || clear");
    printf("Bem-vindo, %s!\n\n", usuarios[indice].nome);

    menu(&usuario, &carteira, &cotacoes, &taxas);

    return 0;
}
