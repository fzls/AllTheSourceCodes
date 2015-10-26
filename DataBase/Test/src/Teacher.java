import java.awt.BorderLayout;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.JToolBar;
public class Teacher extends JFrame implements ActionListener {
	JMenuBar menubar;
    JMenu menu1,menu2,menu3,menu4,menu5,menu6;
    JMenuItem item1_1,item1_2,item2_1,item3_1,item4_1,item5_1;
    JButton button1,button2,button3,button5,button6;
    JLabel label1,label2;
    JToolBar toolbar;
    JSplitPane split;
    Date nowTime=new Date();

    public Teacher(String s) {
    	super(s);
    	setBounds(200,200,420,400);
    	setVisible(false);
    	Toolkit tool=this.getToolkit();
	Image image=tool.getImage("src//����.png");
	this.setIconImage(image); 
    //	setLayout(new FlowLayout());
    	validate();
    	Icon icon=new ImageIcon("src//����.png");
    	menubar=new JMenuBar();
    	menu1=new JMenu("ϵͳ����");
    	menu2=new JMenu("��ʦ��ѯ");
    	menu3=new JMenu("�γ̲�ѯ");
  //  	menu4=new JMenu("���β�ѯ");
 //   	menu5=new JMenu("Ժϵ��ѯ");  	
    	item1_1=new JMenuItem("���µ���");
    	item1_2=new JMenuItem("�˳�");
    	item2_1=new JMenuItem("��ʦ��Ϣ");
    	item3_1=new JMenuItem("�γ���Ϣ");
 //   	item4_1=new JMenuItem("������Ϣ");
 //   	item5_1=new JMenuItem("Ժϵ��Ϣ");
    	label1=new JLabel(icon);
        toolbar=new JToolBar();
    	menu1.add(item1_1);
    	menu1.add(item1_2);
    	menu2.add(item2_1);
    	menu3.add(item3_1);
 //   	menu4.add(item4_1);
 //   	menu5.add(item5_1);
    	menubar.add(menu1);
    	menubar.add(menu2);
    	menubar.add(menu3);
  //  	menubar.add(menu4);
  //  	menubar.add(menu5);
    	split=new JSplitPane(JSplitPane.VERTICAL_SPLIT,menubar,toolbar);
       add(split,BorderLayout.NORTH);
      add(label1,BorderLayout.CENTER);
        item1_1.addActionListener(this);
        item1_2.addActionListener(this);
        item2_1.addActionListener(this);
        item3_1.addActionListener(this);
 //       item4_1.addActionListener(this);
 //       item5_1.addActionListener(this);
 //     item2_2.addActionListener(this);
 //     button1.addActionListener(this);
 //     button2.addActionListener(this);
 //     button3.addActionListener(this);
 //     button4.addActionListener(this);
//      button5.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
     	if(e.getSource()==item1_1)
     	{Login lg=new Login("�û�����");//�ڱ���ʱ�ȰѸþ�ע�͵������Login��Login��������ٱ������
        setVisible(false);
     	}
     	if(e.getSource()==item1_2)
     	{System.exit(0);}
     	
     	if(e.getSource()==item2_1)
     	{TeacherInformation ti=new TeacherInformation("��ʦ��Ϣ��ѯ");
       	ti.setVisible(true);
      	}
     	
     	if(e.getSource()==item3_1){
     		TeacherCourse tc=new TeacherCourse("�������");
     		tc.setVisible(true);
     	}
  //   	if(e.getSource()==item4_1){
  //   		CourseInformation ci=new CourseInformation("�γ���Ϣ");
  //   		ci.setVisible(true);
  //   	}
  //   	if(e.getSource()==item5_1){
  //   		CollegeCheck cc=new CollegeCheck("Ժϵ��ѯ");
  //   		cc.setVisible(true);
  //   	}
     	
     } 
}