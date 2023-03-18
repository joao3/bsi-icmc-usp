package com.mycompany.ex05;

import java.util.ArrayList;

public class Ex05 {

    public static void main(String[] args) {
        SuperPoder batmanBasico = new SuperPoder(0, "Ataque Básico", 7.5);
        SuperPoder batmanEspecial = new SuperPoder(1, "Ataque Especial", 25);
        ArrayList<SuperPoder> poderesBatman = new ArrayList<>();
        poderesBatman.add(batmanBasico);
        poderesBatman.add(batmanEspecial);
        SuperHeroi batman = new SuperHeroi("Batman", "Bruce Wayne", 100, poderesBatman);
        
        SuperPoder coringaBasico = new SuperPoder(0, "Ataque Básico", 5);
        SuperPoder coringaEspecial = new SuperPoder(1, "Ataque Especial", 20);
        ArrayList<SuperPoder> poderesCoringa = new ArrayList<>();
        poderesCoringa.add(coringaBasico);
        poderesCoringa.add(coringaEspecial);
        Vilao coringa = new Vilao("Coringa", "Jack", 120, poderesCoringa, 20);
        
        
        while (batman.getVida() > 0 && coringa.getVida() > 0) {
            System.out.println("Vida " + batman.getNome() + ": " + batman.getVida());
            System.out.println("Vida " + coringa.getNome() + ": " + coringa.getVida());
            
            // Ataque batman
            // 10% de chance de atacar com ataque especial
            if (Math.random() >= 0.9) {
                batman.atacar(batman.poderes.get(1), coringa);
            } else {
                batman.atacar(batman.poderes.get(0), coringa);
            }
            
            // Ataque coringa
            // 10% de chance de atacar com ataque especial
            if (Math.random() >= 0.9) {
                coringa.atacar(coringa.poderes.get(1), batman);
            } else {
                coringa.atacar(coringa.poderes.get(0), batman);
            }
        
            System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        }
        System.out.println("Vida " + batman.getNome() + ": " + batman.getVida());
        System.out.println("Vida " + coringa.getNome() + ": " + coringa.getVida());
    }
}
