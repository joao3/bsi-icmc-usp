public class Main {
    public static void main(String[] args) {
        FilteredSistema fs = new FilteredSistema();
        Sistema sistema = new Sistema(fs);

        sistema.enviaDados("1234567890");

        String wasInvalidArray[] = {"0", "1", "789"};
        
        sistema.enviaArray(wasInvalidArray);
    }
}