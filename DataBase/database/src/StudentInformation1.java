import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class StudentInformation1 extends JFrame implements ActionListener {
JButton button1,button2;
Box box1,box2,basebox;
JLabel label1,label2,label3,label5,label6,label7,label8,label9,label4;
JTextField text1,text2,text3,text5,text6,text7,text8,text9;
JPanel pan1=new JPanel();
JPanel pan2=new JPanel();
Object a[][];
Object col[]={"PROVINCE","DEPARTMENT"};
JTable table;      //建表
Connection ccon;
Statement sql; ResultSet rs;

  public StudentInformation1(String s) {
    super(s);
    setBounds(150,50,1000,618);
    setVisible(false);
    	Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
    Container con=getContentPane();
   
    label6=new JLabel("PROVINCE");
    
    label9=new JLabel("DEPARTMENT");
    label4=new JLabel("RESULTS",JLabel.LEFT);
   
    text5=new JTextField(9);
    text6=new JTextField(8);
   
    text9=new JTextField(8);
    button1=new JButton("QUERY");
    button2=new JButton("RESET");
    box1=Box.createHorizontalBox();
     box2=Box.createHorizontalBox();
  
 box1.add(Box.createHorizontalStrut(8));
box1.add(button1);
box2.add(label6);
box2.add(Box.createHorizontalStrut(8));
     box2.add(text6);
 
 box2.add(Box.createHorizontalStrut(8));
 box2.add(label9);
 box2.add(Box.createHorizontalStrut(8));
     box2.add(text9);
 box2.add(Box.createHorizontalStrut(8));
box2.add(button2);

    basebox=Box.createVerticalBox();
    basebox.add(box1);
    basebox.add(box2);
pan1.add(basebox);
    a=new Object[25][2];
    table=new JTable(a,col);
    pan2.setLayout(new BorderLayout());
    pan2.add(new JScrollPane(table),BorderLayout.CENTER);
    pan2.add(label4,BorderLayout.NORTH);
    con.add(pan1,BorderLayout.NORTH);
    con.add(pan2,BorderLayout.CENTER);
    button1.addActionListener(this);
    button2.addActionListener(this);
    validate();

    }
    public void actionPerformed(ActionEvent e1){

   
    String s5=text6.getText();
   
    String s8=text9.getText();
    if(e1.getSource()==button1){
     int i=0;
      for(int j=0;j<20;j++)//将新的结果写上去
        {
            for(int x=0;x<2;x++ )
            {a[j][x]="";
            repaint();
            }
        }
      try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
      catch(ClassNotFoundException e2){}
      try{
          ccon=DriverManager.getConnection ("jdbc:odbc:student2","user2","u002");//数据源
           sql=ccon.createStatement();
      //rs=sql.executeQuery("SELECT * FROM student WHERE S_id LIKE '%"+s1+"%' AND S_name LIKE '%"+s2+"%' AND S_sex=s3 AND S_birth=s4 AND S_prov LIKE '%"+s5+"%' AND S_region LIKE '%"+s6+"%' AND S_into LIKE '%"+s7+"%' AND Dept_id LIKE '%"+s8+"%'");

        rs=sql.executeQuery("SELECT * FROM student WHERE   S_prov LIKE '%"+s5+"%' AND  Dept_id LIKE '%"+s8+"%'");
          while(rs.next())
           {

            String laizishengfen=rs.getString(5);
           
            String suoshuxibiedaima=rs.getString(8);
           a[i][0]=laizishengfen;a[i][1]=suoshuxibiedaima;
            i++;
           }pack();
           ccon.close();
           label4.setForeground(Color.GREEN);
           label4.setText("THERE ARE"+i+"STUDENTS");
    }catch(SQLException e3){}
}
else if(e1.getSource()==button2)
    {
        
        text6.setText(null);
      
        text9.setText(null);

        label4.setForeground(Color.RED);
        label4.setText("REQUERY");

        for(int j=0;j<25;j++)
        {
            for(int x=0;x<2;x++ )
            {a[j][x]="";
            repaint();//清空表格
            }
        }

        }
}}


