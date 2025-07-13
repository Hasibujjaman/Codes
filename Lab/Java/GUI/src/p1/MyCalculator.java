//calculator with container (incmp)
package p1;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

class MyFrameCalculator extends JFrame implements ActionListener, MouseListener {
    JLabel label = new JLabel("Display here");
    Font fn1 = new Font("Arial", Font.BOLD, 22);
    Font fn2 = new Font("DigifaceWide", Font.BOLD, 22);
    Font fn3 = new Font("Arial", Font.BOLD, 33);
    JButton[] bx = new JButton[16];
    String str1 = "", str2 = "";
    String op;
    Container c;

    public MyFrameCalculator() {
        c = this.getContentPane();
        label.setBounds(10, 7, 255, 40);
        label.setFont(fn2);
        label.setOpaque(true);
        label.setHorizontalAlignment(JLabel.RIGHT);
        label.setBackground(Color.white);
        c.setLayout(null);
        c.setBackground(Color.DARK_GRAY); // buttons starts
        int i, k = 1, j = 1;
        for (i = 1; i <= 9; i++) {
            bx[i] = new JButton(Integer.toString(i));
            bx[i].setBounds(10 + (j - 1) * 65, 60 + (k - 1) * 65, 60, 60);
            bx[i].setFont(fn1);
            c.add(bx[i]);
            bx[i].addActionListener(this);
            bx[i].addMouseListener(this);
            j++;
            if (i % 3 == 0) {

                k++;
                j = 1;
            }
        } // for loop
          // for 0 button
        i = 1;
        bx[i - 1] = new JButton("0");
        bx[i - 1].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[i - 1].setFont(fn1);
        c.add(bx[i - 1]);
        bx[i - 1].addActionListener(this);
        // for +
        i = 2;
        bx[10] = new JButton("+");
        bx[10].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[10].setFont(fn1);
        c.add(bx[10]);
        bx[10].addActionListener(this);
        // for +
        i = 3;
        bx[11] = new JButton("-");
        bx[11].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[11].setFont(fn1);
        c.add(bx[11]);
        bx[11].addActionListener(this);
        // for =
        i = 4;
        bx[14] = new JButton("=");
        bx[14].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[14].setFont(fn1);
        bx[14].setBackground(Color.yellow);
        c.add(bx[14]);
        bx[14].addActionListener(this);
        // for x
        i = 4;
        k--;
        bx[12] = new JButton("x");
        bx[12].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[12].setFont(fn1);
        c.add(bx[12]);
        bx[12].addActionListener(this);

        // for /
        i = 4;
        k--;
        bx[13] = new JButton("/");
        bx[13].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[13].setFont(fn1);
        c.add(bx[13]);
        bx[13].addActionListener(this);
        // for
        i = 4;
        k--;
        bx[15] = new JButton("C");
        bx[15].setBounds(10 + (i - 1) * 65, 60 + (k - 1) * 65, 60, 60);
        bx[15].setFont(fn1);
        c.add(bx[15]);
        bx[15].addActionListener(this);
        c.add(label);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == bx[14]) {
            int x = Integer.parseInt(str2);
            int y = Integer.parseInt(str1);
            int z = 0;
            switch (op) {
                case "+":
                    z = x + y;
                    break;
                case "-":
                    z = x - y;
                    break;
                case "x":
                    z = x * y;
                    break;
                case "/":
                    z = x / y;
                    break;
            }
            label.setText(Integer.toString(z));
        }
        for (int i = 10; i <= 13; i++) {
            if (e.getSource() == bx[i]) {
                // str1="";str2="";
                switch (i) {
                    case 10:
                        op = "+";
                        break;
                    case 11:
                        op = "-";
                        break;
                    case 12:
                        op = "x";
                        break;
                    case 13:
                        op = "/";
                        break;

                }
            }
            str2 = str1;
            str1 = "";
            label.setText(op);
        }
        if (e.getSource() == bx[15])

        {
            str1 = "";
            str2 = "";
            label.setText(str1);
        }
        for (int i = 0; i <= 9; i++) {
            if (e.getSource() == bx[i]) {
                str1 = str1 + Integer.toString(i);
                label.setText(str1);
            }
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        // TODO Auto-generated method stub
    }

    @Override
    public void mousePressed(MouseEvent e) {
        // TODO Auto-generated method stub
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        // TODO Auto-generated method stub
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        for (int i = 0; i < 15; i++)
            if (e.getSource() == bx[i]) {
                bx[i].setForeground(Color.red);

                bx[i].setFont(fn3);
            }
    }

    @Override
    public void mouseExited(MouseEvent e) {
    }
}

public class MyCalculator {
    for(int i = 0;i<15;i++){
        if (e.getSource() == bx[i]) {
            bx[i].setForeground(null);
            bx[i].setFont(fn1);
        }
    }

    public static void main(String[] args) {
        MyFrameCalculator frame3=new MyFrameCalculator(); 
        frame3.setTitle("My Calculator"); 
        frame3.setBounds(100,50,290,400);
        frame3.setVisible(true);
        frame3.setResizable(false); frame3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
