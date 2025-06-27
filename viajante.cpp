#include "Viajante.hpp"
#include <iostream>

Viajante::Viajante(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::VIAJANTE) {}
void Viajante::exibirPainel() const {
    std::cout << "\n--- Painel do Viajante: " << nome << " ---" << std::endl;
}