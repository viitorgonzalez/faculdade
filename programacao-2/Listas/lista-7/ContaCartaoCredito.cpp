#include "Conta.cpp"

class ContaCartaoCredito : public Conta {
    private:
        int numeroCartao;

    public:
        void imprimirConta(){
			cout << "Numero da conta: " << getNumero() << endl;
			cout << "Saldo: " << getSaldo() << endl;
			cout << "Data de abertura: " << getDataAbertura().getDia() << "/";
            if  (getDataAbertura().getMes() < 10) {
                cout << "0";
            }
            cout << getDataAbertura().getMes() << "/" << getDataAbertura().getAno() << endl;
		}

		int getNumeroCartao(){
		    return numeroCartao;
		}

		void setNumeroCartao(int numeroCartao){
		    this->numeroCartao = numeroCartao;
		}
};