package org.example;

public class ContaCorrente extends Conta{
    ContaCorrente(String nome, float saldo) {
        super(nome, saldo);
    }

    public void transferir(ContaCorrente contaPara, float valor){
        this.saldo -= valor;
        contaPara.saldo += valor;
    }
}
