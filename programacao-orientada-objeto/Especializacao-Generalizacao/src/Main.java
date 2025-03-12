import unaerp.Caminhao;
import unaerp.Onibus;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Onibus busao = new Onibus("abc", 2000, 22);
        Caminhao carretaFuracao = new Caminhao("def", 2022, 12);

        busao.exibirDados();
        carretaFuracao.exibirDados();
    }
}