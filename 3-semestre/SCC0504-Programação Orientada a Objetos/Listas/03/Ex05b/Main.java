class Main {
  public static void main(String[] args) {
    BrotherL1012 brotherL1012 = new BrotherL1012();  // instancia um objeto da classe BrotherL1012 que utiliza a interface Impressora e Dispositivo

    brotherL1012.setStatus(1);        // seta o status do brotherL1012 para ligado
    brotherL1012.calibrar(10);        // seta a calibracao do brotherL1012 para 10

    brotherL1012.setModoImpressao(1); // seta o modo de impressao do brotherL1012 para modo 1
    brotherL1012.setFolhasImpressas(10); // seta o numero de folhas impressas do brotherL1012 para 10
    brotherL1012.imprimir("Olá Eduardo");

    brotherL1012.getFolhasImpressas(); // imprime o numero de folhas impressas do brotherL1012
  }
}