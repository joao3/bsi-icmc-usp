import java.util.Observable;

public class Main {
    public static void main(String[] args) {
        Observado o = new Observado();

        ObservadorMaiuscula om = new ObservadorMaiuscula();
        ObservadorAno oa = new ObservadorAno();
        ObservadorTamanho ot = new ObservadorTamanho();

        o.addObserver(ot);
        o.addObserver(oa);
        o.addObserver(om);

        o.setString("nsdodsfs");
        o.notifyObservers(o);
        System.out.println();
        o.setString("ewqopke");
        o.notifyObservers(o);
    }
}
