#include "PacoteTuristico.hpp"
#include "ProdutoTuristico.hpp"
#include <sstream>
#include <iomanip>

PacoteTuristico::PacoteTuristico(std::string id, std::string nome, std::string descricao)
    : id(id), nome(nome), descricao(descricao) {}
void PacoteTuristico::adicionarProduto(std::shared_ptr<ProdutoTuristico> produto) {
    if (produto) produtosInclusos.push_back(produto);
}
double PacoteTuristico::calcularPrecoPacote(double descontoPercentual) const {
    double precoTotalItens = 0.0;
    for (const auto& produto : produtosInclusos) precoTotalItens += produto->getPreco();
    if (descontoPercentual > 0.0 && descontoPercentual < 100.0) {
        return precoTotalItens * (1.0 - (descontoPercentual / 100.0));
    }
    return precoTotalItens;
}
bool PacoteTuristico::verificarDisponibilidadePacote(int quantidadePacotes) const {
    if (produtosInclusos.empty()) return false;
    for (const auto& produto : produtosInclusos) {
        if (produto->getDisponibilidade() < quantidadePacotes) return false;
    }
    return true;
}
std::string PacoteTuristico::getDetalhesPacote() const {
    std::ostringstream oss;
    oss << "Pacote Turístico: " << nome << "\n"
        << "  Descrição: " << descricao << "\n"
        << "  Preço com Desconto: R$ " << std::fixed << std::setprecision(2) << calcularPrecoPacote() << "\n"
        << "  Itens Inclusos:\n";
    for (const auto& produto : produtosInclusos) oss << "  - " << produto->getNome() << "\n";
    return oss.str();
}
std::string PacoteTuristico::getId() const { return id; }
std::string PacoteTuristico::getNome() const { return nome; }
const std::vector<std::shared_ptr<ProdutoTuristico>>& PacoteTuristico::getProdutos() const {
    return produtosInclusos;
}