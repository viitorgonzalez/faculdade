#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include "Conta.cpp"

class ContaBancaria : public Conta {
	private:
		string chave;

	public:
		void imprimirConta(){
        cout << "Numero da conta: " << getNumero() << endl;
        cout << "Saldo: " << getSaldo() << endl;
        cout << "Data de abertura: " << getDataAbertura().getDia() << "/";
        if (getDataAbertura().getMes() < 10) {
            cout << "0";
        }
        cout << getDataAbertura().getMes() << "/" << getDataAbertura().getAno() << endl;
    }

		void sacar(float valor){
            if (valor > 0 && valor <= getSaldo()) {
                setSaldo(getSaldo() - valor);
                cout << "Saque de R$ " << valor << " realizado com sucesso." << endl;
            } else {
                cout << "Saldo insuficiente para saque." << endl;
            }
        }

		void depositar(float valor){
        if (valor > 0) {
            setSaldo(getSaldo() + valor);
            cout << "Depósito de R$ " << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Valor de depósito inválido." << endl;
        }
    }

		void setChave(string chave){
			this->chave = chave;
		}
};

#endif