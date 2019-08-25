import java.util.Scanner;

final class Toado{
    public int i;
    public int j;
    public Toado(){}
    public void set(int x, int y){
        i = x;
        j = y;
    }
}

public class Main{
    public Scanner inp = new Scanner(System.in);
    public int n, m, res;
    public int[][] a;
    public Toado[] b;
    public Toado[] kq;
    public Toado[] kk;

    public Main(){}

    public void set(){
        int i, j;
        res = 0;
        m = inp.nextInt();
        n = inp.nextInt();
        a = new int[m+1][n+1];
        for(i = 1; i <= m; i++){
            for(j = 1; j <= n; j++){
                a[i][j] = inp.nextInt();
            }
        }
        b = new Toado[n+m];
        kq = new Toado[n+m]; 
        kk = new Toado[3];
        for(i = 0; i < 3; i++) kk[i] = new Toado();
        for(i = 0; i < n + m; i++){
            b[i] = new Toado();
            kq[i] = new Toado();
        }
        b[1].set(1, 1);
        kk[1].set(0, 1);
        kk[2].set(1, 0);
        inp.close();
    } 

    public void kt(){
        int r = 0, i;
        for(i = 1; i < m + n; i++) r = r + a[b[i].i][b[i].j];
        if(res < r){
            res = r;
            for(i = 1; i < b.length; i++) kq[i].set(b[i].i, b[i].j);
        }
    }

    public void backtracking(int i){
        if(i >= n + m -1){
            b[i].set(m, n);
            kt();
        }
        else{
            int j;
            for(j = 1; j < 3; j++) if(b[i-1].i + kk[j].i <= m && b[i-1].j + kk[j].j <= n){
                b[i].set(b[i-1].i+kk[j].i, b[i-1].j+kk[j].j);
                backtracking(i+1);
            }
        }
    }

    public void xuat(){
        System.out.println(res);
        for(int i = 1; i < n+m; i++) System.out.println(kq[i].i + " " + kq[i].j);
    }

    public static void main(String[] args){
        Main cc = new Main();
        cc.set();
        cc.backtracking(2);
        cc.xuat();
    }
}
