
import java.util.Scanner;
import java.io.*;

public class Main{
    public Scanner fi = new Scanner(new File("STR.INP"));
    public FileOutputStream out = new FileOutputStream("STR.OUT");
    public PrintWriter fo = new PrintWriter(out);

    public String s;
    public int dau = 0, len = 0;
    public int[] d;

    public Main() throws IOException{}

    public void set(){
        s = fi.next();
        d = new int[256];
        int i;
        for(i = 0; i < 256; i++) d[i] = 0;
        fi.close();
    }

    public void solve(){
        int i, j;
        j = 1;
        for(i = 0; i < s.length(); i++){
            if(d[s.charAt(i)] == 0){
                d[s.charAt(i)] = i + 1;
            }
            else{
                if(i+1 - d[s.charAt(i)] > len){
                    len = i+1 - d[s.charAt(i)];
                    dau = d[s.charAt(i)];
                    j = i + 1;
                    d[s.charAt(i)] = j;
                }
            }
        }

        if(i + 1 - j > len){
            fo.printf(j + " " + (i+1 - j));
        }
        else{
            fo.printf(dau + " " + len);
        }
        fo.close();
    }

    public static void main(String[] args) throws IOException{
        Main cc = new Main();
        cc.set();
        cc.solve();
    }
    
}
