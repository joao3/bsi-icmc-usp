interface Impressora {
  int modoImpressao = 0;
  int folhasImpressas = 0;
  String marca = "";
  String modelo = "";

  public void setModoImpressao(int modoImpressao);
  public int getModoImpressao();
  public void setFolhasImpressas(int folhasImpressas);
  public int getFolhasImpressas();
  public void setMarca(String marca);
  public String getMarca();
  public void setModelo(String modelo);
  public String getModelo();
  public void imprimir(String texto);
}