package org.example;

public class Chefe extends Empregado {

    private double salarioMensal;
    Chefe(String nome, String endereco, double salario, double salarioMensal) {
        super(nome, endereco);
        this.salarioMensal = salarioMensal;
    }

    @Override
    double calcularSalario() {
        return salarioMensal;
    }
}
