import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        FileInputStream fi = new FileInputStream("sample1.data");
        int n = fi.read();
        int[] a = new int[n];
        for(int i = 0; i < a.length; i++) a[i] = fi.read();
        System.out.println(n);
        for(int i = 0; i < a.length; i++) System.out.printf(a[i] + " "); 
        fi.close();
    }
}
