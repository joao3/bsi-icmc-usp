interface Dispositivo {
  int status=0;
  int calibracao=0;

  public void setStatus(int status); // ligado ou desligado
  public int getStatus();
  public void calibrar(int calibracao); // qual valor a ser calibrado
}