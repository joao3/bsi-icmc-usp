package com.mycompany.ex03;

/*
public class Predio implements PegadaDeCarbono {
    private int qtdAndares;
    private int qtdMoradores;
    private String endereço;

    public Predio(int qtdAndares, int qtdMoradores, String endereço) {
        this.qtdAndares = qtdAndares;
        this.qtdMoradores = qtdMoradores;
        this.endereço = endereço;
    }

    public int getQtdAndares() {
        return qtdAndares;
    }

    public void setQtdAndares(int qtdAndares) {
        this.qtdAndares = qtdAndares;
    }

    public int getQtdMoradores() {
        return qtdMoradores;
    }

    public void setQtdMoradores(int qtdMoradores) {
        this.qtdMoradores = qtdMoradores;
    }

    public String getEndereço() {
        return endereço;
    }

    public void setEndereço(String endereço) {
        this.endereço = endereço;
    }
    
    public void adicionarMorador() {
        qtdMoradores++;
    }
    
    public void removerMorador() {
        if (qtdMoradores > 0) {
            qtdMoradores--;
        }
    }

    public float getIPTU() {
        return qtdMoradores * 100;
    }
    
    public int getPegadaDeCarbono() {
        return 10 * qtdMoradores;
    }
}
*/

public abstract class Predio implements PegadaDeCarbono {
    public abstract float getIPTU();
    public abstract int getPegadaDeCarbono();
}