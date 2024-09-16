package app;

import java.util.Scanner;
import utils.Menu;

public class App {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite seu saldo:");

        Conta conta = new Conta(sc.nextDouble());

        int op = 0;
        do {
            op = Menu.menu(sc);

            switch (op) {
                case 0:
                    System.out.println("Saindo...");
                    break;

                case 1:
                    System.out.println("Digite o valor que deseja sacar:");
                    conta.sacar(sc.nextDouble());
                    break;

                case 2:
                    System.out.println("Digite o valor que deseja depositar:");
                    conta.depositar(sc.nextDouble());
                    break;

                case 3:
                    System.out.println("Saldo: " + conta.getSaldo());
                    break;
            
                default:
                    System.out.println("Caracter inválido.");
                    break;
            }
        } while(op != 0);

        sc.close();
    }
}
