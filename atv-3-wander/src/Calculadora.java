import javax.swing.*;
import java.awt.*;

public class Calculadora extends JFrame {
    private JTextField display;
    private JLabel operadorLabel;
    private Operacoes operacoes;
    private String operadorAtual = "";
    private boolean novoNumero = true;

    public Calculadora() {
        setTitle("Calculadora");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(550, 550);
        setLayout(new BorderLayout(10, 10));

        JPanel topPanel = new JPanel();
        topPanel.setLayout(new GridLayout(2, 1, 5, 5));

        // Display para exibir o número
        display = new JTextField("0");
        display.setFont(new Font("Arial", Font.BOLD, 24));
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setEditable(false);
        display.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
        display.setBackground(new Color(240, 240, 240));

        // JLabel para exibir o operador atual
        operadorLabel = new JLabel("");
        operadorLabel.setFont(new Font("Arial", Font.BOLD, 20));
        operadorLabel.setHorizontalAlignment(JLabel.RIGHT);
        operadorLabel.setForeground(new Color(169, 169, 169, 150));

        // Adiciona display e operadorLabel ao painel
        topPanel.add(operadorLabel);
        topPanel.add(display);

        add(topPanel, BorderLayout.NORTH);

        // Painel de botões
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 5, 10, 10)); // Ajusta o espaçamento entre os botões

        String[] buttons = {
                "AC", "+/-", "%", "RAIZ Q", "/",
                "7", "8", "9", "x^y", "*",
                "4", "5", "6", "x^2", "-",
                "1", "2", "3", "x^3", "+",
                "0", ".", "X!", "10^X", "="
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.BOLD, 18));
            button.setBackground(new Color(240, 240, 240)); 
            button.setForeground(Color.BLACK); 
            button.setFocusPainted(false); // Remove a borda quando clica
            button.setBorder(BorderFactory.createLineBorder(Color.GRAY, 1));
            panel.add(button);
            button.addActionListener(e -> handleButtonClick(button.getText()));
        }

        add(panel, BorderLayout.CENTER);

        operacoes = new Operacoes();
        setVisible(true);
    }

    private void handleButtonClick(String text) {
        if (text.matches("[0-9]")) {
            if (novoNumero) {
                display.setText(text);
                novoNumero = false;
            } else {
                display.setText(display.getText() + text);
            }
        } else if (text.equals(".")) {
            if (!display.getText().contains(".")) {
                display.setText(display.getText() + ".");
                novoNumero = false;
            }
        } else if (text.equals("AC")) {
            operacoes.reset();
            operadorAtual = "";
            display.setText("0");
            operadorLabel.setText("");
            novoNumero = true;
        } else if (text.equals("=")) {
            double numero = Double.parseDouble(display.getText());
            double resultado = operacoes.realizarOperacao(numero, operadorAtual);
            if (Double.isNaN(resultado)) {
                display.setText("Math Error");
            } else {
                display.setText(formatarResultado(resultado));
            }
            operadorAtual = "";
            operadorLabel.setText("");
            novoNumero = true;
        } else if (text.equals("+/-")) {
            String currentText = display.getText();
            if (!currentText.equals("0")) {
                if (currentText.startsWith("-")) {
                    display.setText(currentText.substring(1));
                } else {
                    display.setText("-" + currentText);
                }
            }
        } else {
            if (!novoNumero) {
                operadorLabel.setText(operadorAtual);
            }
             
            double numero = Double.parseDouble(display.getText());
            operacoes.setNumeroAnterior(numero);
            double resultado = operacoes.realizarOperacao(numero, operadorAtual);

            display.setText(formatarResultado(resultado)); 
            
            operacoes.setOperadorAnterior(operadorAtual);

            operadorAtual = text;
            operadorLabel.setText(formatarResultado(numero) + " " + operadorAtual);
            novoNumero = true;
        }
    }

    private String formatarResultado(double resultado) {
        if (resultado == (int) resultado) {
            return String.valueOf((int) resultado);
        } else {
            return String.valueOf(resultado);
        }
    }

    public static void main(String[] args) {
        new Calculadora();
    }
}
