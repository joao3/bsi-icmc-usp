import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.RandomAccessFile;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.zip.GZIPOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class FileClass {

    public void RandomAccessMethod(String sAFile, String oldWord, String newWord) {
        try {
            File fTemp = new File(sAFile);
            if (!fTemp.exists()) {
                System.out.println("Arquivo não encontrado!");
                return;
            }

            RandomAccessFile raf = new RandomAccessFile(sAFile, "rw");

            String words[] = new String[8];
            words[0] = "Hoje irei para a escola mais cedo.";
            words[1] = "As crianças hoje em dia usam muito o celular.";
            words[2] = "Quando acordei vi um pássaro na janela.";
            words[3] = "Não posso sair à noite durante a semana.";
            words[4] = "Ainda estava cedo quando João decidiu ir embora.";
            words[5] = "Em breve me formarei na faculdade de medicina.";
            words[6] = "Ela nunca ligou para maquiagem.";
            words[7] = "Ele dirige muito mal.";

            /*Escreve alguns trechos que contenham ou não muito */
            for (int i = 0; i < words.length; i++) {
                raf.writeUTF(words[i]);
            }

            /*Volta ao início para ler os dados*/
            raf.seek(0);

            long seekAnterior = 0;
            while (raf.getFilePointer() < raf.length()) {
                String line = raf.readUTF();
                if(line.contains(oldWord)) { // vê se tem ou não para substituir
                  line = line.replaceAll(oldWord, newWord); // substitui
                  raf.seek(seekAnterior); // volta para o início da linha e sobreescreve a linha antiga
                  raf.writeUTF(line);
                }
                seekAnterior = raf.getFilePointer(); // salvar o ponto inicial de cada linha
            }

            // Volta ao inicio para ler os dados
            raf.seek(0);

            while (raf.getFilePointer() < raf.length()) {
                System.out.println(raf.readUTF());
            }

            raf.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }



    // public void ReplaceWord(String sAFile, String oldWord, String newWord) {
    //     try {
    //         File f = new File(sAFile);
    //         if (!f.exists()) {
    //             System.out.println("Arquivo não encontrado!");
    //             return;
    //         }

    //         FileReader fr = new FileReader(f);
    //         BufferedReader br = new BufferedReader(fr);
    //         FileWriter fw = new FileWriter(f);

    //         String line;
    //         while ((line = br.readLine()) != null) {
    //             line = line.replaceAll(oldWord, newWord);
    //             fw.write(line);
    //         }
    //         fw.seek(0);
    //         while ((line = br.readLine()) != null) {
    //             System.out.println(line);
    //         }
    //         fw.close();
    //         br.close();
    //         fr.close();

    //     } catch (IOException e) {
    //         e.printStackTrace();
    //     }

    // }

    public void TanqueCano(String sAFile) {
        try {
            byte[] byteBuffer = new byte[64];           /*2^5 bytes de buffer*/
            char[] charBuffer = new char[64];

            File tanque = new File(sAFile);

            FileInputStream cano = new FileInputStream(tanque);
            cano.read(byteBuffer);
            FileReader fr = new FileReader(tanque);
            BufferedReader br = new BufferedReader(fr);
            InputStreamReader filtro = new InputStreamReader(cano,StandardCharsets.UTF_8);
            filtro.read(charBuffer);

            BufferedReader decantador = new BufferedReader(filtro);
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            decantador.close();
            filtro.close();
            cano.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void Copy(String[] args) {
        int iSum = 0;
        String nomeFonte = args[0];
        String nomeDestino = args[1];

        System.out.println("Diretório corrente: " + (new File(".")).getAbsolutePath());

        File fonte = new File(nomeFonte);
        File destino = new File(nomeDestino);

        System.out.println(fonte.getAbsolutePath());
        System.out.println(destino.getAbsolutePath());

        try {
            FileInputStream in = new FileInputStream(fonte);
            FileOutputStream out = new FileOutputStream(destino);

            byte[] buffer = new byte[512];           /*2^13 bytes de buffer*/
            int length = in.read(buffer);

            while (length != -1) {
                out.write(buffer, 0, length);
                iSum += length;
                length = in.read(buffer);
            }

            in.close();
            out.flush();
            out.close();

            System.out.println(iSum + " bytes lidos/escritos.");
        } catch (FileNotFoundException e) {
            e.printStackTrace();        /*Exibe a pilha, mas continua rodando*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
