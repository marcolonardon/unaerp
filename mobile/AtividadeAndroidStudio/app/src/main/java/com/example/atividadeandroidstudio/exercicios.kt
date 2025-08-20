package com.example.atividadeadroidstudio

fun main(){
    println(informacoes("João", 30, 1.75))
    println(paresAteN(10))
    println(classificarNota(7.6))
    println(fatorial(5))
    println(tamanhoSeguro("Pipipipopopo"))

    val r: Imprimivel = Relatorio()
    println(r.imprimir())
}

fun informacoes(nome: String, idade: Int, altura: Double): String =
    "Nome: $nome, Idade: $idade, altura: $altura"

fun paresAteN(n: Int): List<Int> {
    return (0..n).filter { it % 2 == 0 }
}

fun classificarNota(nota: Double): String {
    return when {
        nota >= 6.0 -> "Aprovado"
        nota >= 4.0 -> "Recuperação"
        else -> "Reprovado"
    }
}

fun fatorial(n: Int): Long =
    if (n<=1) 1
    else n* fatorial(n-1)

fun tamanhoSeguro(texto: String?): Int {
    return texto?.length ?: 0
}

interface Imprimivel{
    fun imprimir(): String
}

class Relatorio : Imprimivel {
    override fun imprimir(): String {
        return "Gerando relatório..."
    }
}

data class Produto(val nome: String, val preco: Double) {
    fun desconto(percentual: Double): Produto {
        val novoPreco = preco - (preco * percentual / 100)
        return copy(preco = novoPreco)
    }
}

