package org.unaerp;

public class Pessoa {
    String nome;
    int dia, mes, ano;

    Pessoa(String nome, int dia, int mes, int ano){
        this.nome = nome;
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    int calculaIdade(int diaAtual, int mesAtual, int anoAtual){
        int idade = anoAtual - this.ano - 1;
        if(mesAtual > this.mes || (mesAtual == this.mes && diaAtual >= this.dia)) {
            idade++;
        }
        return idade;
    }
}
