import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CollegeCheck extends JFrame implements ActionListener {
	JButton button1,button2;
	JLabel label1,label2,label3,label4,label5;
	JTextField text1,text2,text3,text4;
	JPanel pan1,pan2,pan3;
	Object a[][];
    Object col[]={"学院代码","学院名称","系别代码","系别名称"};
    JTable table;      //建表

    public CollegeCheck(String s) {
    	super(s);
	setBounds(200,150,700,550);
	setVisible(false);
		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
    	button1=new JButton("确定");
    	button2=new JButton("重置");
    	label1=new JLabel("学院代码",JLabel.CENTER);
    	label2=new JLabel("学院名称",JLabel.CENTER);
    	label3=new JLabel("系别代码",JLabel.CENTER);
    	label4=new JLabel("系别名称",JLabel.CENTER);
    	label5=new JLabel("查询结果",JLabel.CENTER);
    	text1=new JTextField(8);
    	text2=new JTextField(8);
    	text3=new JTextField(8);
    	text4=new JTextField(8);
    	pan1=new JPanel();
    	pan2=new JPanel();
    	pan3=new JPanel();
    	pan1.add(label1);
    	pan1.add(text1);
    	pan1.add(label2);
    	pan1.add(text2);
    	pan1.add(label3);
    	pan1.add(text3);
    	pan1.add(label4);
    	pan1.add(text4);
    	pan2.add(button1);
    	pan2.add(button2);
    	pan3.setLayout(new BorderLayout());
    //	pan3.add(label5,BorderLayout.NORTH);
    //	pan3.add(table,BorderLayout.CENTER);
    	a=new Object[25][4];
	    table=new JTable(a,col);
	    pan3.add(new JScrollPane(table),BorderLayout.SOUTH);
	pan3.add(label5,BorderLayout.CENTER);
	pan3.add(pan2,BorderLayout.NORTH);
	add(pan1,BorderLayout.NORTH);
	add(pan3,BorderLayout.CENTER);
	button1.addActionListener(this);
	button2.addActionListener(this);
	validate();


    }
     public void actionPerformed(ActionEvent e1){
	String s1=text1.getText();
	String s2=text2.getText();
	String s3=text3.getText();
	String s4=text4.getText();
//	String s5=text5.getText();
//	String s6=text6.getText();
	if(e1.getSource()==button1){
	 int i=0;
	  for(int j=0;j<20;j++)//将新的结果写上去
 		{
 			for(int x=0;x<4;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}
 	  try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
 	  catch(ClassNotFoundException e2){}
 	  try{
 	  	  Connection con=DriverManager.getConnection ("jdbc:odbc:mydb","1","setting");//数据源
 	  	   Statement sql=con.createStatement();
 		  ResultSet rs=sql.executeQuery("SELECT college.Col_id,Col_namme,Dept_id,Dept_name FROM college,department WHERE college.Col_id=department.Col_id AND college.Col_id LIKE '%"+s1+"%' AND Col_namme LIKE '%"+s2+"%' AND Dept_id LIKE '%"+s3+"%' AND Dept_name LIKE '%"+s4+"%'");
 		  // ResultSet rs=sql.executeQuery("SELECT college.Col_id,Col_namme,Dept_id,Dept_name FROM college,department WHERE college.Col_id=department.Col_id AND college.Col_id=s1 AND Col_namme=s2 AND Dept_id=s3 AND Dept_name=s4");
 		  while(rs.next())
 		   {
 		    String xueyuandaima=rs.getString(1);
 		    String xueyuanmingcheng=rs.getString(2);
 		    String xibiedaima=rs.getString(3);
 		  //  Date chushengnianyue=rs.getDate(4);
 		    String xibiemingcheng=rs.getString(4);
 		    //String xuexi=rs.getString(5);
 		    //String xuenian=rs.getString(6);
 		   // String pingjiaodengji=rs.getString(7);
 		  //  String xinshui=rs.getString(9);
 		  //  Date ruxiaoshijian=rs.getDate(6);
 		 	a[i][0]=xueyuandaima;a[i][1]=xueyuanmingcheng;a[i][2]=xibiedaima;
 		 	a[i][3]=xibiemingcheng;//a[i][4]=xuexi;a[i][5]=xuenian;a[i][6]=pingjiaodengji;
 		 //	a[i][7]=zhicheng;//a[i][8]=xinshui;
 		 	i++;
 		   }pack();
 		   con.close();
 		  // label5.setForeground(Color.red);
 		 //  label5.setText("查到了"+i+"个人");
	}catch(SQLException e3){}
}
else if(e1.getSource()==button2)
 	{
 		text1.setText(null);
 		text2.setText(null);
 		text3.setText(null);
 		text4.setText(null);
 	//	text5.setText(null);
 	//	text6.setText(null);
 	    label5.setForeground(Color.black);
 		label5.setText("重新开始查询");

 		for(int j=0;j<25;j++)
 		{
 			for(int x=0;x<4;x++ )
 			{a[j][x]="";
 			repaint();//清空表格
 			}
 		}

 		}
}


}