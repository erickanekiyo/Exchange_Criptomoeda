Objetivo do Projeto:

  Esse projeto é uma plataforma simulada de transações envolvendo criptomoedas, feita em C, seu objetivo é de representar o funcionamento básico de uma exchange. Ele permite que até 10 usuários façam login com CPF e senha, acessem sua carteira virtual, e realizem operações como depósito, compra e consulta de extratos. Além disso, as moedas trabalhadas são Bitcoin, Ethereum e Ripple.
  
  O programa é uma forma prática e simplificada para entender como funcionam operações financeiras e armazenamento de dados em um sistema sem o uso de banco de dados externo.

Como Compilar e Executar:

  1 - Para compilar o programa, use o GCC com os arquivos organizados nas pastas src e include. Depois use esse comando de compilação no terminal:

            gcc -o programa main.c src/atualizar_cotacao.c src/carregar_dados.c src/comprar_cripto.c src/consultar_extrato.c src/consultar_saldo.c src/depositar_valor.c src/format_cpf.c src/menu.c src/random_cotacao.c src/sacar_valor.c src/salvar_dados.c src/vender_cripto.c -Iinclude

  2 - Para executar, coloque esse: ./programa

Como Usar a Plataforma:

  Para começar, é importante avisar que valores não inteiros devem ser expressados com "." ao invés de "," ainda mais que o próprio programa irá fazer dessa maneira. Para o registro de novos usuários ou akterações em registros à parte das funções do programa, é preciso retirar as informações de um e colocar o desejado, deixando a estrutura do arquivo da mesma maneira que antes.
  
  1 - Login
  
    Ao iniciar, o programa solicita CPF e senha. Apenas os 10 usuários previamente cadastrados no arquivo <dado.txt> podem acessar.
    
  2 - Menu Principal
  
    Depois de acessado, o usuário pode escolher entre as opções que aparecerão no terminal:

      + Consultar o saldo da carteira (Reais e Criptomoedas)
      + Consultar o extrato do usuário (até 100 extratos por usuário)
      + Depositar valores em Reais
      + Sacar dinheiro da carteira
      + Comprar ou vender Bitcoin, Ethereum e Ripple
      + Atualizar as cotações das moedas (com variação simulada de até ±5% do ultimo valor registrado)

  3 - Armazenamento de Dados:
  
    dados.txt: guarda os dados dos usuários e valores da carteira
    extrato_<cpf>.txt: registra as últimas 100 transações de cada usuário
    cotacoes.txt: armazena os valores atuais das criptos
