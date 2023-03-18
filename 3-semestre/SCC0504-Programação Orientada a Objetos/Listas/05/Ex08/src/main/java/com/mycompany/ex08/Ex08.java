package com.mycompany.ex08;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Ex08 {

    public static void main(String[] args) {
        try {
            String fileName = "";
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            MeuLineNumberReader meuReader = new MeuLineNumberReader(reader);
            while (true) {
                String line = meuReader.readLine();
                if (line == null)
                    break;
                System.out.println(line);
            }
        } catch (IOException ex) {
            System.out.println("Arquivo não existe");
            System.exit(-1);
        }
    }
}
