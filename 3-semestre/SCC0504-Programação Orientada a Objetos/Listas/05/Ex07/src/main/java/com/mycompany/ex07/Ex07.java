package com.mycompany.ex07;

public class Ex07 {

    public static void main(String[] args) {
        String dirPath = "";
        Mp3List list = new Mp3List(dirPath);
        list.readMp3s();
        list.rename();
    }
}
