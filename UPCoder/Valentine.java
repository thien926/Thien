import java.util.Scanner;
import java.lang.Math;

public class Main{
    public Scanner inp = new Scanner(System.in);

    public int N, D, R;
    public int[] a;

    public Main(){}

    public void set(){
        N = inp.nextInt();
        D = inp.nextInt();
        R = inp.nextInt();
        a = new int[N];

        int i;
        for(i = 0; i < a.length; i++) a[i] = inp.nextInt();
    }

    public void exch(int i, int j){
        int r = a[i];
        a[i] = a[j];
        a[j] = r;
    }

    public void quicksort(int l, int r){
        int x = a[(l+r)/2], i = l, j = r;
        do{
            while(a[i] > x) i++;
            while(a[j] < x) j--;
            if(i <= j) exch(i++, j--);
        }
        while(i < j);
        if(l < j) quicksort(l, j);
        if(i < r) quicksort(i, r);
    }

    public void solve(){
        int i, res = 0;
        double dd = Math.sqrt(Math.pow(D, 2) + Math.pow(R, 2));
        quicksort(0, a.length-1);
        for(i = 0; i < a.length; i++) if(a[i] > dd) res++;
        else break;
        res = a.length - res;
        System.out.print(res);
    }
    public static void main(String[] args){
        Main cc = new Main();
        cc.set();
        cc.solve();
    }
}
