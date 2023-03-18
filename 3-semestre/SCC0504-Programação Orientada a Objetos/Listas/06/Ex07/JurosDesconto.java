public class JurosDesconto extends JurosDecorator {
    private float desconto;

    public JurosDesconto(Juros jurosASerDecorado, float desconto) {
        super(jurosASerDecorado);
        this.desconto = desconto;
    }

    @Override
    public float calculaJurosTotal(Divida divida) {
        return jurosASerDecorado.calculaJurosTotal(divida) - desconto;
    }
}
