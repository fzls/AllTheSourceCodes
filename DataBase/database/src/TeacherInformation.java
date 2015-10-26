import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class TeacherInformation extends JFrame implements ActionListener{
	JButton button1,button2;
    JLabel label1,label2,label3,label4,label5,label6,label7,label8,label9,label10;
    JTextField text1,text2,text3,text4,text5,text6;
    JPanel pan1=new JPanel();
    JPanel pan2=new JPanel();
    JPanel pan3=new JPanel();
    Object a[][];
    Object col[]={"教师号","姓名","性别","省份","地区","系别","学院","职称","薪水"};
    JTable table;      


TeacherInformation(String s){
	super(s);
	setBounds(100,100,580,580);
	setVisible(false);
		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("src//超人.png");
	this.setIconImage(image);
	label7=new JLabel("查询结果",JLabel.CENTER);
	Icon icon=new ImageIcon("超人.jpg");
	label10=new JLabel(icon);
	button1=new JButton("查询");
	button2=new JButton("重置");
	pan1.setLayout(new GridLayout(4,4));
	pan1.add(button1);
	pan1.add(button2);
    a=new Object[25][10];
	table=new JTable(a,col);
	pan2.setLayout(new BorderLayout());
	pan2.add(new JScrollPane(table),BorderLayout.CENTER);
	pan2.add(label7,BorderLayout.NORTH);
	pan3.setLayout(new BorderLayout());
	pan3.add(pan1,BorderLayout.SOUTH);
	pan3.add(pan2,BorderLayout.CENTER);
	add(label10,BorderLayout.NORTH);
	add(pan3,BorderLayout.CENTER);
	button1.addActionListener(this);
	button2.addActionListener(this);
	validate();
}
public void actionPerformed(ActionEvent e1){

	if(e1.getSource()==button1){
	 int i=0;
	  for(int j=0;j<25;j++)
 		{
 			for(int x=0;x<10;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}
 	  try{Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");}
 	  catch(ClassNotFoundException e2){}
 	  try{
 	  	  Connection con=DriverManager.getConnection("jdbc:odbc:student2","user2","u002");
 	  	   Statement sql=con.createStatement();
 		   ResultSet rs=sql.executeQuery("SELECT * FROM teacher"); 
 		  while(rs.next())
 		   {
 		    String jiaoshihao=rs.getString(1);
 		    String xingming=rs.getString(2);
 		    String xingbie=rs.getString(3);
 		    String shengfen=rs.getString(5);
 		    String diqu=rs.getString(6);
 		    String xibie=rs.getString(7);
 		    String xueyuan=rs.getString(8);
 		    String zhicheng=rs.getString(9);
 		    String xinshui=rs.getString(10);
 		 	a[i][0]=jiaoshihao;a[i][1]=xingming;a[i][2]=xingbie;
 		 	a[i][3]=shengfen;a[i][4]=diqu;a[i][5]=xibie;a[i][6]=xueyuan;a[i][7]=zhicheng;
 		 	a[i][8]=xinshui;
 		 	i++;
 		   }pack();
 		   con.close();

	}catch(SQLException e3){}
}
else if(e1.getSource()==button2)
 	{

 		 label7.setForeground(Color.black);
 		label7.setText("重新开始查询");

 		for(int j=0;j<25;j++)
 		{
 			for(int x=0;x<10;x++ )
 			{a[j][x]="";
 			repaint();
 			}
 		}

 		}
}

}