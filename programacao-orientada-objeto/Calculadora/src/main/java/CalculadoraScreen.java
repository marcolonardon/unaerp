import javax.swing.*;

public class CalculadoraScreen extends JFrame {
    CalculadoraScreen(){
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); //quando clicar no x, encerra o processo
        setSize(200, 200);
        setVisible(true);
        setTitle("Calculadora");

        JTextField display = new JTextField();
        display.setEditable(false);

        add(display);
    }
}
