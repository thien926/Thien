import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        Scanner inp = new Scanner(System.in);
        FileOutputStream fo = new FileOutputStream("sample1.data");
        int[] a;
        int i, n;
        System.out.print("Nhập n = ");
        n = inp.nextInt();
        fo.write(n);
        a = new int[n];
        for(i = 0; i < a.length; i++) a[i] = inp.nextInt();
        for(i = 0; i < a.length; i++){
            fo.write(a[i]);
        }
        inp.close();
        fo.close();
    }
}
