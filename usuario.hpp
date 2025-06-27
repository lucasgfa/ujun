#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>
#include "EnumTypes.hpp"

class Usuario {
protected:
    std::string id, nome, email, senhaHash;
    TipoRole role;
public:
    Usuario(std::string id, std::string nome, std::string email, std::string senha, TipoRole role);
    virtual ~Usuario() = default;
    std::string getId() const;
    std::string getNome() const;
    virtual void exibirPainel() const = 0;
};
#endif // USUARIO_HPP