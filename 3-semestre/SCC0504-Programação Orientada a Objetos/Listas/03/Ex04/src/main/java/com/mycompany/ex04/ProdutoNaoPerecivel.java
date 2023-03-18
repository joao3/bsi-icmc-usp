package com.mycompany.ex04;

public class ProdutoNaoPerecivel extends Produto {
    protected int anosDeGarantia; 

    public ProdutoNaoPerecivel(int anosDeGarantia, int codigo, float preçoUnitario, String descriçao, int qtdEstoque) {
        super(codigo, preçoUnitario, descriçao, qtdEstoque);
        this.anosDeGarantia = anosDeGarantia;
    }

    public int getAnosDeGarantia() {
        return anosDeGarantia;
    }
}
