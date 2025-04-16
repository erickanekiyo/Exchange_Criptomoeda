#ifndef MENU_H
#define MENU_H

#include "tipos.h"
#include "format_cpf.h"
#include "consultar_saldo.h"
#include "consultar_extrato.h"
#include "depositar_valor.h"
#include "salvar_dados.h"
#include "carregar_dados.h"
#include "comprar_cripto.h"

void menu(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas);

#endif
