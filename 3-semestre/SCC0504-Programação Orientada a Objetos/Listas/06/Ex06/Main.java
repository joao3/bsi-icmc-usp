import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> conjuntoA = new ArrayList<>();
        conjuntoA.add(4);
        conjuntoA.add(8);
        conjuntoA.add(21);
        conjuntoA.add(7);
        conjuntoA.add(3);

        ArrayList<Integer> conjuntoB = new ArrayList<>();
        conjuntoB.add(0);
        conjuntoB.add(12);
        conjuntoB.add(2);
        conjuntoB.add(4);
        conjuntoB.add(9);
        conjuntoB.add(7);
        conjuntoB.add(34);

        MeusVetores meusVetores = new MeusVetores(conjuntoA, conjuntoB);

        /*
        meusVetores.fazAlgumaOperacao(new Uniao());
        meusVetores.fazAlgumaOperacao(new Interseccao());
        meusVetores.fazAlgumaOperacao(new Diferenca());
        */

        meusVetores.fazAlgumaOperacao(OperacoesFactory.getOperacao("uniao"));
        meusVetores.fazAlgumaOperacao(OperacoesFactory.getOperacao("interseccao"));
        meusVetores.fazAlgumaOperacao(OperacoesFactory.getOperacao("diferenca"));
    }
}
