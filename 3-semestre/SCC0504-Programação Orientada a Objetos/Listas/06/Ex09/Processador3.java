public class Processador3 extends Processador {
    public Processador3(Processador proximo) {
        super(proximo);
    }

    @Override
    public void processa(float n) {
        if (!(n % 2 == 0) && !(n % 3 == 0)) {
            System.out.println("Processador3");
            System.out.println(Math.pow(n, 2) + " " + Math.sqrt(n));
        } else {
            this.proximo.processa(n);
        }
    }
}
