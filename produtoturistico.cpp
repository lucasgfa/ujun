#include "ProdutoTuristico.hpp"

ProdutoTuristico::ProdutoTuristico(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade)
    : id(id), nome(nome), descricao(descricao), precoBase(precoBase), disponibilidade(disponibilidade) {}
std::string ProdutoTuristico::getId() const { return id; }
std::string ProdutoTuristico::getNome() const { return nome; }
int ProdutoTuristico::getDisponibilidade() const { return disponibilidade; }
void ProdutoTuristico::atualizarDisponibilidade(int quantidadeVendida) {
    this->disponibilidade -= quantidadeVendida;
    if (this->disponibilidade < 0) this->disponibilidade = 0;
}