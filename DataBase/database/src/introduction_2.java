import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
public class introduction_2 extends JFrame {
   JLabel lab;
   //Container con=getContentPane();
    public introduction_2(String s) {
    
    super(s);
    	Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image); 
   // Toolkit tool=this.getToolkit();
  //  Image image=tool.getImage("计算器.jpg");
//	this.setIconImage(image); 
    Icon icon=new ImageIcon("管理员介绍.jpg");
     lab=new JLabel(icon);
     
    add(lab,BorderLayout.CENTER);
    setVisible(false);
    setBounds(450,200,420,400);	
    }
    
    
}