#ifndef PACOTETURISTICO_HPP
#define PACOTETURISTICO_HPP
#include <string>
#include <vector>
#include <memory>

class ProdutoTuristico; 

class PacoteTuristico {
private:
    std::string id, nome, descricao;
    std::vector<std::shared_ptr<ProdutoTuristico>> produtosInclusos;
public:
    PacoteTuristico(std::string id, std::string nome, std::string descricao);
    void adicionarProduto(std::shared_ptr<ProdutoTuristico> produto);
    double calcularPrecoPacote(double descontoPercentual = 10.0) const;
    bool verificarDisponibilidadePacote(int quantidadePacotes = 1) const;
    std::string getDetalhesPacote() const;
    std::string getId() const;
    std::string getNome() const;
    const std::vector<std::shared_ptr<ProdutoTuristico>>& getProdutos() const;
};
#endif // PACOTETURISTICO_HPP