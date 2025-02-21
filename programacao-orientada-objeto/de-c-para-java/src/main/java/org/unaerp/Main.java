package org.unaerp;

//public class Main {
//    public static void main(String[] args){
//        Pessoa pessoa = new Pessoa("Nome", 2, 2, 2000);
//
//        System.out.println("Idade = "+ pessoa.calculaIdade(18, 2, 2025));
//    }
//}

public class Main {
    public static void main(String[] args){
        Conta bruno = new Conta(1, "Bruno");
        Conta jose = new Conta (2, "Jose");

        bruno.depositar(1200);
        jose.depositar(500);
        bruno.sacar(200);
        jose.depositar(300);
        bruno.transferir(jose, 100);

        System.out.println("Saldo Bruno "+bruno.getSaldo());
        System.out.println("Saldo Jose "+jose.getSaldo());
    }
}