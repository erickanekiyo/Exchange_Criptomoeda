#ifndef MENU_H
#define MENU_H

#include "tipos.h"
#include "format_cpf.h"
#include "consultar_saldo.h"
#include "consultar_extrato.h"
#include "depositar_valor.h"
#include "salvar_dados.h"
#include "carregar_dados.h"

void menu(struct Usuario* usuario, struct Carteira* carteira, struct Cotacoes* cotacoes, struct Taxas* taxas);

#endif
