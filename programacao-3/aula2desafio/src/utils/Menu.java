package utils;

import java.util.Scanner;

public class Menu {
    public static int menu(Scanner sc) {
        System.out.println("0- Sair");
        System.out.println("1- Sacar");
        System.out.println("2- Depositar");
        System.out.println("3- Ver saldo");
        System.out.println("Digite uma opção:");
        
        return sc.nextInt();
    }
}
