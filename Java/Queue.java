Các phương thức đặc trưng của Queue
Thao tác	                                   Ném ra ngoại lệ	                         Trả về giá trị cụ thể
Thêm một phần tử vào hàng đợi	                  add(e)	                                      offer(e)
Truy xuất một phần tử từ đầu hàng đợi	          remove()	                                    poll()
Lấy và Xóa một phần tử khỏi đầu hàng đợi	      element()	                                    peek()
1.add(E): Thêm một phần tử vào hàng đợi nếu có thể làm điều này ngay lập tức mà không bị giới hạn bởi kích thước hàng đợi,
          trả về true nếu thành công, ngược lại nó sẽ ném ra ngoại lệ IllegalStateException khi hàng đợi không còn chỗ.
2.boolean offer(E): Thêm phần tử vào hàng đợi nếu có thể làm điều đó ngay lập tức nếu không bị giới hạn bởi kích thước hàng đợi. 
          Khi sử dụng hàng đợi có kích thước giới hạn, phương thức này khá giống với add(E), tuy nhiên phương thức này không ném ra ngoại 
          lệ khi không trèn được phần tử vào hàng đợi, mà nó trả về false trong tình huống đó.
3.E remove(): Lấy ra và loại bỏ luôn phần tử đầu tiên của hàng đợi. Phương thức này chỉ khác với poll() ở chỗ nếu hàng đợi không có phần tử 
           ngoại lệ sẽ bị ném ra.
4.E poll(): Lấy ra và loại bỏ phần tử đầu tiên trong hàng đợi, hoặc trả về null nếu hàng đợi không có phần tử nào.
5.E element(): Lấy ra nhưng không loại bỏ phần tử đứng đầu của hàng đợi. Phương thức này chỉ khác với peek() là nó ném ra ngoại lệ nếu hàng
           đợi không có phần tử.
6.E peek(): Lấy ra, nhưng không loại bỏ phần tử đầu tiên trong hàng đợi, hoặc trả về null nếu hàng đợi không có phần tử nào.
Ví dụ:

package UPCoder;

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class TIMDUONG{
    public Scanner inp = new Scanner(System.in);
    public int n, m, dau, cuoi, res;
    public boolean[][] a;
    public boolean[] s;
    public int[] p;
    public Queue<Integer> qu = new LinkedList<Integer>();

    public TIMDUONG(){}

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
        TIMDUONG cc = new TIMDUONG();
        cc.nhap();
        cc.BFS();
        cc.kq(cc.cuoi);
        System.out.println(cc.res);
    }
}
