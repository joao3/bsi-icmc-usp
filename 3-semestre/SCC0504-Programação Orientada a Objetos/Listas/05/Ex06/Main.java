import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Main {

    public static void main(String[] args) {
        FileClass fcTemp = new FileClass();
        fcTemp.RandomAccessMethod("files/POO.dat", "muito", "pouco");
    }
}