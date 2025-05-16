#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include "Cliente.h"
// Classe que representa uma conta bancária
class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;
// Construtor: pode receber um saldo inicial (padrão = 0.0)
public:
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0);
// Métodos para operações bancárias
    void depositar(double valor);
    void sacar(double valor);
    void transferir(double valor, ContaBancaria &destino);
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);

    void exibirSaldo() const;
    void exibirInformacoes() const;
};

#endif