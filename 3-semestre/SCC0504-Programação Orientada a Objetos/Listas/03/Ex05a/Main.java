class Main {
  public static void main(String[] args) {
    Mouse mouse = new Mouse();  // instancia um objeto da classe Mouse que utiliza a interface Dispositivo    
    mouse.setStatus(1);        // seta o status do mouse para ligado
    mouse.calibrar(10);        // seta a calibracao do mouse para 10
    System.out.println(mouse.getStatus()); // imprime o status do mouse
  }
}