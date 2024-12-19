package p1;

import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

class MyFrame extends JFrame implements ActionListener {
    JButton btn1 = new JButton("Login");
    JButton btn2 = new JButton("Cancel");
    JLabel label = new JLabel();
    JTextField tf = new JTextField();
    Container c;

    MyFrame() {
        setTitle("Welcome to CSE Java");
        setSize(400, 500);
        // setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        c = getContentPane();
        c.setLayout(null);
        btn1.setBounds(100, 100, 80, 30);
        btn2.setBounds(180, 100, 80, 30);
        label.setBounds(100, 50, 180, 30);
        tf.setBounds(100, 20, 50, 30);
        c.add(btn1);
        c.add(btn2);
        c.add(label);
        c.add(tf);
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btn1) {
            label.setText("VAT=" + tf.getText());
            btn1.setBackground(Color.green);
            btn2.setBackground(null);
        }
        if (e.getSource() == btn2) {
            label.setText("0");
            btn2.setBackground(Color.green);
            btn1.setBackground(null);
        }

    }
}

public class GUI{

    public static void main(String[] args) {
        new MyFrame();
        
    }

}