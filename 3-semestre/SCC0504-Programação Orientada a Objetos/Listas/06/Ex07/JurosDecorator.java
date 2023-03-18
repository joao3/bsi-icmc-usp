public abstract class JurosDecorator implements JurosBase {
    JurosBase jurosASerDecorado;

    public JurosDecorator(JurosBase jurosASerDecorado) {
        this.jurosASerDecorado = jurosASerDecorado;
    }

    public abstract float calculaJurosTotal(Divida divida);
}
