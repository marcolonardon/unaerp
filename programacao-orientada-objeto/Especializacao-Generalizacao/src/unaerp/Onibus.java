package unaerp;
public class Onibus extends Veiculo{
    private int assentos;

    public Onibus(String placa, int ano, int assentos){
        super(placa, ano);
        this.assentos = assentos;
    }
    public int getAssentos() {
        return assentos;
    }

    public void setAssentos(int assentos) {
        this.assentos = assentos;
    }

    @Override
    public void exibirDados(){
        System.out.println("Ano: "+this.getAno());
        System.out.println("Placa: "+this.getPlaca());
        System.out.println("Assentos: "+this.assentos);
    }


}
