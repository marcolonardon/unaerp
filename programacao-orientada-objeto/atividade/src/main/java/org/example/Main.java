package org.example;

public class Main {
    public static void main(String[] args) {

        Conta bruno = new Conta("Bruno", 200);
        ContaCorrente joao = new ContaCorrente("Joao", 500);
        ContaPoupanca pedro = new ContaPoupanca("Pedro", 100);

        joao.depositar(50);
        pedro.investir(500, 30);
        zerarSaldo(bruno);
        zerarSaldo(pedro);
    }

    static void zerarSaldo(Conta conta){
        conta.saldo = 0;
    }
}