import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class CheckCorses_1 extends JFrame {//implements ActionListener {
	JButton button1,button2;
	JLabel label;
	JPanel panel;

    public CheckCorses_1(String s) {
    super(s);
	setBounds(300,300,200,210);
	setVisible(false);
		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image); 
	validate();
   button1=new JButton("������ѯ");
   button2=new JButton("������Ϣ");
   Icon icon=new ImageIcon("����.jpg");
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