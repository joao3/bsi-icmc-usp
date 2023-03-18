public class OperacoesFactory {
    public static OperacoesMeusVetores getOperacao(String descricao) {
        switch (descricao) {
            case "uniao":
                return new Uniao();
            case "interseccao":
                return new Interseccao();
            case "diferenca":
                return new Diferenca();
        }

        throw new IllegalArgumentException("operacao desconhecida");
    }
}
