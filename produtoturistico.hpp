#ifndef PRODUTOTURISTICO_HPP
#define PRODUTOTURISTICO_HPP
#include <string>

class ProdutoTuristico {
protected:
    std::string id, nome, descricao;
    double precoBase;
    int disponibilidade;
public:
    ProdutoTuristico(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade);
    virtual ~ProdutoTuristico() = default;
    std::string getId() const;
    std::string getNome() const;
    int getDisponibilidade() const;
    virtual double getPreco() const = 0;
    virtual void atualizarDisponibilidade(int quantidadeVendida);
    virtual std::string getDetalhes() const = 0;
};
#endif // PRODUTOTURISTICO_HPP