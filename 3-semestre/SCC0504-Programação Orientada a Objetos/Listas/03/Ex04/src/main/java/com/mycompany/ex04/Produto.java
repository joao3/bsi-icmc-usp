package com.mycompany.ex04;

public class Produto {
    protected int codigo;
    protected float preçoUnitario;
    protected String descriçao;
    protected int qtdEstoque;

    public Produto(int codigo, float preçoUnitario, String descriçao, int qtdEstoque) {
        this.codigo = codigo;
        this.preçoUnitario = preçoUnitario;
        this.descriçao = descriçao;
        this.qtdEstoque = qtdEstoque;
    }

    public float getPreçoUnitario() {
        return preçoUnitario;
    }

    public void setPreçoUnitario(float preçoUnitario) {
        this.preçoUnitario = preçoUnitario;
    }

    public String getDescriçao() {
        return descriçao;
    }

    public void setDescriçao(String descriçao) {
        this.descriçao = descriçao;
    }

    public int getCodigo() {
        return codigo;
    }

    public int getQtdEstoque() {
        return qtdEstoque;
    }
    
    public int retirarProduto(int n) {
        if (n > qtdEstoque) {
            n = qtdEstoque;
        }
        System.out.println("Retirado " + n + " produtos");
        qtdEstoque -= n;
        return n;
    }
    
    public boolean adicionarProduto(int n) {
        qtdEstoque += n;
        System.out.println("Adicionado " + n + "produtos");
        return true;
    }
    
    public void imprimirProduto() {
        System.out.println("Produto " + codigo + ", " + descriçao + 
                ", custo de R$" + preçoUnitario + ", quantidade " + qtdEstoque);
    }
}