#include "ContaBancaria.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
// Construtor da conta bancária
ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
    : numero(numero), saldo(saldo), titular(titular) {
    if (!std::isfinite(saldo) || saldo < 0) {
        throw std::invalid_argument("Saldo inicial inválido.");
    }
}
// Adiciona um valor ao saldo
void ContaBancaria::depositar(double valor) {
    if (std::isfinite(valor) && valor > 0 && std::isfinite(saldo + valor)) {
        saldo += valor;
    }
}
// Remove um valor do saldo, se houver saldo suficiente
void ContaBancaria::sacar(double valor) {
    if (std::isfinite(valor) && valor > 0 && valor <= saldo) {
        saldo -= valor;
    } else {
        cout << "Saque inválido ou saldo insuficiente." << endl;
    }
}
// Transfere um valor para outra conta, se houver saldo
void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (&destino != this && std::isfinite(valor) && valor > 0 && valor <= saldo &&
        std::isfinite(destino.saldo + valor)) {
        saldo -= valor;
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << endl;
    } else {
        cout << "Transferência inválida ou saldo insuficiente." << endl;
    }
}
// Transfere o valor dividido entre duas contas
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    double metade = valor / 2.0;
    if (&destino1 != this && &destino2 != this && &destino1 != &destino2 &&
        std::isfinite(valor) && valor > 0 && valor <= saldo &&
        std::isfinite(destino1.saldo + metade) &&
        std::isfinite(destino2.saldo + metade)) {
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero
             << " e " << destino2.numero << ") da conta " << numero << endl;
    } else {
        cout << "Transferência múltipla inválida ou saldo insuficiente." << endl;
    }
}
// Exibe o saldo atual
double ContaBancaria::getSaldo() const {
    return saldo;
}

void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}
// Exibe informações do titular e conta
void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
    cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
}
