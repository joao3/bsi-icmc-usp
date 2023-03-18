package com.mycompany.ex03;

public class Escola extends Predio {
    public String endereço;
    public int qtdAlunos;
    public int qtdProfessores;

    public Escola(String endereço, int qtdAlunos, int qtdProfessores) {
        this.endereço = endereço;
        this.qtdAlunos = qtdAlunos;
        this.qtdProfessores = qtdProfessores;
    }

    public String getEndereço() {
        return endereço;
    }

    public void setEndereço(String endereço) {
        this.endereço = endereço;
    }

    public int getQtdAlunos() {
        return qtdAlunos;
    }

    public void setQtdAlunos(int qtdAlunos) {
        this.qtdAlunos = qtdAlunos;
    }

    public int getQtdProfessores() {
        return qtdProfessores;
    }

    public void setQtdProfessores(int qtdProfessores) {
        this.qtdProfessores = qtdProfessores;
    }
        
    public float getIPTU() {
        return 4.3F * (qtdAlunos + qtdProfessores);
    }

    public int getPegadaDeCarbono() {
        return 6 * qtdAlunos + 6 * qtdProfessores;
    }
    
}
