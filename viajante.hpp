#ifndef VIAJANTE_HPP
#define VIAJANTE_HPP
#include "Usuario.hpp"

class Viajante : public Usuario {
public:
    Viajante(std::string id, std::string nome, std::string email, std::string senha);
    void exibirPainel() const override;
};
#endif // VIAJANTE_HPP