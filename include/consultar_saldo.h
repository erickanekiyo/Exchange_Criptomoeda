#ifndef CONSULTAR_SALDO_H
#define CONSULTAR_SALDO_H

#include "tipos.h"
#include "format_cpf.h"

void tela_saldo();
void consultando(struct Usuario* usuario, struct Carteira* carteira);
void verificacao(struct Usuario* usuario, struct Carteira* carteira);

#endif