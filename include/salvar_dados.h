#ifndef SALVAR_DADOS_H
#define SALVAR_DADOS_H

#include "tipos.h"

void salvar_dados_usuario(Usuario* usuario, Carteira* carteira);
void salvar_extrato(Usuario* usuario, const char* linha);

#endif
