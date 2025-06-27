#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

#include "Viajante.hpp"
#include "Voo.hpp"
#include "PacoteTuristico.hpp"
#include "Reserva.hpp"

int main() {
    try {
        std::cout << "===== Sistema de Agencia de Viagem - Simulacao =====" << std::endl;

        std::unique_ptr<Viajante> viajante(new Viajante("v001", "Clarice Lispector", "clarice@email.com", "senha123"));
        auto voo_ida = std::make_shared<Voo>("voo001", "Voo BH-SP", "Voo de Belo Horizonte para Sao Paulo", 350.00, 50, "CNF", "CGH", "2025-08-15 08:00", "2025-08-15 09:15", "Azul");
        auto voo_volta = std::make_shared<Voo>("voo002", "Voo SP-BH", "Voo de Sao Paulo para Belo Horizonte", 380.00, 45, "CGH", "CNF", "2025-08-20 18:30", "2025-08-20 19:45", "Azul");
        
        auto pacote_viagem_sp = std::make_shared<PacoteTuristico>("pct01", "Viagem Completa para SP", "Pacote com voos de ida e volta.");
        pacote_viagem_sp->adicionarProduto(voo_ida);
        pacote_viagem_sp->adicionarProduto(voo_volta);

        std::cout << "\n--- Pacote Criado ---\n" << pacote_viagem_sp->getDetalhesPacote() << std::endl;

        Reserva reserva("r001", viajante.get(), "2025-06-26");
        reserva.adicionarPacote(pacote_viagem_sp);
        
        std::cout << "\n--- Detalhes Iniciais da Reserva ---\n" << reserva.getDetalhesReserva();

        std::cout << "\n--- Tentando confirmar a reserva... ---" << std::endl;
        if (reserva.confirmarReserva()) {
            std::cout << "Reserva confirmada com sucesso!" << std::endl;
        } else {
            std::cout << "Falha ao confirmar a reserva." << std::endl;
        }

        std::cout << "\n--- Detalhes Finais da Reserva ---\n" << reserva.getDetalhesReserva();

        std::cout << "\n--- Disponibilidade Atualizada dos Produtos ---" << std::endl;
        std::cout << "Disponibilidade do " << voo_ida->getNome() << ": " << voo_ida->getDisponibilidade() << " assentos." << std::endl;
        std::cout << "Disponibilidade do " << voo_volta->getNome() << ": " << voo_volta->getDisponibilidade() << " assentos." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro inesperado: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}