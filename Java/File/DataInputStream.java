import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        FileInputStream in = new FileInputStream("sample2.data");
        DataInputStream fi = new DataInputStream(in);
        int n, i;
        int[] a;
        n = fi.read();
        a = new int[n];
        for(i = 0; i < a.length; i++) a[i] = fi.read();
        for(i = 0; i < a.length; i++) System.out.printf(a[i] + " ");
        fi.close();
    }
}
