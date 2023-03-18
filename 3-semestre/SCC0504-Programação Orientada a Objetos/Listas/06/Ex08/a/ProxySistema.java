
import java.util.*;

public class ProxySistema {
  Sistema sSistema;

  ProxySistema() {
    this.sSistema = new Sistema();
  }

  public void enviaDados(String s) {
    if (s.contains("789"))
      System.out.println("ERRO: tentativa de execucao de codigo malicioso");
    else
      sSistema.enviaDados(s);
  }

  public void enviaArray(String[] i) {
    // find if x has 789 on array
    if (Arrays.stream(i).filter(x -> x.contains("789")).count() > 0) {
      System.out.println("ERRO: tentativa de execucao de codigo malicioso");
    } else
      sSistema.enviaArray(i);
  }
}
