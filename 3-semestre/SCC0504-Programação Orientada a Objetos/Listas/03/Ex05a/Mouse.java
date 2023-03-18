public class Mouse implements Dispositivo {
  private int status = 0;
  private int calibracao = 0;

  // Constructor
  public Mouse() {
    this.status = 0;
    this.calibracao = 0;
  }

  public void setStatus(int status) {
    System.out.println("Mouse: setStatus(" + status + ")");
    this.status = status;
  }

  public int getStatus() {
    System.out.println("Mouse: getStatus() : " + status);;
    return this.status;
  }

  public void calibrar(int calibracao) {
    System.out.println("Mouse: calibrar(" + calibracao + ")");
    this.calibracao = calibracao;
  }
}