#include "Cliente.h"

// Construtor que inicializa os atributos nome e cpf 
Cliente::Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}
// Métodos de acesso (getters) - Retorna o nome do cliente
string Cliente::getNome() const {
    return nome;
}
// Retorna o CPF do cliente
string Cliente::getCpf() const {
    return cpf;
}
