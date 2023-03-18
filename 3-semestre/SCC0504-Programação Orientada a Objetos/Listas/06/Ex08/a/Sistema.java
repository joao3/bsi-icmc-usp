
import java.util.*;

public class Sistema {


  public void enviaDados(String s){
    if(s.contains("789"))
        System.out.println("FALHA DE SEGURANCA: valor malicioso.");
    else
        System.out.println("Acesso normal ao sistema.");
  }

  public void enviaArray(String[] i){
      // find if x has "789" on array
      if(Arrays.stream(i).filter(x-> x.contains("789")).count() > 0) {
        System.out.println("FALHA DE SEGURANCA: valor malicioso.");
      }
      else
          System.out.println("Acesso normal ao sistema.");
  }
}
