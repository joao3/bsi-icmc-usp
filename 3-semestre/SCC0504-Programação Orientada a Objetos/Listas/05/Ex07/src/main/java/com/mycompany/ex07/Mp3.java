package com.mycompany.ex07;

import java.io.File;

public class Mp3 implements Comparable {
    private int pos;
    private String dirPath;
    private String oldName;
    private String newName;
    private File file;

    public Mp3(String oldName, String path) {
        this.oldName = oldName;
        this.dirPath = path;
        file = new File(path + "\\" + oldName);
    }

    public boolean rename() {
        File newFile = new File(dirPath + "\\" + newName);
        return file.renameTo(newFile);
    }

    @Override
    public int compareTo(Object o) {
        if (this.file.length() > ((Mp3) o).file.length())
            return 1;
        else if (this.file.length() < ((Mp3) o).file.length())
            return -1;
        return 0;
    }

    public void setNewName(String newName) {
        this.newName = newName;
    }

    public String getOldName() {
        return oldName;
    }
}
