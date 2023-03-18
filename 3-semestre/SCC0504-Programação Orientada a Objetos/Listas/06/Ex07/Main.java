import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Divida divida = new Divida(100);

        Juros juros = new Juros(5);
        JurosDesconto jurosDesconto = new JurosDesconto(juros, 10);
        JurosDescontoAcrescimo jurosDescontoAcrescimo = new JurosDescontoAcrescimo(jurosDesconto, 20);

        ArrayList<JurosBase> jurosList = new ArrayList<>();
        jurosList.add(juros);
        jurosList.add(jurosDesconto);
        jurosList.add(jurosDescontoAcrescimo);

        for (JurosBase j : jurosList) {
            System.out.println(j.calculaJurosTotal(divida));
        }
    }
}
