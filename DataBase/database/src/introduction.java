import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
public class introduction extends JFrame {
   JLabel lab;
   Container con=getContentPane();
    public introduction(String s) {
    
    super(s);
    	Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image); 
   // Toolkit tool=this.getToolkit();
    //Image image=tool.getImage("º∆À„∆˜.jpg");
	this.setIconImage(image); 
    Icon icon=new ImageIcon("src//—ß…˙ΩÈ…‹.jpg");
     lab=new JLabel(icon);
     
    add(lab,BorderLayout.CENTER);
    setVisible(true);
    setBounds(450,200,420,400);	
    }
    
    
}