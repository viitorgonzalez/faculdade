#ifndef CONTA_H
#define CONTA_H

#include "Data.cpp"

class Conta {
	private:
		int numero;
		float saldo;
		Data dataAbertura;

	public:
		Conta(){
			numero = 0;
			saldo = 0.0;
		}

		int getNumero(){
			return numero;
		}

		void setNumero(int numero){
			this->numero = numero;
		}

		float getSaldo(){
			return saldo;
		}

		void setSaldo(float saldo){
			this->saldo = saldo;
		}

		Data getDataAbertura(){
			return dataAbertura;
		}

		void setDataAbertura(Data dataAbertura){
			this->dataAbertura = dataAbertura;
		}
};

#endif