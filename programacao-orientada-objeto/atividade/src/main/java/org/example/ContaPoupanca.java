package org.example;

public class ContaPoupanca extends Conta{
    ContaPoupanca(String nome, float saldo) {
        super(nome, saldo);
    }

    public void investir(float valor, int dias){
        float investido = valor * 0.05f * dias;
        this.saldo += investido;

    }
}
