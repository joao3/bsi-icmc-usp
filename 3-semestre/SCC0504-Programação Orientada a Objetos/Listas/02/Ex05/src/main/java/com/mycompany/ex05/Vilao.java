package com.mycompany.ex05;

import java.util.ArrayList;

public class Vilao extends Personagem{
    private int anosDePrisao;

    public Vilao(String nome, String nomeVidaReal, double vida, ArrayList<SuperPoder> poderes, int anosDePrisao) {
        this.nome = nome;
        this.nomeVidaReal = nomeVidaReal;
        this.vida = vida;
        this.poderes = poderes;
        this.anosDePrisao = anosDePrisao;
    }
    
    public int getAnosDePrisao() {
        return anosDePrisao;
    }

    public void setAnosDePrisao(int anosDePrisao) {
        this.anosDePrisao = anosDePrisao;
    }
}
