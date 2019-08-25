import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main{
    public Scanner inp = new Scanner(System.in);
    public int n, m, dau, cuoi, res;
    public boolean[][] a;
    public boolean[] s;
    public int[] p;
    public Queue<Integer> qu = new LinkedList<Integer>();

    public Main(){}

    public void nhap(){
        int i, j, u, v;
        res = 0;
        n = inp.nextInt();
        m = inp.nextInt();
        dau = inp.nextInt(); dau--;
        cuoi = inp.nextInt(); cuoi--;
        a = new boolean[n][n];
        s = new boolean[n];
        p = new int[n];

        for(i = 0; i < n; i++){
            s[i] = true;
            for(j = 0; j < n; j++){
                a[i][j] = false;
            }
        }

        for(i = 0; i < m; i++){
            u = inp.nextInt(); u--;
            v = inp.nextInt(); v--;
            a[u][v] = true;
            a[v][u] = true;
        }

        p[dau] = -1;
        inp.close();
    }

    public void BFS(){
        int i, u;
        s[dau] = false;
        qu.offer(dau);
        do{
            u = qu.poll();
            for(i = 0; i < n; i++) if(s[i] && a[u][i]){
                s[i] = false;
                p[i] = u;
                qu.offer(i);
            }
        }
        while(!qu.isEmpty());
    }

    public void kq(int i){
        if(p[i] != -1){
            res++;
            kq(p[i]);
  //          System.out.println(i+1);
        }
    }

    public static void main(String[] args){
        Main cc = new Main();
        cc.nhap();
        cc.BFS();
        cc.kq(cc.cuoi);
        System.out.print(cc.res);
    }
}
