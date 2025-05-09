import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;

public class FormularioClientes extends JFrame {
    private JTextField txtNome, txtEmail;
    private JTextArea areaClientes;
    private List<Cliente> clientes = new ArrayList<>();
    public FormularioClientes() {
        setTitle("Cadastro de Clientes");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(400, 300);
        setLayout(new BorderLayout());

        // Painel do formulário
        JPanel painelForm = new JPanel(new GridLayout(3, 2));
        painelForm.add(new JLabel("Nome:"));
        txtNome = new JTextField();
        painelForm.add(txtNome);
        painelForm.add(new JLabel("Email:"));
        txtEmail = new JTextField();
        painelForm.add(txtEmail);

        JButton btnSalvar = new JButton("Salvar");
        painelForm.add(btnSalvar);

        add(painelForm, BorderLayout.NORTH);

        // Área para exibir clientes
        areaClientes = new JTextArea();
        areaClientes.setEditable(false);
        add(new JScrollPane(areaClientes), BorderLayout.CENTER);

        // Ação do botão
        btnSalvar.addActionListener(e -> salvarCliente());

        setVisible(true);
    }

    private void salvarCliente() {
        try {
            String nome = txtNome.getText().trim();
            String email = txtEmail.getText().trim();

            if (nome.isEmpty() || email.isEmpty()) {
                throw new IllegalArgumentException("Preencha todos os campos.");
            }

            Cliente cliente = new Cliente(nome, email);
            clientes.add(cliente);

            atualizarLista();
            limparCampos();

            SessionFactory factory = new Configuration().configure().buildSessionFactory();
            Session session = factory.openSession();

            Cliente cliente1 = new Cliente();
            cliente1.setNome("Maria");

            Transaction tx = session.beginTransaction();
            session.save(cliente1);
            tx.commit();

            session.close();

        } catch (IllegalArgumentException ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage(), "Aviso", JOptionPane.WARNING_MESSAGE);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Erro: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void atualizarLista() {
        StringBuilder sb = new StringBuilder();
        for (Cliente c : clientes) {
            sb.append(c).append("\n");
        }
        areaClientes.setText(sb.toString());
    }

    private void limparCampos() {
        txtNome.setText("");
        txtEmail.setText("");
        txtNome.requestFocus();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(FormularioClientes::new);
    }
}
