import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.util.Date;
import java.text.SimpleDateFormat;
public class Administrator extends JFrame implements ActionListener {
	JMenuBar menubar;
    JMenu menu1,menu2;
    JMenuItem item1_1,item1_2,item2_1,item2_2;
    JButton button1,button2,button3,button4,button5,button6;
    JLabel label1,label2;
    JToolBar toolbar;
    JSplitPane split;
    Date nowTime=new Date();

    public Administrator(String s) {
    	super(s);
    	setBounds(450,200,420,400);
    	setVisible(false);
    		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
    //	setLayout(new FlowLayout());
    	validate();
    	Icon icon=new ImageIcon("管理员.jpg");
    	menubar=new JMenuBar();
    	menu1=new JMenu("操作");
    	menu2=new JMenu("帮助");
    	item1_1=new JMenuItem("重新登入");
    	item1_2=new JMenuItem("退出");
    	item2_1=new JMenuItem("使用帮助");
    	item2_2=new JMenuItem("关于系统");
    //	label1=new JLabel("xianzaishijianshi",JLabel.RIGHT);
    	label1=new JLabel(icon);
    	SimpleDateFormat matter=new SimpleDateFormat("您此次登入的时间是:yyyy年MM月dd日HH时mm分");//时间不会变？？
        label2=new JLabel(matter.format(nowTime),JLabel.CENTER);
    	button1=new JButton("修改课程信息");
    //	button2=new JButton("删除课程信息");
    /*	button3=new JButton("成绩查询");
    	button4=new JButton("课程查询");
    	button5=new JButton("选课查询");
    	button6=new JButton("院系查询");*/
    	button1.setToolTipText("修改课程信息");
    //	button2.setToolTipText("删除课程信息");
    /*	button3.setToolTipText("查询航班");
    	button4.setToolTipText("查询航班");
    	button5.setToolTipText("查询航班");
    	button6.setToolTipText("查询航班");*/
    //	panel=new JPanel();
        toolbar=new JToolBar();
    //	panel.setLayout(new GridLayout(2,3));
    /*	panel.add(button1);
    	panel.add(button2);
    	panel.add(button3);
    	panel.add(button4);
    	panel.add(button5);
    	panel.add(button6);*/
    	toolbar.add(button1);
    //	toolbar.add(button2);
    //	toolbar.add(button3);
    //	toolbar.add(button4);
    //	toolbar.add(button5);
    //	toolbar.add(button6);
    	menu1.add(item1_1);
    	menu1.add(item1_2);
    	menu2.add(item2_1);
    	menu2.add(item2_2);
    	menubar.add(menu1);
    	menubar.add(menu2);
    	/*setJMenuBar(menubar);
    	add(label1);
    	add(label2);
    	add(panel);*/
    	split=new JSplitPane(JSplitPane.VERTICAL_SPLIT,menubar,toolbar);
       add(split,BorderLayout.NORTH);
      add(label1,BorderLayout.CENTER);
       add(label2,BorderLayout.SOUTH);
        item1_1.addActionListener(this);
      item1_2.addActionListener(this);
      item2_1.addActionListener(this);
      item2_2.addActionListener(this);
      button1.addActionListener(this);
    //  button2.addActionListener(this);
    }

     public void actionPerformed(ActionEvent e){
     	if(e.getSource()==item1_1)
     	{Login lg=new Login("用户登入");//在编译时先把该句注释掉后编译Login等Login编译完后再编译该类
        setVisible(false);
     	}
     	if(e.getSource()==item1_2)
     	{System.exit(0);}

     	if(e.getSource()==item2_1)
     	{introduction_2 intro=new introduction_2("功能介绍");
     	intro.setVisible(true);
     	}
     	if(e.getSource()==item2_2)
     	{JOptionPane.showMessageDialog(this,"                 教务查询系统\n                 第二小组(信管0901） 制作\n                 成员：胡林枫 干诚远\n                 蒋歆宇 李敏 车文\n                 联系邮箱：3090102377@zju.edu.cn ","数据库查询系统",JOptionPane.PLAIN_MESSAGE);
     	}
     	if(e.getSource()==button1)
     	{Update t=new Update("课程信息修改");
     	t.setVisible(true);
     	}
     //	if(e.getSource()==button3){
     	//	TeacherCourse tc=new TeacherCourse("开课情况");
     //		tc.setVisible(true);
     	//}*/


     }
}