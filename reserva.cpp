#include "Reserva.hpp"
#include "Viajante.hpp"
#include "ProdutoTuristico.hpp"
#include "PacoteTuristico.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>

Reserva::Reserva(std::string id, Viajante* viajante, const std::string& dataReserva)
    : id(id), viajante(viajante), dataReserva(dataReserva), status(StatusReserva::PENDENTE), precoTotalCalculado(0.0) {
    if (!viajante) throw std::invalid_argument("Viajante não pode ser nulo.");
}
void Reserva::adicionarPacote(std::shared_ptr<PacoteTuristico> pacote) {
    if (pacote) {
        pacotesReservados.push_back(pacote);
        calcularPrecoTotal();
    }
}
double Reserva::calcularPrecoTotal() {
    precoTotalCalculado = 0.0;
    for (const auto& pacote : pacotesReservados) precoTotalCalculado += pacote->calcularPrecoPacote();
    return precoTotalCalculado;
}
bool Reserva::confirmarReserva() {
    if (status!= StatusReserva::PENDENTE) return false;
    for (const auto& pacote : pacotesReservados) {
        if (!pacote->verificarDisponibilidadePacote(1)) {
            std::cerr << "Erro: Pacote " << pacote->getNome() << " não disponível." << std::endl;
            return false;
        }
    }
    for (const auto& pacote : pacotesReservados) {
        for (const auto& produto_no_pacote : pacote->getProdutos()) {
            produto_no_pacote->atualizarDisponibilidade(1);
        }
    }
    this->status = StatusReserva::CONFIRMADA;
    return true;
}
bool Reserva::cancelarReserva() {
    if (status == StatusReserva::CONFIRMADA || 
        status == StatusReserva::PENDENTE) {
        this->status = StatusReserva::CANCELADA;
        return true;
    }
    return false;
}
std::string Reserva::getDetalhesReserva() const {
    std::ostringstream oss;
    oss << "Detalhes da Reserva ID: " << id << "\n"
        << "  Viajante: " << (viajante? viajante->getNome() : "N/A") << "\n"
        << "  Status: ";
    switch(status) {
        case StatusReserva::PENDENTE: oss << "Pendente"; break;
        case StatusReserva::CONFIRMADA: oss << "Confirmada"; break;
        case StatusReserva::CANCELADA: oss << "Cancelada"; break;
        case StatusReserva::CONCLUIDA: oss << "Concluída"; break;
    }
    oss << "\n  Preço Total: R$ " << std::fixed << std::setprecision(2) << precoTotalCalculado << "\n";
    if (!pacotesReservados.empty()) {
        oss << "  Pacotes:\n";
        for(const auto& pacote : pacotesReservados) oss << "  - " << pacote->getNome() << "\n";
    }
    return oss.str();
}