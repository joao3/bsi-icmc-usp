package com.mycompany.ex03;

public class Casa extends Predio {
    private String endereço;
    private int qtdMoradores;

    public Casa(String endereço, int qtdMoradores) {
        this.endereço = endereço;
        this.qtdMoradores = qtdMoradores;
    }

    public String getEndereço() {
        return endereço;
    }

    public void setEndereço(String endereço) {
        this.endereço = endereço;
    }

    public int getQtdMoradores() {
        return qtdMoradores;
    }

    public void setQtdMoradores(int qtdMoradores) {
        this.qtdMoradores = qtdMoradores;
    }
    

    public float getIPTU() {
        return 7.6F * qtdMoradores;
    }

    public int getPegadaDeCarbono() {
        return 9 * qtdMoradores;
    }
}
