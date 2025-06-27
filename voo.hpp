#ifndef VOO_HPP
#define VOO_HPP
#include "ProdutoTuristico.hpp"
#include <string>

class Voo : public ProdutoTuristico {
private:
    std::string origem, destino, dataPartida, dataChegada, companhiaAerea;
public:
    Voo(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade,
        std::string origem, std::string destino, std::string dataPartida, std::string dataChegada, std::string companhiaAerea);
    ~Voo() override = default;
    double getPreco() const override;
    std::string getDetalhes() const override;
};
#endif // VOO_HPP