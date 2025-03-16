public class Operacoes {
    private double resultado;
    private double numeroAnterior;
    private String operadorAnterior;

    public Operacoes() {
        this.resultado = 0;
        this.numeroAnterior = 0;
        this.operadorAnterior = "";
    }

    public double realizarOperacao(double numero, String operador) {
        switch (operador) {
            case "+":
                resultado += numero;
                break;
            case "-":
                resultado -= numero;
                break;
            case "*":
                resultado *= numero;
                break;
            case "/":
                if (numero != 0) {
                    resultado /= numero;
                } else {
                    return Double.NaN;
                }
                break;
            case "RAIZ Q":
                resultado = Math.sqrt(numero);
                break;
            case "x^y":
                resultado = Math.pow(numeroAnterior, numero);
                break;
            case "x^2":
                resultado = Math.pow(numero, 2);
                break;
            case "x^3":
                resultado = Math.pow(numero, 3);
                break;
            case "10^X":
                resultado = Math.pow(10, numero);
                break;
            case "X!":
                resultado = fatorial((int) numero);
                break;
            case "+/-":
                resultado = -numero;
                break;
            case "%":
                double aux = 0;
                switch (operadorAnterior) {
                    case "+":
                        aux = numero - numeroAnterior;
                        resultado = aux + (aux * (numeroAnterior / 100));
                        break;

                    case "-":
                        aux = numero + numeroAnterior;
                        resultado = aux - (aux * (numeroAnterior / 100));
                        break;

                    case "*":
                        aux = numero / numeroAnterior;
                        resultado = aux * (numeroAnterior / 100);
                        break;

                    case "/":
                        aux = numero * numeroAnterior;
                        resultado = aux / (numeroAnterior / 100);
                        break;
                }
                break;
            default:
                resultado = numero;
        }
        return resultado;
    }

    public void setNumeroAnterior(double numero) {
        this.numeroAnterior = numero;
    }

    public void setOperadorAnterior(String operador) {
        this.operadorAnterior = operador;
    }

    private double fatorial(int num) {
        if (num == 0)
            return 1;
        double fatorial = 1;
        for (int i = 1; i <= num; i++) {
            fatorial *= i;
        }
        return fatorial;
    }

    public void reset() {
        resultado = 0;
    }

    public double getResultado() {
        return resultado;
    }
}
