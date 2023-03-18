import java.time.LocalDate;

public class Operacao {
  private Usuario usuario;
  private int tipo;
  private LocalDate data;

  public Operacao(Usuario usuario, int tipo) {
    LocalDate data = LocalDate.now();
    this.usuario = usuario;
    this.tipo = tipo;
    this.data = data;
  }

  public Usuario getUsuario() {
    return usuario;
  }

  public int getTipo() {
    return tipo;
  }

  public LocalDate getData() {
    return data;
  }

  public void realizaCalculo(int identificador, float valor1, float valor2) {
    Calculo calculo = new Calculo();
    float resultado = 0;

    switch (identificador) {
      case 1:
        resultado = calculo.Soma(valor1, valor2);
      case 2:
        resultado = calculo.Subtracao(valor1, valor2);
      case 3:
        resultado = calculo.Produto(valor1, valor2);
      case 4:
        resultado = calculo.Coeficiente(valor1, valor2);
    }

    System.out.println("Tipo: " + identificador + " Usuario: " + usuario.getNome() + " Data: " + this.data + " Resultado: " + resultado);
    // print the result to 2 decimal places

    
  }
}