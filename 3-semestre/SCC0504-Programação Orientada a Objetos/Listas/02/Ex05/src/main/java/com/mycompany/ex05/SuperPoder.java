package com.mycompany.ex05;

public class SuperPoder {
    private int categoria;
    private String nome;
    private double intensidade;
    
    public SuperPoder(int categoria, String nome, double intensidade) {
        this.categoria = categoria;
        this.nome = nome;
        this.intensidade = intensidade;
    }

    public int getCategoria() {
        return categoria;
    }

    public void setCategoria(int categoria) {
        this.categoria = categoria;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getIntensidade() {
        return intensidade;
    }

    public void setIntensidade(double intensidade) {
        this.intensidade = intensidade;
    }
    
}
