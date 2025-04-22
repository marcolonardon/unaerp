package org.example;

public class Comissionado extends Empregado {

    private double salarioBase;
    private double comissao;
    private int quantidade;

    Comissionado(String nome, String endereco, double salario, double salarioBase, double comissao, int quantidade) {
        super(nome, endereco);
        this.salarioBase = salarioBase;
        this.comissao = comissao;
        this.quantidade = quantidade;
    }

    @Override
    double calcularSalario() {
        return salarioBase * (comissao * quantidade);
    }
}
