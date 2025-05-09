import jakarta.persistence.*;

@Entity
@Table(name = "cliente")
class Cliente {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private String nome;
    private String email;

    public Cliente() {}

    public Cliente(String nome, String email) {
        this.nome = nome;
        this.email = email;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String toString() {
        return nome + " (" + email + ")";
    }
}
