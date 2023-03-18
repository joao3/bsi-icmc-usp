import java.util.ArrayList;

public class Uniao implements OperacoesMeusVetores {

    @Override
    public void fazOperacao(MeusVetores vetores) {
        ArrayList<Integer> conjuntoA = vetores.getConjuntoA();
        ArrayList<Integer> conjuntoB = vetores.getConjuntoB();
        ArrayList<Integer> resultado = new ArrayList<>(conjuntoA);
        for (Integer n : conjuntoB) {
            if (!resultado.contains(n)) {
                resultado.add(n);
            }
        }

        System.out.println("Uniao");
        for (Integer n : resultado) {
            System.out.print(n + " ");
        }
        System.out.println("\n--------------------");
    }

}