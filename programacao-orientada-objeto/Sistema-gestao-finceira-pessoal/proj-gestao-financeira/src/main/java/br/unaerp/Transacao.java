package br.unaerp;

/*
Os usuários devem poder registrar transações financeiras, classificando-
as como receita ou despesa. Para cada transação, devem ser informados:
valor, categoria, data e descrição.
* */
public class Transacao {
    private String classificacao;
    private float valor;
    private String data;
    private String descricao;

    private String[] historico;
    Transacao(String classificacao, String data, String descricao){
        this.classificacao = classificacao;
        this.valor = 0;
        this.data = data;
        this.descricao = descricao;
        this.historico = null;
    }

    private void fezTransacao(){
        int totalTrasacoes = this.historico.length;
        historico[totalTrasacoes] = "- Categoria: "+this.classificacao+" - Data: "+this.data+" - valor: "+this.valor;
    }
    public String getClassificacao() {
        return classificacao;
    }

    public void setClassificacao(String classificacao) {
        this.classificacao = classificacao;
    }
    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
    public String[] getHistorico() {
        return historico;
    }

    public void setHistorico(String[] historico) {
        this.historico = historico;
    }
}
