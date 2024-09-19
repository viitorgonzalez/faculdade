package com.devflix;

import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Filme {
  private String titulo;
  private String genero;
  private String dataLancamento;
  private float nota;

  public Filme() {}

  public Filme(String titulo, String genero, String dataLancamento, float nota) {
    this.titulo = titulo;
    this.genero = genero;
    this.dataLancamento = dataLancamento;
    this.nota = nota;
  }

  public String getTitulo() {
    return titulo;
  }

  public void setTitulo(String titulo) {
    this.titulo = titulo;
  }

  public String getGenero() {
    return genero;
  }

  public void setGenero(String genero) {
    this.genero = genero;
  }

  public String getDataLancamento() {
    return dataLancamento;
  }

  public void setDataLancamento(String dataLancamento) {
    this.dataLancamento = dataLancamento;
  }

  public float getNota() {
    return nota;
  }

  public void setNota(float nota) throws Exception {
    if(nota >= 0 && nota <= 10)
      this.nota = nota;
    else throw new Exception("Valor inválido.");
  }

  public static Filme adicionarFilme() {
    String titulo = JOptionPane.showInputDialog("Informe o título do filme:");
    String genero = JOptionPane.showInputDialog("Informe o gênero do filme:");
    String dataLancamento = JOptionPane.showInputDialog("Informe a data de lançamento do filme (dd/MM/yyyy):");
    float nota = Float.parseFloat(JOptionPane.showInputDialog("Informe a nota do filme (0-10):"));
    
    return new Filme(titulo, genero, dataLancamento, nota);
  }

    public static void exibirFilmes(ArrayList<Filme> filmes) {
    StringBuilder resultado = new StringBuilder();
    for (Filme filme : filmes) {
      if(filme.getNota() >= 8 ) {
        resultado.append("Título: ").append(filme.getTitulo()).append("\n");
        resultado.append("Gênero: ").append(filme.getGenero()).append("\n");
        resultado.append("Data de Lançamento: ").append(filme.getDataLancamento()).append("\n");
        resultado.append("Nota: ").append(filme.getNota()).append("\n\n");
      } 
    }
    if (resultado.length() > 0)
      JOptionPane.showMessageDialog(null, resultado.toString(), "Filmes com nota superior a 8", JOptionPane.INFORMATION_MESSAGE);
    else 
      JOptionPane.showMessageDialog(null, "Nenhum filme com nota superior a 8 foi encontrado", "Resultado", JOptionPane.INFORMATION_MESSAGE);
  }

  public static void buscarFilmes(ArrayList<Filme> filmes, String genero) {
    StringBuilder resultado = new StringBuilder();
    for (Filme filme : filmes) {
      if(filme.getGenero().equalsIgnoreCase(genero)) {
        resultado.append("Título: ").append(filme.getTitulo()).append("\n");
          resultado.append("Gênero: ").append(filme.getGenero()).append("\n");
          resultado.append("Data de Lançamento: ").append(filme.getDataLancamento()).append("\n");
          resultado.append("Nota: ").append(filme.getNota()).append("\n\n");
      }
    }

    if (resultado.length() > 0) 
      JOptionPane.showMessageDialog(null, resultado.toString(), "Filmes Encontrados", JOptionPane.INFORMATION_MESSAGE);
    else 
      JOptionPane.showMessageDialog(null, "Nenhum filme encontrado com o gênero: " + genero, "Resultado", JOptionPane.INFORMATION_MESSAGE);
    
  } 
}
