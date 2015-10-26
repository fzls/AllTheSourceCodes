import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TeacherCourse extends JFrame implements ActionListener {
	JLabel label1,label6,label7;
	JButton button1,button2;
	JPanel pan1,pan2;
	JComboBox list1,list2,list3;
	Object a[][];
    Object col[]={"��ʦ��","����","�Ա�","ʡ��","����","ϵ�����","ѧԺ����","ְ��","нˮ","�γ�����"};
    JTable table;      //����

    public TeacherCourse(String s) {
    	super(s);
	setBounds(100,100,900,550);
	setVisible(false);
		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
	label1=new JLabel("ѧ��",JLabel.CENTER);
	label6=new JLabel("���̵ȼ�",JLabel.CENTER);
	label7=new JLabel("��ѯ���",JLabel.CENTER);
	list1=new JComboBox();
	list2=new JComboBox();
	list3=new JComboBox();
	list1.addItem("2002");
	list1.addItem("2003");
	list2.addItem("1");
	list2.addItem("2");
	list3.addItem("��");
	list3.addItem("��");
	list3.addItem("����");
	button1=new JButton("��ѯ");
	button2=new JButton("����");
    pan1=new JPanel();
    pan2=new JPanel();
    pan1.add(label1);
	pan1.add(list1);
	pan1.add(list2);
	pan1.add(label6);
	pan1.add(list3);
    a=new Object[25][10];
	table=new JTable(a,col);
JPanel pan3=new JPanel();
	pan3.add(button1);
	pan3.add(button2);
	pan2.setLayout(new BorderLayout());
pan2.add(new JScrollPane(table),BorderLayout.NORTH);
	pan2.add(label7,BorderLayout.CENTER);
	pan2.add(pan3,BorderLayout.SOUTH);
	add(pan1,BorderLayout.SOUTH);
	add(pan2,BorderLayout.CENTER);
	button1.addActionListener(this);
	button2.addActionListener(this);
	validate();

    }
    public void actionPerformed(ActionEvent e1){

String s5=(String)list1.getSelectedItem();
   String s6=(String)list3.getSelectedItem();
   int m=1;
   m=list2.getSelectedIndex()+1;


	if(e1.getSource()==button1){
	 int i=0;
	  for(int j=0;j<20;j++)
 		{
 			for(int x=0;x<9;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}
 	  try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
 	  catch(ClassNotFoundException e2){}
 	  try{
 	  	  Connection con=DriverManager.getConnection ("jdbc:odbc:student2","user2","u002");//����Դ
 	  	   Statement sql=con.createStatement();
 //		  ResultSet rs=sql.executeQuery("select * from teacher");
 		 ResultSet rs=sql.executeQuery("SELECT teacher.*, c_name FROM teacher, tc, course WHERE teacher.t_id = tc.t_id and tc.c_id = course.c_id and teacher.t_id in (select t_id from tc where ayear = '2002' and rating = '��');");
 		  while(rs.next())
 		   {
 		    String cha1=rs.getString(1);
 		    String cha2=rs.getString(2);
 		    String cha3=rs.getString(3);
 		    String cha4=rs.getString(5);
 		    String cha5=rs.getString(6);
 		    String cha6=rs.getString(7);
 		    String cha7=rs.getString(8);
 		    String cha8=rs.getString(9);
 		    String cha9=rs.getString(10);
 		    String cha10=rs.getString(11);
 		    
 		 	a[i][0]=cha1;
 		 	a[i][1]=cha2;
 		 	a[i][2]=cha3;
 		 	a[i][3]=cha4;
 		 	a[i][4]=cha5;
 		 	a[i][5]=cha6;
 		 	a[i][6]=cha7;
 		 	a[i][7]=cha8;
 		 	a[i][8]=cha9;
 		 	a[i][9]=cha10;
 		 	
 		 	i++;
 		   }pack();
 		   con.close();
	}catch(SQLException e3){}
}
else if(e1.getSource()==button2)
 	{

 	label7.setForeground(Color.black);
 		label7.setText("���¿�ʼ��ѯ");

 		for(int j=0;j<25;j++)
 		{
 			for(int x=0;x<7;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}

 		}
}

}