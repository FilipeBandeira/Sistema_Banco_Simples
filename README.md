# Sistema bancário simples

Projeto acadêmico de Linguagem de Programação I em **C++11**. Demonstra clientes e contas bancárias com encapsulamento, composição e sobrecarga de métodos.

## Funcionalidades

- Cliente com nome e CPF.
- Conta com número, titular e saldo.
- Depósito e saque.
- Transferência para uma conta ou divisão do valor entre duas contas.
- Exibição dos dados e saldos.

## Como executar

Requisitos: compilador C++11 e GNU Make.

```sh
git clone https://github.com/FilipeBandeira/Sistema_Banco_Simples.git
cd Sistema_Banco_Simples
make
./BancoSimples
make test
```

O programa executa um cenário demonstrativo: Ana começa com R$ 1.000, transfere R$ 200 para Bruno e divide R$ 300 entre Bruno e Carla. Saldos finais: **Ana R$ 500, Bruno R$ 350 e Carla R$ 150**.

## Estrutura

| Arquivo | Responsabilidade |
| --- | --- |
| `Cliente.*` | Dados do titular |
| `ContaBancaria.*` | Estado da conta e operações |
| `main.cpp` | Cenário de demonstração |
| `tests/test_conta.cpp` | Regressões das operações |
| `Makefile` | Compilação e testes |

## Regras e limites

Operações rejeitam valores não positivos ou não finitos. Saques e transferências também exigem saldo suficiente. O construtor rejeita saldo inicial inválido. Transferências para a própria conta são rejeitadas.

Este é um exercício de POO: usa `double` para valores monetários e não implementa persistência, autenticação, transações concorrentes, validação de CPF ou um livro contábil. Uma aplicação financeira real exigiria outra modelagem, incluindo valores em centavos e garantias transacionais.

## Qualidade e evolução

`make test` verifica operações válidas, rejeições e preservação do saldo. O GitHub Actions compila e executa os testes. Próximos passos: representação monetária em centavos, extrato e persistência.

## Autor e licença

[Filipe Bandeira](https://github.com/FilipeBandeira). Consulte o arquivo [LICENSE](LICENSE) para os termos do repositório. Materiais e marcas de terceiros mantêm seus respectivos direitos.
