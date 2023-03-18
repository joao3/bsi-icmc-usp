package com.mycompany.ex08;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;

public class MeuLineNumberReader extends BufferedReader {
    private static int lineCount;

    public MeuLineNumberReader(Reader in) {
        super(in);
        lineCount = 1;
    }

    @Override
    public String readLine() throws IOException {
        String line = super.readLine();
        if (line == null)
            return null;
        return lineCount++ + ". " + line;
    }
}
