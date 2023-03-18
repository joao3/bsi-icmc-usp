package com.mycompany.ex04;

import java.time.LocalDate;


public class ProdutoPerecivelEspecial extends ProdutoPerecivel {

    public ProdutoPerecivelEspecial(LocalDate dataValidade, int codigo, float preçoUnitario, String descriçao, int qtdEstoque) {
        super(dataValidade, codigo, preçoUnitario, descriçao, qtdEstoque);
    }
    
    public void imprimirProdutoPerecivel() {
        System.out.println(codigo + " " + descriçao + " " + qtdEstoque + " " + dataValidade);
    }
}
