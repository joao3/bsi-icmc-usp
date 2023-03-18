public class Juros extends JurosDecorator {
    private float porcentagemJuros;

    public Juros(float porcentagemJuros) {
        super(null);
        this.porcentagemJuros = porcentagemJuros;
    }

    @Override
    public float calculaJurosTotal(Divida divida) {
        return divida.getDividaTotal() * (porcentagemJuros / 100);
    }
}
