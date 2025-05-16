#include "ContaBancaria.h"
#include <iostream>
using namespace std;
// Construtor da conta bancária
ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
    : numero(numero), saldo(saldo), titular(titular) {}
// Adiciona um valor ao saldo
void ContaBancaria::depositar(double valor) {
    if (valor > 0) {
        saldo += valor;
    }
}
// Remove um valor do saldo, se houver saldo suficiente
void ContaBancaria::sacar(double valor) {
    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
    } else {
        cout << "Saldo insuficiente para saque." << endl;
    }
}
// Transfere um valor para outra conta, se houver saldo
void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << endl;
    } else {
        cout << "Saldo insuficiente para transferência." << endl;
    }
}
// Transfere o valor dividido entre duas contas
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    double metade = valor / 2.0;
    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero
             << " e " << destino2.numero << ") da conta " << numero << endl;
    } else {
        cout << "Saldo insuficiente para transferência múltipla." << endl;
    }
}
// Exibe o saldo atual
void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}
// Exibe informações do titular e conta
void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
    cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
}