import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculadoraScreen extends JFrame implements ActionListener {
    private final JTextField display = new JTextField();
    private int num1 = 0;
    private String operador = "";
    CalculadoraScreen() {
        String[] textosBotoes = {"7","8","9","/","4","5","6","*","1","2","3","-","0","C","=","+"};
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setSize(400, 600);
        setVisible(true);
        setTitle("Calculadora");

        display.setEditable(false);
        display.setHorizontalAlignment(JTextField.RIGHT);

        add(display, BorderLayout.NORTH);

        JPanel panel = new JPanel();
        GridLayout layout = new GridLayout(5, 3, 5, 5);
        panel.setLayout(layout);

        for(String textoBotao : textosBotoes){
            JButton botao = new JButton(textoBotao);
            botao.addActionListener(this);
            panel.add(botao);
        }

        add(panel);
        setVisible(true);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        String comando = e.getActionCommand();
        System.out.println(comando);
        if(comando.matches("[0-9]")){
            display.setText(display.getText() + comando);
        }else if(comando.matches("[/*\\-+]")){
            num1 = Integer.parseInt(display.getText());
            operador = comando;
            display.setText("");
        }else if(comando == "="){
            int num2 = Integer.parseInt(display.getText());
            int resultado = num1 + num2;
            display.setText(String.valueOf(resultado));
            switch (operador){
                case "+": resultado = num1 + num2; break;
            }

            display.setText(String.valueOf(resultado));
        }
    }
}
