package com.mycompany.ex05;

import java.util.ArrayList;

public class Personagem {
    protected String nome;
    protected String nomeVidaReal;
    protected double vida;
    public ArrayList<SuperPoder> poderes;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNomeVidaReal() {
        return nomeVidaReal;
    }

    public void setNomeVidaReal(String nomeVidaReal) {
        this.nomeVidaReal = nomeVidaReal;
    }

    public double getVida() {
        return vida;
    }

    public void setVida(double vida) {
        this.vida = vida;
    }
    
    public double getTotalPoder() {
        double totalPoder = 0;
        for (int i = 0; i < poderes.size(); i++) {
            totalPoder += this.poderes.get(i).getIntensidade();
        }
        return totalPoder;
    }
    
    public void atacar(SuperPoder poder, Personagem alvo) {
        // Ataque bem sucedido
        if (Math.random() >= 0.5) {
            alvo.vida -= poder.getIntensidade();
            System.out.println(this.nome + " atacou " + alvo.nome + ". Dano causado: " + poder.getIntensidade());
        }
    }
}
