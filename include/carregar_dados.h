#ifndef CARREGAR_DADOS_H
#define CARREGAR_DADOS_H

#include "tipos.h"

int carregar_dados_usuario(const char* nome_arquivo, Usuario* usuario, Carteira* carteira);
int carregar_extrato(const char* nome_arquivo, char extrato[][256], int* total_linhas);
int carregar_todos_os_usuarios(Usuario usuarios[], int max_usuarios);
int carregar_cotacoes(const char* nome_arquivo, Cotacoes* cotacoes);


#endif
