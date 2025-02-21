package org.unaerp;

public class Conta {
    private int id;
    private String nome;
    private float saldo;

    public float getSaldo() {
        return this.saldo;
    }
    Conta(int id, String nome){
        this.id = id;
        this.nome = nome;
        this.saldo = 0;
    }

    void depositar(float valor){
        this.saldo += valor;
    }

    public void setNome(String novoNome){
        this.nome = novoNome;
    }
    void sacar(float valor){
        if(this.saldo < valor){
            System.out.println("saldo insuficiente.");
            return;
        }
        this.saldo -= valor;
    }

    void transferir(Conta contaPara, float valor){
        if(this.saldo < valor){
            System.out.println("saldo insuficiente.");
            return;
        }

        this.sacar(valor);
        contaPara.depositar(valor);
    }
}
