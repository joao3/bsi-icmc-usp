import java.util.Calendar;
import java.util.Observable;
import java.util.Observer;

public class ObservadorAno implements Observer {

    @Override
    public void update(Observable o, Object arg) {
        Observado observado = (Observado) o;

        Calendar cal = Calendar.getInstance();
        int year = cal.get(Calendar.YEAR);

        System.out.println(observado.getString() + year);
    }
}
