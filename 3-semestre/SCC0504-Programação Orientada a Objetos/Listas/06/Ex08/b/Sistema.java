import java.util.*;

public class Sistema extends SistemaDecorator {
  
  Sistema(FilteredSistema fsASerDecorado) {
    super(fsASerDecorado);
  }
  public void enviaDados(String s){
    String input = fsASerDecorado.lerDados(s); // é definido no SistemaDecorator

    if(input.contains("789"))
        System.out.println("FALHA DE SEGURANCA: valor malicioso.");
    else
        System.out.println("Acesso normal ao sistema.");
  }

  public void enviaArray(String[] i){
      String[] input = fsASerDecorado.lerArray(i);  // é definido no SistemaDecorator

      if(Arrays.stream(input).filter(x-> x.contains("789")).count() > 0) {
        System.out.println("FALHA DE SEGURANCA: valor malicioso.");
      }
      else
          System.out.println("Acesso normal ao sistema.");
  }
}
