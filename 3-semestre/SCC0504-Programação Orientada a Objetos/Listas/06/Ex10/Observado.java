import java.util.Observable;

public class Observado extends Observable {
    private String string;

    public String getString() {
        return string;
    }

    public void setString(String string) {
        this.string = string;
        this.setChanged();
    }
}
