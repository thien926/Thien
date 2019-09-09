
import java.util.Scanner;
import java.util.Vector;
import java.util.List;
import java.io.*;
import java.nio.IntBuffer;

public class Main{
    public Scanner fi = new Scanner(new File("DIVISORS.INP"));
    public FileOutputStream out = new FileOutputStream("DIVISORS.OUT");
    public PrintWriter fo = new PrintWriter(out);

    public int n;
    public boolean[] t;
    public List<Integer> a;
    public long res, nn;
    final int mmax = 1000000;

    public Main() throws IOException{}

    public void set(){
        n = fi.nextInt();
        int i, j;
        t = new boolean[mmax];
        a = new Vector<>();
        for(i = 0; i < mmax; i++) t[i] = true;
        for(i = 2; i < mmax; i++) if(t[i]){
            a.add(i);
            j = i * i;
            if(j < 0) continue;
            for(; j < mmax; j = j + i){
                t[j] = false;
            }
        }
        t[0] = t[1] = false;
        fi.close();
    }

    public void solve(){
        int i, j;
        nn = 1;
        for(i = 1; i <= n; i++) nn = nn * i;
        res = 1;
        int dem;
        Integer[] aa;
        aa = new Integer[a.size()];
        aa = a.toArray(aa);
        for(i = 0; i < aa.length; i++){
            if(nn <= 0) break;
            dem = 0;
            while(nn % aa[i] == 0){
                dem++;
                nn/= aa[i];
            }
            res = res * (1 + dem);
        }
        fo.println(res - 1);
        a.clear();
        fo.close();
    }

    public static void main(String[] args) throws IOException{
        Main cc = new Main();
        cc.set();
        cc.solve();
    }
}
