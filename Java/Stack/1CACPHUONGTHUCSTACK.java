Các phương thức của Stack
1	boolean empty(): Kiểm tra nếu Stack này là trống. Trả về true nếu nó trống và false nếu stack chứa các phần tử
2	Object peek( ): Trả về phần tử trên cùng của Stack, nhưng không gỡ bỏ nó
3	Object pop( ): Trả về phần tử trên cùng của Stack, gỡ bỏ nó
4	Object push(Object element): Đẩy phần tử lên trên cùng của Stack. Cũng trả về phần tử đó
5	int search(Object element): Tìm kiếm phần tử trong Stack. Nếu tìm thấy, offset của nó từ trên cùng của Stack được trả về. Nếu không, nó trả về -1

Ví dụ:
package RegexMatches1;

import java.util.Scanner;
import java.util.Stack;
public class DFS {
    private Scanner inp = new Scanner(System.in);
    public int n, m, dau, cuoi;
    public boolean[][] a;
    public boolean[] s;
    public int[] trace;
    public Stack st = new  Stack();
    
    public DFS(){
//        System.out.printf("Nhập n, m, đầu, cuối: ");
        n = inp.nextInt();
        m = inp.nextInt();
        dau = inp.nextInt();
        cuoi = inp.nextInt();
        dau--;
        cuoi--;
    }
    
    public void nhapmang(){
//        System.out.println("Nhập các số:");
        a = new boolean[n][n];
        s = new boolean[n];
        trace = new int [n];
        for(int i = 0; i < n; i++){
            s [i] = true;
            for(int j = 0; j < n; j++) a [i][j] = false;
        }
        
        int u, v;
        for(int i = 0 ; i < m ; i++){
            u = inp.nextInt();
            v = inp.nextInt();
            u--;v--;
            a [u][v] = true;
            a [v][u] = true;
        }
        
        trace [dau] = -1;
    }
    
    public void DFS1(){
        st.push((int)dau);
        s [dau] = false;
        int u, i;
        do{
            u = (int)st.peek();
            for(i = 0; i < n; i++) if(s[i] && a[u][i]){
                System.out.printf((i + 1) + " ");
                s[i] = false;
                st.push((int)i);
                trace [i] = u;
                break;
            }
            if(i >= n) st.pop();
        }
        while(!st.empty());
    }
    
    public void xuat(int i){
        if(trace[i] >= 0) xuat(trace[i]);
        System.out.printf((i + 1) + " ");
    }
    
    public static void main(String[] args){
        DFS bien = new DFS();
        bien.nhapmang();
        System.out.printf((bien.dau + 1) + " can visit: " + (bien.dau + 1) + " ");
        bien.DFS1();
        System.out.println();
        bien.xuat(bien.cuoi);
    }
}
