public abstract class Processador {
    protected Processador proximo;

    public Processador(Processador proximo) {
        this.proximo = proximo;
    }

    public abstract void processa(float n);
}
