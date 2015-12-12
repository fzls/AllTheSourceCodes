package database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Silence on 2015/12/12.
 */
public class TestIcon {
    private JButton button1;
    private JPanel panel;

    public TestIcon() {
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showConfirmDialog(null,"Bye Bye","Bye",JOptionPane.INFORMATION_MESSAGE,JOptionPane.OK_OPTION) ;
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("TestIcon");
        frame.setContentPane(new TestIcon().panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
