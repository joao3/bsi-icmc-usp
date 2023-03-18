import java.lang.Integer;
// import collections
import java.util.ArrayList;

public class TimeFutebol implements Comparable<TimeFutebol> {
  private String nome;
  private int vitorias=0;
  private int derrotas=0;
  private int empates=0;
  private int golsMarcados=0;
  private int golsSofridos=0;
  private int saldoGols=0;
  private int cartoesAmarelos=0;
  private int cartoesVermelhos=0;
  private int numeroSorteio=0;

  public TimeFutebol(String nome, int vitorias, int derrotas, int empates, int golsMarcados, int golsSofridos, int cartoesAmarelos, int cartoesVermelhos) {
    this.nome = nome;
    this.vitorias = vitorias;
    this.derrotas = derrotas;
    this.empates = empates;
    this.golsMarcados = golsMarcados;
    this.golsSofridos = golsSofridos;
    this.saldoGols = golsMarcados - golsSofridos;
    this.cartoesAmarelos = cartoesAmarelos;
    this.cartoesVermelhos = cartoesVermelhos;
  }

  public String getNome() {
    return nome;
  }

  public int getPontos() {
    return (this.vitorias * 3) + this.empates;
  }

  public int getVitorias() {
    return this.vitorias;
  }

  public int getSaldoGols() {
    return this.saldoGols;
  }

  public int getCartoesVermelhos() {
    return this.cartoesVermelhos;
  }

  public int getCartoesAmarelos() {
    return this.cartoesAmarelos;
  }

  public int getNumeroSorteio() {
    return (int) (Math.random() * 100) + 1;
  }


  public int compareTo(TimeFutebol outro) {
    int compareVitorias = Integer.compare(this.getVitorias(), outro.getVitorias());
    if(compareVitorias == 0) {
      int compareSaldoGols = Integer.compare(this.getSaldoGols(), outro.getSaldoGols());
      if(compareSaldoGols == 0) {
        int compareCartoesAmarelos = Integer.compare(this.getCartoesAmarelos(), outro.getCartoesAmarelos());
        if(compareCartoesAmarelos == 0) {
          int compareCartoesVermelhos = Integer.compare(this.getCartoesVermelhos(), outro.getCartoesVermelhos());
          if(compareCartoesVermelhos == 0) {
            int compareSorteio = Integer.compare(this.getNumeroSorteio(), outro.getNumeroSorteio());
            if(compareSorteio == 0) {
              // execute while compareSorteio == 0
              do {
                compareSorteio = Integer.compare(this.getNumeroSorteio(), outro.getNumeroSorteio());
              } while (compareSorteio == 0);

              return compareSorteio;
            }
            return compareSorteio;
          }
          return compareCartoesVermelhos * (compareCartoesVermelhos > 0 ? -1 : 1);
        }
        return compareCartoesAmarelos * (compareCartoesAmarelos > 0 ? -1 : 1);
      }
      return compareSaldoGols;
    }
    return compareVitorias;
  }
}
