import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        Scanner fi = new Scanner(new File("sample3.data"));
        int n, i;
        int[] a;
        n = fi.nextInt();
        a = new int[n];
        for(i = 0; i < a.length; i++) a[i] = fi.nextInt();
        System.out.println(n);
        for(i = 0; i < a.length; i++) System.out.printf(a[i] + " ");
        fi.close();
    }
}
