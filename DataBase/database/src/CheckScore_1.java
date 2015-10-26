import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;


public class CheckScore_1 extends JFrame {//implements ActionListener {
	JButton button1,button2;
	JLabel label;
	JPanel panel;
    public CheckScore_1(String s) {
    	super(s);
	setBounds(300,300,200,310);
	setVisible(false);
	validate();
   button1=new JButton("分数查询");
   button2=new JButton("其它信息");
   Icon icon=new ImageIcon("介绍.jpg");
   label=new JLabel(icon,JLabel.CENTER);
   panel=new JPanel();
   panel.add(button1);
   panel.add(button2);
   add(label,BorderLayout.NORTH);
   add(panel,BorderLayout.CENTER);
//   button1.addActionListener(this);
 //  button2.addActionListener(this);
    }
    
    
}