import java.util.Scanner;
import java.io.IOException;
import java.lang.Math;

public class Main{
    public Scanner inp = new Scanner(System.in);
    public int T, A, B, m, n;
    public int w = 100001;
    public boolean[] a;
    public int res;

    public Main(){}

    public void set(){
        int i, j;
        T = inp.nextInt();
        a = new boolean[w];
        for(i = 0; i < w; i++) a[i] = true;
        for(i = 2; i < w; i++) if(a[i]){
            j = i*i;
            if((int)Math.sqrt(Math.abs(j)) != i) continue;
            for(; j < w; j = j + i) a[j] = false;
        }
        a[1] = false;
        a[0] = false;
    }

    public void solve(){
        int i, j;
        for(i = 0; i < T; i++){
            res = 0;
            A = inp.nextInt();
            B = inp.nextInt();
            m = inp.nextInt();
            n = inp.nextInt();
            for(j = A; j <= B; j++) if(a[j] && j % m == n){
                res = res + j;
            }
            System.out.println(res);
        }
        inp.close();
    }

    public static void main(String[] args) throws IOException{
        Main cc = new Main();
        cc.set();
        cc.solve();
    }
}
