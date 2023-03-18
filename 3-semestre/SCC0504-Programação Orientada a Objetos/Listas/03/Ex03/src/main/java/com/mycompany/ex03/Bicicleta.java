package com.mycompany.ex03;

public class Bicicleta implements PegadaDeCarbono {
    private int aro;
    private String cor;

    public Bicicleta(int aro, String cor) {
        this.aro = aro;
        this.cor = cor;
    }

    public int getAro() {
        return aro;
    }

    public void setAro(int aro) {
        this.aro = aro;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }
    
    public void pedalar() {
        System.out.println("Pedalando...");
    }
    
    public int getPegadaDeCarbono() {
        return 10;
    }
}
