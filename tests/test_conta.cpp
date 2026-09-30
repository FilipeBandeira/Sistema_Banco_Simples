#include "ContaBancaria.h"
#include <cassert>
#include <limits>
#include <stdexcept>

int main() {
    Cliente titular("Exemplo", "000.000.000-00");
    ContaBancaria origem(1, titular, 1000), a(2, titular), b(3, titular);
    origem.transferir(200, a);
    origem.transferir(300, a, b);
    assert(origem.getSaldo() == 500 && a.getSaldo() == 350 && b.getSaldo() == 150);
    origem.depositar(50);
    origem.sacar(25);
    assert(origem.getSaldo() == 525);
    for (double valor : {0.0, -1.0, std::numeric_limits<double>::infinity(),
                         -std::numeric_limits<double>::infinity(),
                         std::numeric_limits<double>::quiet_NaN(), 10000.0}) {
        origem.sacar(valor);
        origem.transferir(valor, a);
        origem.transferir(valor, a, b);
        assert(origem.getSaldo() == 525 && a.getSaldo() == 350 && b.getSaldo() == 150);
    }
    for (double valor : {0.0, -1.0, std::numeric_limits<double>::infinity(),
                         std::numeric_limits<double>::quiet_NaN()}) {
        origem.depositar(valor);
        assert(origem.getSaldo() == 525);
    }
    origem.transferir(20, origem);
    origem.transferir(20, a, origem);
    origem.transferir(20, a, a);
    assert(origem.getSaldo() == 525 && a.getSaldo() == 350);
    ContaBancaria grande(4, titular, std::numeric_limits<double>::max());
    grande.depositar(std::numeric_limits<double>::max());
    assert(grande.getSaldo() == std::numeric_limits<double>::max());
    ContaBancaria grande2(5, titular, std::numeric_limits<double>::max());
    grande.transferir(std::numeric_limits<double>::max(), grande2);
    grande.transferir(std::numeric_limits<double>::max(), grande2, b);
    assert(grande.getSaldo() == std::numeric_limits<double>::max());
    assert(b.getSaldo() == 150);
    for (double saldo : {-1.0, std::numeric_limits<double>::infinity(),
                         std::numeric_limits<double>::quiet_NaN()}) {
        bool rejeitado = false;
        try { ContaBancaria invalida(6, titular, saldo); }
        catch (const std::invalid_argument&) { rejeitado = true; }
        assert(rejeitado);
    }
}
