#include "itemPedido.cpp"

class Venda{
	private:
		string cliente;
		itemPedido *itens;
		string data;
		float valorTotalVenda;
	public:
		string getCliente(){
			return cliente;
		}
		void setCliente(string cliente){
			this->cliente=cliente;
		}
		
		itemPedido* getItens(){
			return itens;
		}
		void setItens(itemPedido *itens){
			this->itens=itens;
		}
		
		string getData(){
			return data;
		}
		void setData(string data){
			this->data=data;
		}
		
		float getValorTotalVenda(){
			return valorTotalVenda;
		}
		void setValorTotalVenda(float valorTotalVenda){
			this->valorTotalVenda=valorTotalVenda;
		}
		
		Venda(){
			cliente="";
			data="";
			valorTotalVenda=0;
			itens=new itemPedido[10];
			
		}
		
	void imprimirVenda(){
	for (int i=0;i<10;i++){
		itens[i].imprimirItem();
	}
		cout<<"Cliente: "<<cliente<<"\nData: "<<data<<"Valor Total: "<<valorTotalVenda<<endl;
	    
	}
		
};
