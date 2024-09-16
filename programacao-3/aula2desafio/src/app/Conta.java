package app;
public class Conta {
    private double saldo;

    Conta(double saldo) {
        setSaldo(saldo);
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public void sacar(double quantidade) throws Exception {
        if(quantidade > this.getSaldo()) throw new Exception("Saldo insuficente.");
        this.saldo -= quantidade;
    }

    public void depositar(double quantidade) throws Exception {
        if(quantidade <= 0) throw new Exception("Valor inválido.");
        this.saldo += quantidade;
    }
}
