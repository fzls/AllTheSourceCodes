import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class specialstudent extends JFrame implements ActionListener {
	JLabel label2,label3,label4,label5,label6;
 JButton button1,button2;

 JTextField text1;
 JPanel panel1=new JPanel();
JPanel panel2=new JPanel();
Object a[][];
//Object col[]={"�γ̺�","ѡ������","��߷�","��ͷ�","ƽ����","����������"};
Object col[]={"YEAR","SEMESTER","STUDENT ID","COURSE ID","SCORE"};
JTable table;      //����
//Connection ccon;
//Statement sql; ResultSet rs;

    public specialstudent(String s) {
    	super(s);
    setBounds(150,50,1000,618);
    setVisible(false);
    	Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
    label2=new JLabel("STUDENT ID",JLabel.CENTER);
    
//  label3=new JLabel("����",JLabel.CENTER);
//  label4=new JLabel("FROM",JLabel.CENTER);
//  label5=new JLabel("TO",JLabel.CENTER);
    label6=new JLabel("RESULTS",JLabel.CENTER);
    button1=new JButton("QUERY");
    button2=new JButton("RESET");
//  text1=new JTextField(4);
//  text2=new JTextField(4);
  
    text1=new JTextField(8);
 /*   list2.addItem("��Ϣ����");
    list2.addItem("Ӣ��");
    list2.addItem("����");
    list2.addItem("����");
    list2.addItem("��ѧ");
    list2.addItem("����");
    list2.addItem("����");
    list2.addItem("����");
    list2.addItem("����");*/
    a=new Object[25][6];
    table=new JTable(a,col);//��ɽ���
    //panel1.setLayout(new)
  
   
    panel1.add(label2);
    panel1.add(text1);
//  panel1.add(label3);
//  panel1.add(label4);
//  panel1.add(text1);
//  panel1.add(label5);
//  panel1.add(text2);
    panel1.add(button1);
    panel1.add(button2);
    panel2.setLayout(new BorderLayout());
    panel2.add(new JScrollPane(table),BorderLayout.CENTER);//�ӹ�����
    panel2.add(label6,BorderLayout.NORTH);
    add(panel1,BorderLayout.NORTH);
    add(panel2,BorderLayout.CENTER);
    button1.addActionListener(this);
    button2.addActionListener(this);
    validate();
    }
    public void actionPerformed(ActionEvent e1){
//  String s1=text1.getText();
 String s2=text1.getText();
//  float m=Float.parseFloat(s1);//ת����������
//  float n=Float.parseFloat(s2);

    //�����б�ѡ�����
  // String s2=(String)list2.getSelectedItem();//���ӣ�String���������Ͳ�����
    if(e1.getSource()==button1){
     int i=0;
      for(int j=0;j<20;j++)//���µĽ��д��ȥ
        {
            for(int x=0;x<5;x++ )
            {a[j][x]="";
            repaint();
            }
        }
      try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
      catch(ClassNotFoundException e2){}//����JDBC-ODBC�Ž���
      try{
          Connection con=DriverManager.getConnection ("jdbc:odbc:student2","user2","u002");//����Դ
           Statement sql=con.createStatement();
          ResultSet rs=sql.executeQuery("SELECT * FROM sc WHERE s_id LIKE '%"+s2+"%'  AND s_id not in ( select s_id from SC where score < 60 ) ");
          while(rs.next())
           {
            String xingming=rs.getString(1);
            String xuehao=rs.getString(2);
            String xingbie=rs.getString(3);
           // Date chushengnianyue=rs.getDate(4);
            String xibie=rs.getString(4);
            String xuenian=rs.getString(5);
        
         //   String fenshuduanrenshu=rs.getString(6);
           // Date ruxiaoshijian=rs.getDate(6);
            a[i][0]=xingming;a[i][1]=xuehao;a[i][2]=xingbie;
            a[i][3]=xibie;a[i][4]=xuenian;
            i++;
           }pack();
           con.close();
           label6.setForeground(Color.GREEN);
           label6.setText("RANK");
    }catch(SQLException e3){}
}
else if(e1.getSource()==button2)
    {
      
    //  text2.setText(null);
        text1.setText(null);
        label6.setForeground(Color.RED);
        label6.setText("REQUERY");

        for(int j=0;j<25;j++)
        {
            for(int x=0;x<5;x++ )
            {a[j][x]="";
            repaint();//��ձ��
            }
        }

        }
}


}