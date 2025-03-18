import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class EditorTexto extends JFrame {
    private JTextArea textArea;
    private JComboBox<String> fontComboBox, sizeComboBox, colorComboBox;
    private JRadioButton negrito, italico, normal, negritoItalico;
    private JButton btnAlterar, btnLimpar, btnApagar;

    public EditorTexto() {
        setTitle("Editor de Texto");
        setSize(1000, 600);             // Ajuste se quiser outro tamanho
        setLocationRelativeTo(null);   // Centraliza na tela
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Painel superior vai conter 2 "faixas" (subpainéis):
        //  1) Combos + Botões
        //  2) Botões de Rádio
        JPanel painelSuperior = new JPanel();
        painelSuperior.setLayout(new BoxLayout(painelSuperior, BoxLayout.Y_AXIS));

        // -------------------------
        // Faixa 1: Combos + Botões
        // -------------------------
        JPanel painelCombosBotoes = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 5));

        // ComboBox de fontes (10 fontes)
        painelCombosBotoes.add(new JLabel("Fonte:"));
        fontComboBox = new JComboBox<>(new String[]{
            "-Selecione-", 
            "Arial", 
            "Calibri", 
            "Comic Sans MS", 
            "Courier New", 
            "Dialog", 
            "Monospaced", 
            "Serif", 
            "Tahoma", 
            "Times New Roman", 
            "Verdana"
        });
        painelCombosBotoes.add(fontComboBox);

        // ComboBox de tamanhos (10 tamanhos)
        painelCombosBotoes.add(new JLabel("Tamanho:"));
        sizeComboBox = new JComboBox<>(new String[]{
            "-Selecione-",
            "10", "12", "14", "16", "18", 
            "20", "24", "28", "32", "36"
        });
        painelCombosBotoes.add(sizeComboBox);

        // ComboBox de cores (10 cores)
        painelCombosBotoes.add(new JLabel("Cor:"));
        colorComboBox = new JComboBox<>(new String[]{
            "-Selecione-",
            "Preto", "Vermelho", "Azul", "Verde",
            "Amarelo", "Rosa", "Laranja", "Ciano",
            "Magenta", "Cinza"
        });
        painelCombosBotoes.add(colorComboBox);

        // Botões de ação
        btnAlterar = new JButton("Alterar formatação");
        btnLimpar = new JButton("Limpar formatação");
        btnApagar = new JButton("Apagar texto");

        painelCombosBotoes.add(btnAlterar);
        painelCombosBotoes.add(btnLimpar);
        painelCombosBotoes.add(btnApagar);

        // Adiciona a faixa 1 ao painel superior
        painelSuperior.add(painelCombosBotoes);

        // -------------------------
        // Faixa 2: Botões de Rádio
        // -------------------------
        JPanel painelRadios = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 5));
        ButtonGroup grupoEstilo = new ButtonGroup();

        negrito = new JRadioButton("Negrito");
        normal = new JRadioButton("Normal", true);
        italico = new JRadioButton("Itálico");
        negritoItalico = new JRadioButton("Negrito - Itálico");

        grupoEstilo.add(negrito);
        grupoEstilo.add(normal);
        grupoEstilo.add(italico);
        grupoEstilo.add(negritoItalico);

        painelRadios.add(negrito);
        painelRadios.add(normal);
        painelRadios.add(italico);
        painelRadios.add(negritoItalico);

        // Adiciona a faixa 2 ao painel superior
        painelSuperior.add(painelRadios);

        // Adiciona o painel superior ao Frame (NORTH)
        add(painelSuperior, BorderLayout.NORTH);

        // -------------------------
        // JTextArea (CENTRO)
        // -------------------------
        textArea = new JTextArea();
        textArea.setLineWrap(true);       // Quebra de linha
        textArea.setWrapStyleWord(true);  // Quebra entre palavras
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        // -------------------------
        // Eventos dos Botões
        // -------------------------
        btnAlterar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                alterarFormatacao();
            }
        });

        btnLimpar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Volta para a formatação "original": Arial, tamanho 12, cor preta
                textArea.setFont(new Font("Arial", Font.PLAIN, 12));
                textArea.setForeground(Color.BLACK);
            }
        });

        btnApagar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Apaga todo o texto
                textArea.setText("");
            }
        });

        setVisible(true);
    }

    private void alterarFormatacao() {
        // 1) Fonte
        String fonte = (String) fontComboBox.getSelectedItem();
        if (fonte == null || fonte.equals("-Selecione-")) {
            fonte = "Arial"; // Se não escolher nada, default
        }

        // 2) Tamanho
        int tamanho = 12; // Default
        String tamanhoSelecionado = (String) sizeComboBox.getSelectedItem();
        if (tamanhoSelecionado != null && !tamanhoSelecionado.equals("-Selecione-")) {
            tamanho = Integer.parseInt(tamanhoSelecionado);
        }

        // 3) Estilo
        int estilo = Font.PLAIN;
        if (negrito.isSelected()) {
            estilo = Font.BOLD;
        } else if (italico.isSelected()) {
            estilo = Font.ITALIC;
        } else if (negritoItalico.isSelected()) {
            estilo = Font.BOLD | Font.ITALIC;
        }

        // Aplica a fonte e estilo
        textArea.setFont(new Font(fonte, estilo, tamanho));

        // 4) Cor
        String corSelecionada = (String) colorComboBox.getSelectedItem();
        if (corSelecionada == null || corSelecionada.equals("-Selecione-")) {
            textArea.setForeground(Color.BLACK);
            return;
        }
        switch (corSelecionada) {
            case "Vermelho": textArea.setForeground(Color.RED);      break;
            case "Azul":     textArea.setForeground(Color.BLUE);     break;
            case "Verde":    textArea.setForeground(Color.GREEN);    break;
            case "Amarelo":  textArea.setForeground(Color.YELLOW);   break;
            case "Rosa":     textArea.setForeground(Color.PINK);     break;
            case "Laranja":  textArea.setForeground(Color.ORANGE);   break;
            case "Ciano":    textArea.setForeground(Color.CYAN);     break;
            case "Magenta":  textArea.setForeground(Color.MAGENTA);  break;
            case "Cinza":    textArea.setForeground(Color.GRAY);     break;
            case "Preto":    textArea.setForeground(Color.BLACK);    break;
            default:         textArea.setForeground(Color.BLACK);    break;
        }
    }

    public static void main(String[] args) {
        new EditorTexto();
    }
}
