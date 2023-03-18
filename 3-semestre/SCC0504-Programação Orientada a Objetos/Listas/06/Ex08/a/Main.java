public class Main {
    public static void main(String[] args) {
        ProxySistema proxy = new ProxySistema();
        Sistema sistema = new Sistema();

        proxy.enviaDados("1234567890");
        sistema.enviaDados("1234567890");

        String invalidArray[] = {"0", "1", "789"};
        proxy.enviaArray(invalidArray);

        String validArray[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
        proxy.enviaArray(validArray);
    }
}