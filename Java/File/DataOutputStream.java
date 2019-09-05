import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        Scanner inp = new Scanner(System.in);;
        FileOutputStream out = new FileOutputStream("sample2.data");
        DataOutputStream fo = new DataOutputStream(out);
        int n, i;
        int[] a;
        System.out.print("Nhập n = ");
        n = inp.nextInt();
        a = new int[n];
        fo.write(n);
        for(i = 0; i < a.length; i++) a[i] = inp.nextInt();
        for(i = 0; i < a.length; i++) fo.write(a[i]);
        inp.close();
        fo.close();
    }
}
