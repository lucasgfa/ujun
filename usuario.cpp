#include "Usuario.hpp"

Usuario::Usuario(std::string id, std::string nome, std::string email, std::string senha, TipoRole role)
    : id(id), nome(nome), email(email), senhaHash(senha), role(role) {}
std::string Usuario::getId() const { return id; }
std::string Usuario::getNome() const { return nome; }