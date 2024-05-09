#include "ContaBancaria.cpp"

class ContaPoupanca : public ContaBancaria {
	private:
		Data dataAniversario;
		float taxaRendimento;

	public:
		void aplicarRendimento(){
			int dia, mes, ano;
			cout << "Informe a data de aniversario (dia/mes/ano): " << endl;
			cin >> dia;
			cin >> mes;
			cin >> ano;
			if ((dia == dataAniversario.getDia()) && (mes == dataAniversario.getMes()) && (ano == dataAniversario.getAno())){
				float valor=getSaldo() * (taxaRendimento / 100);
				setSaldo(getSaldo() + valor);
			}		
		}

		Data getDataAniversario(){
			return dataAniversario;
		}

		void setDataAniversario(Data dataAniversario){
			this->dataAniversario = dataAniversario;
		}

		float getTaxaRendimento(){
			return taxaRendimento;
		}

		void setTaxaRendimento(float taxaRendimento){
			this->taxaRendimento = taxaRendimento;
		}
};