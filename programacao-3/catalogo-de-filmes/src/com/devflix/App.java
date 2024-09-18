package com.devflix;
import javax.swing.JOptionPane;

public class App {
    public static void main(String[] args) throws Exception {
        int opc = 0;
        String[] opcs = {"Opção 1", "Opção 2", "Opção 3"};
        do {
            opc = JOptionPane.showOptionDialog(
                null,
                "Escolha uma Opção",
                "Menu",
                JOptionPane.DEFAULT_OPTION,
                JOptionPane.INFORMATION_MESSAGE,
                null,
                opcs,
                opcs[0]
            );

            switch (opc) {
                case 0:
                    System.out.println("Você escolheu Opção 1");
                    break;
                case 1:
                    System.out.println("Você escolheu Opção 2");
                    break;
                case 2:
                    System.out.println("Você escolheu Opção 3");
                    break;
                default:
                    System.out.println("Nenhuma opção válida escolhida");
                    break;
            }
        } while(opc != 0);
    }
}

// Crie uma aplicação para gerenciar um catálogo de filmes. Cada filme tem título,
// gênero, ano de lançamento e uma nota (entre 0 e 10). A lista de filmes deve permitir:
// • Adicionar novos filmes.
// • Buscar filmes por gênero.
// • Exibir os filmes com nota superior a 8.
