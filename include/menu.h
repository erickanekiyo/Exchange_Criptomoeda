#ifndef MENU_H
#define MENU_H

#include "tipos.h"
#include "format_cpf.h"
#include "consultar_saldo.h"
#include "consultar_extrato.h"
#include "depositar_valor.h"
#include "salvar_dados.h"
#include "sacar_valor.h"
#include "carregar_dados.h"
#include "comprar_cripto.h"
#include "vender_cripto.h"
#include "atualizar_cotacao.h"
#include "random_cotacao.h"

void menu(Usuario* usuario, Carteira* carteira, Cotacoes* cotacoes, Taxas* taxas);

#endif
