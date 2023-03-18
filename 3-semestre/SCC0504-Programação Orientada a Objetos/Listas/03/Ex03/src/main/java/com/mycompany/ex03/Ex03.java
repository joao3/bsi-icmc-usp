package com.mycompany.ex03;

import java.util.ArrayList;

// Não, pois não é possível instanciar um classe abstrata.

public class Ex03 {

    public static void main(String[] args) {
        //Predio p1 = new Predio(10, 76, "Rua asdnfisa n42");
        //Predio p2 = new Predio(14, 93, "Rua yiuffu n157");
        
        Casa ca1 = new Casa("Rua slnkzxcn", 6);
        Escola e1 = new Escola("Av msdçzmc", 250, 15);
        
        Bicicleta b1 = new Bicicleta(26, "azul");
        Bicicleta b2 = new Bicicleta(29, "verde");
        
        Carro c1 = new Carro("BMW", 250);
        Carro c2 = new Carro("Ferrari", 450);
    
        ArrayList<PegadaDeCarbono> l = new ArrayList<>();
        l.add(ca1);
        l.add(e1);
        l.add(b1);
        l.add(b2);
        l.add(c1);
        l.add(c2);
        
        int totalPegadaDeCarbono = 0;
        for (PegadaDeCarbono x : l) {
            totalPegadaDeCarbono += x.getPegadaDeCarbono();
        }
        System.out.println("Pegadas de carbono: " + totalPegadaDeCarbono);
    }
}
