#include <iostream>
using namespace std;

class Produto{
	private:
		string nome;
		string descricao;
		float preco;
	public:
		Produto(){
			nome="";
			descricao="";
			preco=0;
		}
		
		void imprimirProduto(){
			
	       cout<<"Nome: "<<nome<<"\nDescricao: "<<"Preço: "<<preco<<endl;
		}
		
		
		string getNome(){
			return nome;
		}
		
		void setNome(string nome){
			this->nome = nome;
		}
		
		string getDescricao(){
			return descricao;
		}
		
		void setDescricao(string descricao){
			this->descricao = descricao;
		}
		
		float getPreco(){
			return preco;
		}
		
		void setPreco(float preco){
			this->preco = preco;
		}
		
};
