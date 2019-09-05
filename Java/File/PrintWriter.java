import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        FileOutputStream out = new FileOutputStream("sample3.data");
        PrintWriter fo = new PrintWriter(out);
        Scanner inp = new Scanner(System.in);
        int n, i;
        int[] a;
        System.out.print("Nhập n = ");
        n = inp.nextInt();
        a = new int[n];
        fo.println(n);
        for(i = 0; i < a.length; i++) a[i] = inp.nextInt();
        for(i = 0; i < a.length; i++) fo.printf(a[i] + " ");
        inp.close();
        fo.close();
    }
}
