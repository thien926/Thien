

import java.util.Scanner;
import java.lang.Math;

final class Toado{
    public int i;
    public int j;
    
    public Toado(){
        
    }
    
    public void khoitao(int x, int y){
        this.i = x;
        this.j = y;
    }
    
    public void phai(){
        this.j = this.j + 1;
    }
    
    public void trai(){
        this.j = this.j - 1;
    }
    
    public void tren(){
        this.i = this.i - 1;
    }
    
    public void duoi(){
        this.i = this.i + 1;
    }
    
}

public class Main{
    public Scanner inp = new Scanner(System.in);
    
    public int n, max;
    public int[][] a;
    Toado[] b;
    
    public Main(){
        
    }
    
    public void nhap(){
        max = 0;
        n = inp.nextInt();
        a = new int[n+1][n+1];
        b = new Toado[2*n+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                a[i][j] = inp.nextInt();
            }
        }
        for(int i = 0; i <= 2*n; i++) b[i] = new Toado();
        b[1].khoitao(1, 1);
    }
    
    public void kt(){
        int rr = 0;
        for(int i = 2*n-1; i >= 1; i--){
            rr = rr + ((int)Math.pow(2,2*n - 1 -i))*a[b[i].i][b[i].j];
        }
        if(max < rr) max = rr;
    }
    
    public void quaylui(int i){
        if(i >= 2*n-1){
            b[i].khoitao(n,n);
            kt();
        }
        else{
            if(a[b[i-1].i][b[i-1].j] != -1){
                if(b[i-1].i == n && b[i-1].j != n){
                    b[i].khoitao(b[i-1].i, b[i-1].j+1);
                    quaylui(i+1);
                }
                else if(b[i-1].i != n && b[i-1].j == n){
                    b[i].khoitao(b[i-1].i+1, b[i-1].j);
                    quaylui(i+1);
                }
                else if(b[i-1].i != n && b[i-1].j != n){
                    if(a[b[i-1].i][b[i-1].j+1] > a[b[i-1].i+1][b[i-1].j]){
                        b[i].khoitao(b[i-1].i, b[i-1].j+1);
                        quaylui(i+1);
                    }
                    else{
                        if(a[b[i-1].i][b[i-1].j+1] < a[b[i-1].i+1][b[i-1].j]){
                            b[i].khoitao(b[i-1].i+1, b[i-1].j);
                            quaylui(i+1);
                        }
                        else{
                            b[i].khoitao(b[i-1].i, b[i-1].j+1);
                            quaylui(i+1);
                            b[i].khoitao(b[i-1].i+1, b[i-1].j);
                            quaylui(i+1);
                        }
                    }
                }
            }
        }
    }

    
    public void xuat(){
        System.out.println(max);
        inp.close();
    }
    
    public static void main(String[] args){
        Main cc = new Main();
        cc.nhap();
        cc.quaylui(2);
        cc.xuat();
    }
}
