#include "Voo.hpp"
#include <sstream>
#include <iomanip>

Voo::Voo(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade,
         std::string origem, std::string destino, std::string dataPartida, std::string dataChegada, std::string companhiaAerea)
    : ProdutoTuristico(id, nome, descricao, precoBase, disponibilidade),
      origem(origem), destino(destino), dataPartida(dataPartida), dataChegada(dataChegada), companhiaAerea(companhiaAerea) {}

double Voo::getPreco() const { return precoBase + 50.0; }

std::string Voo::getDetalhes() const { 
    std::ostringstream oss;
    oss << "Voo: " << nome << " (" << companhiaAerea << ")\n"
        << "  De: " << origem << " Para: " << destino << "\n"
        << "  Partida: " << dataPartida << " Chegada: " << dataChegada << "\n"
        << "  Preço: R$ " << std::fixed << std::setprecision(2) << getPreco() << "\n"
        << "  Disponíveis: " << disponibilidade << " assentos.";
    return oss.str();
}