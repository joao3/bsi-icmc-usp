import java.util.ArrayList;

public class MeusVetores {
    private ArrayList<Integer> conjuntoA;
    private ArrayList<Integer> conjuntoB;

    public MeusVetores(ArrayList<Integer> conjuntoA, ArrayList<Integer> conjuntoB) {
        this.conjuntoA = conjuntoA;
        this.conjuntoB = conjuntoB;
    }

    public ArrayList<Integer> getConjuntoA() {
        return conjuntoA;
    }

    public ArrayList<Integer> getConjuntoB() {
        return conjuntoB;
    }

    public void fazAlgumaOperacao(OperacoesMeusVetores operacao) {
        operacao.fazOperacao(this);
    }
}