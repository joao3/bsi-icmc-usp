public class Processador2 extends Processador {
    public Processador2(Processador proximo) {
        super(proximo);
    }

    @Override
    public void processa(float n) {
        if (n % 3 == 0) {
            System.out.println("Processador2");
            System.out.println(Math.pow(n, 2) + " " + Math.sqrt(n));
        } else {
            this.proximo.processa(n);
        }
    }
}
