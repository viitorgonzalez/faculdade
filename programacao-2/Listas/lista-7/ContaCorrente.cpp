#include "ContaBancaria.cpp"

class ContaCorrente : public ContaBancaria {
    private:
        float taxaJuros, limite, taxaServico;

    public:
        void aplicarServico(Conta conta){
            float saldo = conta.getSaldo();
            if (saldo < 0) {
                saldo *= (1 + taxaJuros / 100);
                saldo += taxaServico;
                conta.setSaldo(saldo);
            }
        }

        float getTaxaJuros(){
            return taxaJuros;
        }

        void setTaxaJuros(float taxaJuros){
            this->taxaJuros = taxaJuros;
        }

        float getLimite(){
            return limite;
        }

        void setLimite(float limite){
            this->limite = limite;
        }

        float getTaxaServico(){
            return taxaServico;
        }

        void setTaxaServico(float taxaServico){
            this->taxaServico = taxaServico;
        }
};
