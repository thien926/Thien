
import java.util.Scanner;
import java.io.*;

final class hcn{
    public int x1, x2, y1, y2, d;

    public hcn(){}

    public void set(int aa, int bb, int cc, int dd){
        x1 = aa;
        y1 = bb;
        x2 = cc;
        y2 = dd;
        d = 0;
    }
}

public class Main{
    public Scanner fi = new Scanner(new File("HCN.INP"));
    public FileOutputStream out = new FileOutputStream("HCN.OUT");
    public PrintWriter fo = new PrintWriter(out);

    public hcn[] a;
    public int n;

    public Main() throws IOException{}

    public void set(){
        int x1, y1, x2, y2;
        n = fi.nextInt();
        a = new hcn[n];
        for(int i = 0; i < n; i++) a[i] = new hcn();
        for(int i = 0 ; i < n; i++){
            x1 = fi.nextInt();
            y1 = fi.nextInt();
            x2 = fi.nextInt();
            y2 = fi.nextInt();
            a[i].set(x1, y1, x2, y2);
        }
        fi.close();
    }  

    public void solve(){
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++) if(i != j && a[i].x1 >= a[j].x1 && a[i].y1 >= a[j].y1 && a[i].x2 <= a[j].x2 && a[i].y2 <= a[j].y2){
                a[i].d++;
            }
        }
        int max = a[0].d;
        for(i = 1; i < n; i++) if(max < a[i].d) max = a[i].d;
        fo.println(max);
        fo.close();
    }  
    
    public static void main(String[] args) throws IOException{
        Main cc = new Main();
        cc.set();
        cc.solve();
    }
}
