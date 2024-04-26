#include "Produto.cpp"

class itemPedido{
	private:
		Produto produto;
		int quantidade;
		float valorTotal;
	public:
		Produto getProduto(){
			return produto;
		}
		void setProduto(Produto produto){
			this->produto=produto;
		}
		
		int getQuantidade(){
			return quantidade;
		}
		void setQuantidade(int quantidade){
			this->quantidade=quantidade;
		}
		
		float getValorTotal(){
			return valorTotal;
		}
		void setValorTotal(float valorTotal){
			this->valorTotal=valorTotal;
		}
	
		itemPedido(){
		quantidade=0;
		valorTotal=0;
	    }
		void imprimirItem(){
		produto.imprimirProduto();
		cout<<"\nQuantidade: "<<quantidade<<"\nValor Total: "<<valorTotal;
			
		}
		
};
