package com.devflix;

import java.util.ArrayList;

import javax.swing.JOptionPane;

public class App {
    public static void main(String[] args) throws Exception {
        int opc = 0;
        String[] opcs = {"Adicionar Filme", "Buscar Filme", "Exibir Filmes"};
        ArrayList<Filme> filmes = new ArrayList<>();
        do {
            opc = Util.JShowDialog(opcs);
            switch (opc) {
                case 0:
                    filmes.add(Filme.adicionarFilme());
                    break;
                case 1:
                    String genero = JOptionPane.showInputDialog("Informe o gênero que deseja buscar:");
                    Filme.buscarFilmes(filmes, genero);
                    break;
                case 2:
                    Filme.exibirFilmes(filmes);
                    break;
                default:
                    System.out.println("Nenhuma opção válida escolhida");
                    break;
            }
        } while(opc != -1);
    }
}
