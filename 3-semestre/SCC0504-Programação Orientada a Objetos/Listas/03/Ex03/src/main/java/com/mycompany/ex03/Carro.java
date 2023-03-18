package com.mycompany.ex03;

public class Carro implements PegadaDeCarbono {
    private boolean ligado;
    private String modelo;
    private int potenciaMotor;

    public Carro(String modelo, int potenciaMotor) {
        this.ligado = false;
        this.modelo = modelo;
        this.potenciaMotor = potenciaMotor;
    }

    public boolean isLigado() {
        return ligado;
    }

    public void setLigado(boolean ligado) {
        this.ligado = ligado;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getPotenciaMotor() {
        return potenciaMotor;
    }

    public void setPotenciaMotor(int potenciaMotor) {
        this.potenciaMotor = potenciaMotor;
    }
    
    public void ligar() {
        if (!ligado) {
            System.out.println("Carro ligado");
            ligado = true;
        } else {
            System.out.println("Carro já está ligado");
        }
    }
    
    public void andar() {
        if (!ligado) {
            System.out.println("Impossível andar, carro desligado");
        } else {
            System.out.println("Andando...");
        }
    }
    
    public int getPegadaDeCarbono() {
        return potenciaMotor * 25;
    }
}
