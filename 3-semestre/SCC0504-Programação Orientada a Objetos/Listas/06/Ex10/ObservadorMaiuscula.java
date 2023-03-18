import java.util.Observable;
import java.util.Observer;

public class ObservadorMaiuscula implements Observer {

    @Override
    public void update(Observable o, Object arg) {
        Observado observado = (Observado) o;
        System.out.println(observado.getString().toUpperCase());
    }
}
