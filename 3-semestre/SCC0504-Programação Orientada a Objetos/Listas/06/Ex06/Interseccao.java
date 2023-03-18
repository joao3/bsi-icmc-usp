import java.util.ArrayList;

public class Interseccao implements OperacoesMeusVetores {

    @Override
    public void fazOperacao(MeusVetores vetores) {
        ArrayList<Integer> conjuntoA = vetores.getConjuntoA();
        ArrayList<Integer> conjuntoB = vetores.getConjuntoB();
        ArrayList<Integer> resultado = new ArrayList<>();

        for (Integer n : conjuntoA) {
            if (conjuntoB.contains(n)) {
                resultado.add(n);
            }
        }

        System.out.println("Interseccao");
        for (Integer n : resultado) {
            System.out.print(n + " ");
        }
        System.out.println("\n--------------------");
    }
}
