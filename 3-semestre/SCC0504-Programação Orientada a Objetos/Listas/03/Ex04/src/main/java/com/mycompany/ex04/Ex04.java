package com.mycompany.ex04;

import java.time.LocalDate;

public class Ex04 {
    public static void main(String[] args) {
        ProdutoPerecivel banana = new ProdutoPerecivel(LocalDate.of(2022, 04, 7),
                0, 3.2F, "Banana", 10);
        ProdutoPerecivelEspecial uva = new ProdutoPerecivelEspecial(LocalDate.of(2022, 05, 21),
                1, 0.4F, "Uva", 50);
        ProdutoNaoPerecivel arroz = new ProdutoNaoPerecivel(1, 2, 20F, "Arroz", 5);
        
        Estoque estoque = new Estoque();
        
        estoque.cadastrarProduto(banana);
        estoque.cadastrarProduto(uva);
        estoque.cadastrarProduto(arroz);
        
        estoque.buscarPorCodigo(1).imprimirProduto();
                
        System.out.println(estoque.preçoTotal());
        
        estoque.descriçaoBasicaTodos();
    }
}
