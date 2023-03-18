public class BrotherL1012 implements Impressora, Dispositivo {
  private int modoImpressao;
  private int folhasImpressas;
  private String marca;
  private String modelo;
  private int status;
  private int calibracao;

  public BrotherL1012() {
    this.modoImpressao = 0;
    this.folhasImpressas = 0;
    this.marca = "Brother";
    this.modelo = "L1012";
    this.status = 0;
    this.calibracao = 0;
  }

  // Dispositivo métodos

  public void setStatus(int status) {
    System.out.println("BrotherL1012: setStatus(" + status + ")");
    this.status = status;
  }

  public int getStatus() {
    System.out.println("BrotherL1012: getStatus() : " + status);;
    return this.status;
  }

  public void calibrar(int calibracao) {
    System.out.println("BrotherL1012: calibrar(" + calibracao + ")");
    this.calibracao = calibracao;
  }

  // Impressora métodos

  public void setModoImpressao(int modoImpressao) {
    System.out.println("Impressora: setModoImpressao(" + modoImpressao + ")");
    this.modoImpressao = modoImpressao;
  }

  public int getModoImpressao() {
    System.out.println("Impressora: getModoImpressao() : " + modoImpressao);;
    return this.modoImpressao;
  }

  public void setFolhasImpressas(int folhasImpressas) {
    System.out.println("Impressora: setFolhasImpressas(" + folhasImpressas + ")");
    this.folhasImpressas = folhasImpressas;
  }

  public int getFolhasImpressas() {
    System.out.println("Impressora: getFolhasImpressas() : " + folhasImpressas);;
    return this.folhasImpressas;
  }

  public void setMarca(String marca) {
    System.out.println("Impressora: setMarca(" + marca + ")");
    this.marca = marca;
  }

  public String getMarca() {
    System.out.println("Impressora: getMarca() : " + marca);;
    return this.marca;
  }

  public void setModelo(String modelo) {
    System.out.println("Impressora: setModelo(" + modelo + ")");
    this.modelo = modelo;
  }

  public String getModelo() {
    System.out.println("Impressora: getModelo() : " + modelo);;
    return this.modelo;
  }

  public void imprimir(String texto) {
    System.out.println("Impressora: imprimir(" + texto + ")");
    this.setFolhasImpressas(this.getFolhasImpressas() + 1);
  }
}


