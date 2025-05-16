#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;
// Classe que representa um cliente do banco
class Cliente {
private:
    string nome;
    string cpf;

public:
    // Construtor que inicializa nome e cpf
    Cliente(string nome, string cpf);
    // Métodos de acesso aos atributos privados
    string getNome() const;
    string getCpf() const;
};

#endif
