package org.unaerp;

public class Main {
    public static void main(String[] args){
        Pessoa pessoa = new Pessoa("Nome", 2, 2, 2000);

        System.out.println("Idade = "+ pessoa.calculaIdade(18, 2, 2025));
    }
}
