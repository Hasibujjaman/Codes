package p1;

import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class MoneyChanger {
    JFrame frame;
    JLabel label1;
    JLabel label2;
    JTextField tf1;
    JTextField tf2;
    JButton b1;
    JButton b2;

    MoneyChanger(){
    frame = new JFrame();
    frame.setVisible(true);
    frame.setTitle("Money Changer");
    frame.setSize(510,410);
    frame.setResizable(false);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLayout(null);
    
    tf1 = new JTextField();
    tf2 = new JTextField();
    tf1.setBounds(50,25,150,50);
    tf2.setBounds(250,25,150,50);


    label1 = new JLabel();
    label1.setText("USD");
    label1.setForeground(Color.BLACK);
    label2 = new JLabel("BDT");


    //frame.add(tf1);
    //frame.add(tf2);
    frame.add(label1);
    frame.add(label2);
    
        
    }
    public static void main(String[] args) {
        MoneyChanger mc = new MoneyChanger();
    }
}
