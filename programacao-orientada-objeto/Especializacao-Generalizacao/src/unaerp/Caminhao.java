package unaerp;

public class Caminhao extends Veiculo{

    private int eixos;

    public Caminhao(String placa, int ano, int eixos) {
        super(placa, ano);
        this.eixos = eixos;
    }

    public int getEixos() {
        return eixos;
    }

    public void setEixos(int eixos) {
        this.eixos = eixos;
    }
    @Override
    public void exibirDados(){
        System.out.println("Ano: "+this.getAno());
        System.out.println("Placa: "+this.getPlaca());
        System.out.println("Eixos: "+this.eixos);
    }
}
