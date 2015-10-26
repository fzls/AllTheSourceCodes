import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CheckCorses extends JFrame implements ActionListener {
JLabel label1,label2,label3,label4,label5,label6;
 JButton button1,button2;
 JComboBox list1,list2;
 JTextField text1,text2;
 JPanel panel1=new JPanel();
JPanel panel2=new JPanel();
JPanel panel3=new JPanel();
Object a[][];
//Object col[]={"�γ̺�","ѡ������","��߷�","��ͷ�","ƽ����","����������"};
Object col[]={"ID","NAME","GENDER","BIRTHDAY","PROVINCE","REGION","MATRICULATION","DEPARTMENT","COLLEGE"};
JTable table;      //����

    public CheckCorses(String s) {
    	super(s);
    	setBounds(150,50,1000,618);
    setVisible(false);
    	Toolkit tool=this.getToolkit();
	Image image=tool.getImage("src//login.png");
	this.setIconImage(image);
    label1=new JLabel("FOR SCORE>=");
    label2=new JLabel("");
    text1=new JTextField(4);

  //  label2=new JLabel("ѡ�޿γɼ�����75����������",JLabel.CENTER);
//    label1=new JLabel("ѧ��",JLabel.CENTER);
//  label3=new JLabel("����",JLabel.CENTER);
//  label4=new JLabel("FROM",JLabel.CENTER);
//  label5=new JLabel("TO",JLabel.CENTER);
    label6=new JLabel("RESULTS",JLabel.CENTER);
    button1=new JButton("QUERY");
    button2=new JButton("RESET");
//  text1=new JTextField(4);
//  text2=new JTextField(4);
/*    list1=new JComboBox();
    list2=new JComboBox();
    list1.addItem("2008");
    list1.addItem("2009");
    list1.addItem("2010");
    list1.addItem("2011");
    list2.addItem("��Ϣ����");
    list2.addItem("Ӣ��");
    list2.addItem("����");
    list2.addItem("����");
    list2.addItem("��ѧ");
    list2.addItem("����");
    list2.addItem("����");
    list2.addItem("����");
    list2.addItem("����");
*///text1=new JTextField(8);
    a=new Object[25][9];
    table=new JTable(a,col);//��ɽ���
    //panel3.setLayout(new)
 //   panel3.add(label1);
  //  panel1.add(list1);
 // panel1.add(label2);
//    panel1.add(list2);
//  panel1.add(label3);
//  panel1.add(label4);
//  panel3.add(text1);
//  panel1.add(label5);
//  panel1.add(text2);
panel1.add(label1);
panel1.add(text1);
panel1.add(label2);
    panel1.add(button1);
    panel1.add(button2);
    panel2.setLayout(new BorderLayout());
    panel2.add(new JScrollPane(table),BorderLayout.CENTER);//�ӹ�����
    panel2.add(label6,BorderLayout.NORTH);
    add(panel1,BorderLayout.NORTH);
    add(panel2,BorderLayout.CENTER);
   // add(panel3,BorderLayout.SOUTH);
    button1.addActionListener(this);
    button2.addActionListener(this);
    validate();
    }
  public void actionPerformed(ActionEvent e1){
//  String s1=text1.getText();
//  String s2=text2.getText();
//  float m=Float.parseFloat(s1);//ת����������
//  float n=Float.parseFloat(s2);

//    String s1=(String)list1.getSelectedItem();//�����б�ѡ��
//   String s2=(String)list2.getSelectedItem();//���ӣ�String���������Ͳ�����
String s=text1.getText();
//float m=Float.parseFloat(s);
    if(e1.getSource()==button1){
     int i=0;
      for(int j=0;j<20;j++)//���µĽ��д��ȥ
        {
            for(int x=0;x<8;x++ )
            {a[j][x]="";
            repaint();
            }
        }
      try{Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
      catch(ClassNotFoundException e2){}//����JDBC-ODBC�Ž���
      try{
          Connection con=DriverManager.getConnection ("jdbc:odbc:student2","user2","u002");//����Դ
           Statement sql=con.createStatement();
           ResultSet rs=sql.executeQuery("SELECT distinct student.* FROM student,sc WHERE student.S_id=sc.S_id AND student.S_id not IN (SELECT S_id FROM sc WHERE score<60)");
          while(rs.next())
           {
            String xingming=rs.getString(1);
            String xuehao=rs.getString(2);
            String xingbie=rs.getString(3);
         //   Date chushengnianyue=rs.getDate(4);
           String suoshuxibie=rs.getString(4);
            String laizishengfen=rs.getString(5);
            String laizidiqu=rs.getString(6);
            String ruxiaonianfen=rs.getString(7);
            String chushengriqi=rs.getString(8);
            String chushengriqi1=rs.getString(9);
           // Date ruxiaoshijian=rs.getDate(6);
            a[i][0]=xingming;a[i][1]=xuehao;a[i][2]=xingbie;
            a[i][3]=suoshuxibie;a[i][4]=laizishengfen;a[i][5]=laizidiqu;
            a[i][6]=ruxiaonianfen;a[i][7]=chushengriqi;a[i][8]=chushengriqi;
            i++;
           }pack();
           con.close();
           label6.setForeground(Color.GREEN);
          label6.setText("THERE ARE "+i+" STUDENTS WHOSE SCORE>="+s);
    }catch(SQLException e3){}
}
else if(e1.getSource()==button2)
    {
     text1.setText(null);
    //  text2.setText(null);
        //text3.setText(null);
        label6.setForeground(Color.RED);
        label6.setText("REQUERY");

        for(int j=0;j<25;j++)
        {
            for(int x=0;x<9;x++ )
            {a[j][x]="";
            repaint();//��ձ��
            }
        }

        }
}

}