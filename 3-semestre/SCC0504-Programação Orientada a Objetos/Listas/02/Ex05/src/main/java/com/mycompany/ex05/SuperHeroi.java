package com.mycompany.ex05;

import java.util.ArrayList;

public class SuperHeroi extends Personagem {
    public SuperHeroi(String nome, String nomeVidaReal, double vida, ArrayList<SuperPoder> poderes) {
        this.nome = nome;
        this.nomeVidaReal = nomeVidaReal;
        this.vida = vida;
        this.poderes = poderes;
    }
}