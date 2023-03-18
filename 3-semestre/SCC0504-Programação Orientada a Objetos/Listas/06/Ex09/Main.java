public class Main {
    public static void main(String[] args) {
        Processador p = new Processador1(new Processador2(new Processador3(null)));
        p.processa(8);
        p.processa(15);
        p.processa(29);
    }
}
