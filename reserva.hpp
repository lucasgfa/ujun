#ifndef RESERVA_HPP
#define RESERVA_HPP
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "EnumTypes.hpp"

class Viajante;
class ProdutoTuristico;
class PacoteTuristico;

class Reserva {
private:
    std::string id;
    Viajante* viajante;
    std::map<std::shared_ptr<ProdutoTuristico>, int> itensIndividuais;
    std::vector<std::shared_ptr<PacoteTuristico>> pacotesReservados;
    std::string dataReserva;
    StatusReserva status;
    double precoTotalCalculado;
public:
    Reserva(std::string id, Viajante* viajante, const std::string& dataReserva);
    void adicionarPacote(std::shared_ptr<PacoteTuristico> pacote);
    double calcularPrecoTotal();
    bool confirmarReserva();
    bool cancelarReserva();
    std::string getDetalhesReserva() const;
};
#endif // RESERVA_HPP