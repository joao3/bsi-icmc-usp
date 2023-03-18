public class JurosDescontoAcrescimo extends JurosDecorator {
    private float taxa;

    public JurosDescontoAcrescimo(JurosDesconto jurosASerDecorado, float taxa) {
        super(jurosASerDecorado);
        this.taxa = taxa;
    }

    @Override
    public float calculaJurosTotal(Divida divida) {
        return jurosASerDecorado.calculaJurosTotal(divida) + taxa;
    }
}
