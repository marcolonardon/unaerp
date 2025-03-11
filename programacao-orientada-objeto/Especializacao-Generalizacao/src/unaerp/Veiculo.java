package unaerp;

public class Veiculo {
    private String placa;
    private int ano;

    public Veiculo(String placa, int ano){
        this.placa = placa;
        this.ano = ano;
    }


    public void exibirDados(){
        System.out.println("Ano: "+this.ano);
        System.out.println("Placa: "+this.placa);
    }
    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }





}
