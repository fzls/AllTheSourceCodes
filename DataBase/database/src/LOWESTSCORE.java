
import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class LOWESTSCORE extends JFrame implements ActionListener{
	JLabel label4,label5;
	JButton button1,button2;
	
	JPanel pan1,pan2;
	JComboBox list;
	Object a[][];
  //  Object col[]={"课程代码","课程名称","学分","学期","学年"};
    Object col[]={"LOWESTSCORE"};
    JTable table;      //建表
    LOWESTSCORE(String s){
	super(s);
	setBounds(150,50,1000,618);
	setVisible(false);
		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
	
	label4=new JLabel("学年",JLabel.CENTER);
	label5=new JLabel("RESULTS",JLabel.CENTER);
	list=new JComboBox();
	list.addItem("2002");
	list.addItem("2003");
	list.addItem("2004");	list.addItem("2005");
	list.addItem("2006");
	list.addItem("2007");
	list.addItem("2008");	list.addItem("2009");list.addItem("2010");
	list.addItem("2011");list.addItem("2012");list.addItem("2013");
	
	button1=new JButton("QUERY");
	button2=new JButton("RESET");
    pan1=new JPanel();
    pan2=new JPanel();
   
	
	

	

//	pan1.add(label4);
//	pan1.add(list);
	pan1.add(button1);
	pan1.add(button2);
    a=new Object[25][5];
	table=new JTable(a,col);
	pan2.setLayout(new BorderLayout());
	pan2.add(new JScrollPane(table),BorderLayout.CENTER);
	pan2.add(label5,BorderLayout.NORTH);
	add(pan1,BorderLayout.NORTH);
	add(pan2,BorderLayout.CENTER);
	button1.addActionListener(this);
	button2.addActionListener(this);
	validate();
//	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//关闭窗口
}
public void actionPerformed(ActionEvent e1){

//	String s4;
//	String s4=(String)list.getSelectedItem();
//	int m=Integer.parseInt(s3);//学分
//	int n=Integer.parseInt(s4);//学年
 //   int a=0;
//    a=list.getSelectedIndex();
    // 	a2=b.getSelectedIndex();
 /*   switch(a){
    case 0;s4="2008";break;
    case 1;s4="2009";break;
    case 2;s4="2010";break;
    case 3;s4="2011";break;
   // case 0;s4="2008";break;
   }*/
	if(e1.getSource()==button1){
	 int i=0;
	  for(int j=0;j<20;j++)//将新的结果写上去
 		{
 			for(int x=0;x<1;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}
 	  try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
 	  catch(ClassNotFoundException e2){}
 	  try{
 	  	  Connection con=DriverManager.getConnection ("jdbc:odbc:student2","user2","u002");//数据源
 	  	   Statement sql=con.createStatement();
 		  ResultSet rs=sql.executeQuery("select top 1 score  from sc order by score asc   ");
 		  while(rs.next())
 		   {
 		    String kechengdaima=rs.getString(1);
 		    //String kechengmingcheng=rs.getString(2);
 		  //  String xuefen=rs.getString(3);
 		    //Date chushengnianyue=rs.getDate(4);
 		 //  String xueqi=rs.getString(4);
 		   // Date ruxiaoshijian=rs.getDate(6);
 		  //String xuenian=rs.getString(5);
 		 	a[i][0]=kechengdaima;//a[i][1]=kechengmingcheng;//a[i][2]=xuefen;
 		 //	a[i][3]=xueqi;a[i][4]=xuenian;//a[i][5]=ruxiaoshijian;
 		 	i++;
 		   }pack();
 		   con.close();
 		   label5.setForeground(Color.GREEN);
 		   label5.setText("THERE ARE "+i+" LOWESTSCORE");
	}catch(SQLException e3){}
}
else if(e1.getSource()==button2)
 	{
 	
 		label5.setForeground(Color.RED);
 		label5.setText("REQUERY");

 		for(int j=0;j<25;j++)
 		{
 			for(int x=0;x<1;x++ )
 			{a[j][x]="";
 			repaint();//清空表格
 			}
 		}

 		}
}
}
