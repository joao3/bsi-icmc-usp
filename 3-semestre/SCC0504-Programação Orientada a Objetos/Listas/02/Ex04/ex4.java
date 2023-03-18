public class ex4 {
    // start a main method in java
    public static void main(String[] args) {
        // create a new instance of Usuario
        Usuario usuario = new Usuario("João", 20, 123);
        // create a new instance of Operacao
        Operacao operacao = new Operacao(usuario, 1);
        
        operacao.realizaCalculo(1, 10, 2);
        operacao.realizaCalculo(2, 16, 2);
        operacao.realizaCalculo(3, 18, 2);
        operacao.realizaCalculo(4, 20, 2);
    }
}
