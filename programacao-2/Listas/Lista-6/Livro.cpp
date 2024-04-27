#include "Produto.cpp"

class Livro : public Produto {
    private:
        string autor;
        int numeroPaginas;

    public:
        Livro(int codigo, string descricao, double preco, int quantidade) : Produto(codigo, descricao, preco, quantidade) {}

        Livro(int codigo, string descricao, double preco, int quantidade, string autor, int numeroPaginas) : Produto(codigo, descricao, preco, quantidade) {
            setAutor(autor);
            setNumeroPaginas(numeroPaginas);
        }

        string getAutor() {
            return autor;
        }

        void setAutor(string autor) {
            this->autor = autor;
        }

        int getNumeroPaginas() {
            return numeroPaginas;
        }

        void setNumeroPaginas(int numeroPaginas) {
            this->numeroPaginas = numeroPaginas;
        }
        
        void imprimeProduto() {
            cout << "Código: " << getCodigo() << endl;
            cout << "Descrição: " << getDescricao() << endl;
            cout << "Preço: " << getPreco() << endl;
            cout << "Quantidade: " << getQuantidade() << endl;
            cout << "Autor: " << getAutor() << endl;
            cout << "Número de páginas: " << getNumeroPaginas() << endl;
            cout << endl;
        }
};
