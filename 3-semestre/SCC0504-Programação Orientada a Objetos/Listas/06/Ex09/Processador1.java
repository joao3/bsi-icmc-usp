public class Processador1 extends Processador {
    public Processador1(Processador proximo) {
        super(proximo);
    }

    @Override
    public void processa(float n) {
        if (n % 2 == 0) {
            System.out.println("Processador1");
            System.out.println(Math.pow(n, 2) + " " + Math.sqrt(n));
        } else {
            this.proximo.processa(n);
        }
    }
}
