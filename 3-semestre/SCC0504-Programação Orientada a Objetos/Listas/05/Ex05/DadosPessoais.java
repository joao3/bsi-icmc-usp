import java.io.Serializable;

/**
 *
 * @author Junio
 */

public class DadosPessoais implements Serializable{
    String sNome;
    int iIdade;
    String sSexo;
    Endereco eEndereco;

    DadosPessoais() {
        this.sNome = "";
        this.iIdade = 0;
        this.sSexo = "";
    }
    DadosPessoais(String nome, int idade, String sexo, Endereco endereco) {
        this.sNome = nome;
        this.iIdade = idade;
        this.sSexo = sexo;
        this.eEndereco = endereco;
    }

    public String toString() {
        return "DadosPessoais{ \n" + "\tsNome=" + sNome + "\n\tiIdade=" + iIdade + "\n\tsSexo=" + sSexo + "\n\teEndereco=" + eEndereco.toString() + "\n}";
    }
}
