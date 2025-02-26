package unaerp;

public class Conta {
    private static int proxId;
    private int id;
    private String nome;
    private float saldo;


    public void Depositar(int valor){

    }

    public void Sacar(int valor){

    }



    public static int getProxId() {
        return proxId;
    }

    public static void setProxId(int proxId) {
        Conta.proxId = proxId;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }
}
