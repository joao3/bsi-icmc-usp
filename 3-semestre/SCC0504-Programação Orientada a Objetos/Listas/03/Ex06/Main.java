import java.util.ArrayList;
import java.util.Collections;
class Main {
  public static void main(String[] args) {
    //String nome, int vitorias, int derrotas, int empates, int golsMarcados, 
    // int golsSofridos, int cartoesAmarelos, int cartoesVermelhos) {
    
    ArrayList<TimeFutebol> times = new ArrayList<TimeFutebol>();

    times.add(new TimeFutebol("São Paulo"  , 3, 0, 0, 0, 0, 0, 0));
    times.add(new TimeFutebol("Palmeiras"  , 4, 0, 0, 0, 0, 0, 0));
    times.add(new TimeFutebol("Santos"     , 4, 1, 2, 1, 0, 0, 0));
    times.add(new TimeFutebol("Corinthians", 4, 1, 2, 5, 0, 0, 0));
    times.add(new TimeFutebol("Flamengo"   , 4, 1, 2, 5, 6, 0, 0));
    times.add(new TimeFutebol("Fluminense" , 4, 1, 2, 5, 6, 7, 0));
    times.add(new TimeFutebol("Botafogo"   , 4, 1, 2, 5, 6, 7, 8));
    times.add(new TimeFutebol("Vasco"      , 4, 1, 2, 5, 6, 7, 8));

    // sort times
    Collections.sort(times);
    // reverse t
    Collections.reverse(times);

    for(TimeFutebol time : times) {
      System.out.println(time.getNome() + " - " + time.getPontos());
    }
  }

}