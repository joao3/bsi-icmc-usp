package com.mycompany.ex04;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class ProdutoPerecivel extends Produto {
    protected LocalDate dataValidade;

    public ProdutoPerecivel(LocalDate dataValidade, int codigo, float preçoUnitario, String descriçao, int qtdEstoque) {
        super(codigo, preçoUnitario, descriçao, qtdEstoque);
        this.dataValidade = dataValidade;
    }
    
    public LocalDate getDataValidade() {
        return dataValidade;
    }

    public void setDataValidade(LocalDate dataValidade) {
        this.dataValidade = dataValidade;
    }
    
    public int retirarProduto(int n, LocalDate dataAtual) {
        if (dataAtual.until(dataValidade, ChronoUnit.DAYS) <= 30) {
            System.out.println("Vencimento em menos de 30 dias");
            qtdEstoque = 0;
            return 0;
        } 
        
        if (n > qtdEstoque) {
            n = qtdEstoque;
        }
        System.out.println("Retirado " + n + " produtos");
        qtdEstoque -= n;
        return n;
    }
    
    public boolean adicionarProduto(int n) {
        if (qtdEstoque == 0) {
            qtdEstoque += n;
            return true;
        }
        return false;
    }
}
