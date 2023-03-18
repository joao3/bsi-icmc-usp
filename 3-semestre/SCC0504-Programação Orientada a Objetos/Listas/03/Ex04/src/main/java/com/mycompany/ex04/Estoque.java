package com.mycompany.ex04;

import java.util.ArrayList;

public class Estoque {
    private ArrayList<Produto> produtos;

    public Estoque() {
        produtos = new ArrayList<>();
    }
    
    public void cadastrarProduto(Produto produtoAdicionado) {
        produtos.add(produtoAdicionado);
    }
    
    public Produto buscarPorCodigo(int codigoBuscado) {
        for (Produto p : produtos) {
            if (p.getCodigo() == codigoBuscado) {
                return p;
            }
        }
        return null;
    }
    
    public void removerPorCodigo(int codigoBuscado) {
        for (int i = 0; i < produtos.size(); i++) {
            if (produtos.get(i).getCodigo() == codigoBuscado) {
                produtos.remove(i);
            }
        }
    }
    
    public float preçoTotal() {
        float total = 0;
        for (Produto p : produtos) {
            total += p.getPreçoUnitario() * p.getQtdEstoque();
        }
        return total;
    }
    
    public void descriçaoBasicaTodos() {
        for (Produto p : produtos) {
            p.imprimirProduto();
        }
    }
}
