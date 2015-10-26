import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.color.*;
import java.awt.event.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class Student extends JFrame implements ActionListener{
	
	JMenuBar menubar;
    JMenu menu1,menu2,menu3;
    JMenuItem item1_1,item1_2,item2_1,item2_2,item3_1,item3_2,item3_3,item3_4,item3_5,item3_6,item3_7,item3_8,item3_9,item3_10;
    JButton button1,button2,button3,button4,button5,button6;
    JLabel label1,label2;
    JToolBar toolbar;
    JSplitPane split;
    Date nowTime=new Date();
    public Student(String s) {
    	super(s);
    	setBounds(150,50,1000,618);
    	setVisible(false);
		
    		Toolkit tool=this.getToolkit();
	
	Image image = tool.getImage("SRC//login.png");
	this.setIconImage(image); 

	validate();

    	Icon icon=new ImageIcon("SRC//学生.jpg");
    	Icon icon1=new ImageIcon("SRC//学生介绍.jpg");
    	menubar=new JMenuBar();
    	menubar.setBackground(Color.green);
    	menu1=new JMenu("QUERY");
    	menu2=new JMenu("HELP");
    	menu3=new JMenu("STASTICS QUERY");
    	item1_1=new JMenuItem("RELOGIN");
    	item1_2=new JMenuItem("EXIT");
    	item2_1=new JMenuItem("FUNCTION INTRODUCTION");
    	item2_2=new JMenuItem("ABOUT THE SYSTEM");   
    	item3_1=new JMenuItem("TEACHER");
    	item3_2=new JMenuItem("COURSE");
    	item3_3=new JMenuItem("RANK");
    	item3_4=new JMenuItem("SCORE>=75");
    	item3_5=new JMenuItem("COURSES FAILED>=2");
    	item3_6=new JMenuItem("STUDENTS FAILED>=2");
    	item3_7=new JMenuItem("LOWEST SCORE");
    	item3_8=new JMenuItem("SPECIAL STUDENT");
    	item3_9=new JMenuItem("PROVINCE");
    	item3_10=new JMenuItem("HIGHEST CREDITS");
    	
    	label1=new JLabel(icon);
    	
    	label1.setBackground(Color.green);
    	label1.setSize(100, 62);
    	label1.setVisible(true);
    	SimpleDateFormat matter=new SimpleDateFormat();//时间不会变？？
        label2=new JLabel(matter.format(nowTime),JLabel.CENTER);
    	button1=new JButton("STUDENTS INFORMATION");
    	button2=new JButton("COURSE INFORMATION");
    	button3=new JButton("COURSE-SELECTION");
    	button4=new JButton("PASSED AMOUNTS");
    	button5=new JButton("RANK");
    	button1.setBackground(Color.green);
    	button2.setBackground(Color.green);
    	button3.setBackground(Color.green);
    	button4.setBackground(Color.green);
    	button5.setBackground(Color.green);
    	
    	
        toolbar=new JToolBar();
    	toolbar.add(button1);
    	toolbar.add(button2);
    	toolbar.add(button3);
    	toolbar.add(button4);
    	toolbar.add(button5);
    	toolbar.setBackground(Color.green);
    	menu1.add(item1_1);
    	menu1.add(item1_2);
    	menu2.add(item2_1);
    	menu2.add(item2_2);
    	menu3.add(item3_1);
    	menu3.add(item3_2);
    	menu3.add(item3_3);
    	menu3.add(item3_4);
    	menu3.add(item3_5);
    	menu3.add(item3_6);
    	menu3.add(item3_7);
    	menu3.add(item3_8);
    	menu3.add(item3_9);
    	menu3.add(item3_10);
    	menubar.add(menu1);
    	menubar.add(menu2);
    	menubar.add(menu3);
    
    	split=new JSplitPane(JSplitPane.VERTICAL_SPLIT,menubar,toolbar);
       add(split,BorderLayout.NORTH);
      add(label1,BorderLayout.CENTER);
       add(label2,BorderLayout.SOUTH);
      
      //加的东西
      item1_1.addActionListener(this);
      item1_2.addActionListener(this);
      item2_1.addActionListener(this);
      item2_2.addActionListener(this);

      item3_1.addActionListener(this);
      item3_2.addActionListener(this);
      item3_3.addActionListener(this);
      item3_4.addActionListener(this);
      item3_5.addActionListener(this);
      item3_6.addActionListener(this);
      item3_7.addActionListener(this);
      item3_8.addActionListener(this);
      item3_9.addActionListener(this);
      item3_10.addActionListener(this);
    
      button1.addActionListener(this);
      button2.addActionListener(this);
      button3.addActionListener(this);
      button4.addActionListener(this);
      button5.addActionListener(this);
     // button6.addActionListener(this);
      
       }
     public void actionPerformed(ActionEvent e){
     	if(e.getSource()==item1_1)
     	{Login lg=new Login("LOGIN");//在编译时先把该句注释掉后编译Login等Login编译完后再编译该类
        setVisible(false);
     	}
     	if(e.getSource()==item1_2)
     	{System.exit(0);}
     if(e.getSource()==button1)
     	{StudentInformation si=new StudentInformation("STUDENT INFORMATION");
     	si.setVisible(true);
     	}
     	if(e.getSource()==item2_1)
     	{introduction intro=new introduction("JAVA & DATABASE");
     	intro.setVisible(true);
     	}
     	if(e.getSource()==item2_2)
     	{JOptionPane.showMessageDialog(this,"WELCOME,YOU GUYS! THIS IS A SYSTEM BY GROUP 2",getTitle(), JOptionPane.PLAIN_MESSAGE);
     	}
     	
     	if(e.getSource()==item3_1){
     		TeacherCourse T=new TeacherCourse("TEACHER INFORMATION"); 
     		T.setVisible(true);
     	}
     	if(e.getSource()==item3_2){
     		COURSE C=new COURSE("COURSES"); 
     		C.setVisible(true);
     	}
     	if(e.getSource()==item3_3){
     		ChengjiPaiming cp=new ChengjiPaiming("scores>= ");
     		cp.setVisible(true);}
     	if(e.getSource()==item3_4){
     		CheckCorses cp=new CheckCorses("scores>=");
     		cp.setVisible(true);}
     	if(e.getSource()==item3_5){
     		courses2 cp=new courses2("FAILED 2++ COURSES");
     		cp.setVisible(true);}
     	if(e.getSource()==item3_6){
     		failed_courses c=new failed_courses("FAILED 2++ COURSES");
     		c.setVisible(true);}
     	if(e.getSource()==item3_7){

 		LOWESTSCORE cp=new LOWESTSCORE("LOWEST SCORE");
 		cp.setVisible(true);
     	}
     	if(e.getSource()==item3_8){


     		specialstudent ss=new specialstudent("SPECIALSTUDENT");
     		ss.setVisible(true);
     	}
     	if(e.getSource()==item3_9){

     		StudentInformation1 cp=new StudentInformation1("PROVINCE");
     		cp.setVisible(true);
         	}
         	if(e.getSource()==item3_10){


         		specialstudent1 ss=new specialstudent1("HIGHEST CREDITS");
         		ss.setVisible(true);
         	}
     	if(e.getSource()==button3){
     		Xuankeqingkuang xuanke=new Xuankeqingkuang("COURSE-SELECTION"); 
     		xuanke.setVisible(true);
     	}
     	if(e.getSource()==button2){
     		CourseInformation ci=new CourseInformation("COURSE INFORMATION");
     		ci.setVisible(true);
     	}
     	if(e.getSource()==button4){
     		CheckCorses cs=new CheckCorses("CHECKCOURSE");
     		cs.setVisible(true);}
     		if(e.getSource()==button5){
     			chengjipaiming2 cp=new chengjipaiming2("RANK");
     		cp.setVisible(true);}
     } 
}