package com.mycompany.ex07;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;

public class Mp3List {
    private ArrayList<Mp3> mp3s;
    private String dirPath;

    public Mp3List(String dirPath) {
        this.dirPath = dirPath;
        mp3s = new ArrayList<>();
    }

    public void readMp3s() {
        File dir = new File(dirPath);
        if (!dir.isDirectory()) {
            System.out.println("Nao e diretorio");
            System.exit(-1);
        }
        File[] files = dir.listFiles();
        if (files == null) {
            System.out.println("Erro");
            System.exit(-1);
        }

        for (File file : files) {
            if (file.getName().endsWith(".mp3")) {
                Mp3 mp3 = new Mp3(file.getName(), dirPath);
                mp3s.add(mp3);
            }
        }
    }

    public void rename() {
        Collections.sort(mp3s);
        for (int i = 0; i < mp3s.size(); i++) {
            Mp3 mp3 = mp3s.get(i);
            String name = mp3.getOldName();
            name = name.replace("-", "");
            for (char c = '0'; c <= '9'; c++) {
                char[] charArray= {c};
                String s = new String(charArray);
                name = name.replace(s, "");
            }
            name = name + "3"; // recoloca o 3 do "mp3" retirado acima
            String number = String.format("%05d", i);
            mp3.setNewName(number + "." + name);
            mp3.rename();
        }
    }
}
