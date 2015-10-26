import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class teachercourse1 extends JFrame implements ActionListener {
	JLabel label1,label6,label7;
	JButton button1,button2;
	
	JPanel pan1,pan2;
	JComboBox list1,list3;
	Object a[][];
    Object col[]={"教师号","姓名","课程代码","课程名称","学期","学年","评教等级"};
    JTable table;      //建表

    public teachercourse1(String s) {
    	super(s);
	setBounds(100,100,900,550);
	setVisible(false);
		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
	label1=new JLabel("学年",JLabel.CENTER);
	list1=new JComboBox();

	list3=new JComboBox();
	label6=new JLabel("评教等级",JLabel.CENTER);
	label7=new JLabel("查询结果",JLabel.CENTER);
	list1=new JComboBox();
	
	
//	list4=new JComboBox();
	list1.addItem("2002");
	list1.addItem("2003");
	list1.addItem("2004");
	list1.addItem("2005");
	list1.addItem("2006");
	list1.addItem("2007");
	list1.addItem("2008");
	list1.addItem("2009");
	list1.addItem("2010");
	list1.addItem("2011");
	
//	list2.addItem("1");
//	list2.addItem("2");
	list3.addItem("优");
	list3.addItem("良");
	list3.addItem("及格");
	
	button1=new JButton("查询");
	button2=new JButton("重置");
    pan1=new JPanel();
    pan2=new JPanel();
    pan1.add(label1);
	pan1.add(list1);


	
	

	pan1.add(label6);
	pan1.add(list3);
//	pan1.add(button1);
//	pan1.add(button2);
    a=new Object[25][7];
	table=new JTable(a,col);
JPanel pan3=new JPanel();
	pan3.add(button1);
	pan3.add(button2);
	pan2.setLayout(new BorderLayout());
//	pan2.add(new JScrollPane(table),BorderLayout.CENTER);
//	pan2.add(label7,BorderLayout.NORTH);
pan2.add(new JScrollPane(table),BorderLayout.SOUTH);
	pan2.add(label7,BorderLayout.CENTER);
	pan2.add(pan3,BorderLayout.NORTH);
	add(pan1,BorderLayout.NORTH);
	add(pan2,BorderLayout.CENTER);
	button1.addActionListener(this);
	button2.addActionListener(this);
	validate();

    }
    public void actionPerformed(ActionEvent e1){
	
//	String s5=text5.getText();
//	String s6=text6.getText();
String s5=(String)list1.getSelectedItem();//下拉列表选择
   String s6=(String)list3.getSelectedItem();
  
   
 //int m=1;
    //  m=list2.getSelectedItem();

	if(e1.getSource()==button1){
	 int i=0;
	  for(int j=0;j<20;j++)//将新的结果写上去
 		{
 			for(int x=0;x<7;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}
 	  try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
 	  catch(ClassNotFoundException e2){}
 	  try{
 	  	  Connection con=DriverManager.getConnection ("jdbc:odbc:mydb","1","setting");//数据源
 	  	   Statement sql=con.createStatement();
 		  ResultSet rs=sql.executeQuery("SELECT tc.T_id, T_name,tc.C_id,C_name,Semester,Ayear,Rating FROM  tc, teacher,course WHERE tc.T_id=teacher.T_id AND tc.C_id=course.C_id AND Rating LIKE '%"+s6+"%' AND tc.Ayear LIKE '%"+s5+"%'");
 		 //
 		  while(rs.next())
 		   {
 		    String jiaoshihao=rs.getString(1);
 		    String xingming=rs.getString(2);
 		    String kechengdaima=rs.getString(3);
 		  //  Date chushengnianyue=rs.getDate(4);
 		    String kechengmingcheng=rs.getString(4);
 		    String xuexi=rs.getString(5);
 		    String xuenian=rs.getString(6);
 		    String pingjiaodengji=rs.getString(7);
 		  //  String xinshui=rs.getString(9);
 		  //  Date ruxiaoshijian=rs.getDate(6);
 		 	a[i][0]=jiaoshihao;a[i][1]=xingming;a[i][2]=kechengdaima;
 		 	a[i][3]=kechengmingcheng;a[i][4]=xuexi;a[i][5]=xuenian;a[i][6]=pingjiaodengji;
 		 //	a[i][7]=zhicheng;//a[i][8]=xinshui;
 		 	i++;
 		   }pack();
 		   con.close();
 		   label7.setForeground(Color.red);
 		   label7.setText("查到了"+i+"条记录");
	}catch(SQLException e3){}
}
else if(e1.getSource()==button2)
 	{
 		
 	//	text5.setText(null);
 	//	text6.setText(null);
 	label7.setForeground(Color.black);
 		label7.setText("重新开始查询");

 		for(int j=0;j<25;j++)
 		{
 			for(int x=0;x<7;x++ )
 			{a[j][x]="";
 			repaint();//清空表格
 			}
 		}

 		}
}

}

