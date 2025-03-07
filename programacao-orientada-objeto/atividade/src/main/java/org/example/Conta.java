package org.example;

public class Conta {
    private static int proxId = 0;
    protected int id;
    protected String nome;
    protected float saldo;

    Conta(String nome, float saldo){
        this.nome = nome;
        this.saldo = saldo;
        this.id = proxId++;
    }

    public void depositar(float valor){
        this.saldo+=valor;
    }

    public void sacar(float valor){
        this.saldo -= valor;
    }
}
