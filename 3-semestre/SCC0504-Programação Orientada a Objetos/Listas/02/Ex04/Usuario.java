// create class usuario in java

public class Usuario {
  private String nome;
  private int idade;
  private long CPF;

  public Usuario(String nome, int idade, long CPF) {
    this.nome = nome;
    this.idade = idade;
    this.CPF = CPF;
  }

  public String getNome() {
    return nome;
  }

  public int getIdade() {
    return idade;
  }

  public long getCPF() {
    return CPF;
  }
}