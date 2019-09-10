//https://www.youtube.com/watch?v=qZHp7NkO2nY&list=PLAxmMVqEIFdeN2-ql337WNwQZq7d3HDF5&index=3&t=0s
package javaswing;

import javax.swing.*;

public class hello extends JFrame{
    public hello(){
        setSize(200, 150);  // kich thuoc khung
        setVisible(true);  // xuất khung
        setLocation(600, 300); //xuất hiện khung ở vị trí giữa màn hình
        setResizable(false);  //chọn thay kéo thay đỏi kích thước bảng
        JLabel label = new JLabel("Hello World");
        add(label);
    }
    public static void main(String[] args){
        hello cc = new hello();
    }
}
