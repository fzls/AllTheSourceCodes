import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Update extends JFrame implements ActionListener  {
  JLabel label1, label2, label3, label4, label5;
  JButton button1, button2;
  JTextField text1, text2, text3;
  JPanel pan1, pan2;
//  JComboBox list;
  Object a[][];
  //  Object col[]={"�γ̴���","�γ�����","ѧ��","ѧ��","ѧ��"};
  Object col[] = {"�γ̴���", "�γ�����", "ѧ��"};
  JTable table;      //����
  public Update(String s) {
    super(s);
    setBounds(450, 200, 650, 450);
    setVisible(false);
    Toolkit tool = this.getToolkit();
    Image image = tool.getImage("login.png");
    this.setIconImage(image);
    label1 = new JLabel("�γ̴���", JLabel.CENTER);
    label2 = new JLabel("�γ�����", JLabel.CENTER);
    label3 = new JLabel("ѧ��", JLabel.CENTER);
//  label4=new JLabel("ѧ��",JLabel.CENTER);
    label5 = new JLabel("���½��", JLabel.CENTER);
//  list=new JComboBox();
//  list.addItem("2008");
//  list.addItem("2009");
/// list.addItem("2010");
//  list.addItem("2011");
    text1 = new JTextField(8);
    text2 = new JTextField(8);
    text3 = new JTextField(8);
    button1 = new JButton("���");
    button2 = new JButton("����");
    pan1 = new JPanel();
    pan2 = new JPanel();
    pan1.add(label1);
    pan1.add(text1);
    pan1.add(label2);
    pan1.add(text2);
    pan1.add(label3);
    pan1.add(text3);
//  pan1.add(label4);
//  pan1.add(list);
    pan1.add(button1);
    pan1.add(button2);
    a = new Object[25][3];
    table = new JTable(a, col);
    pan2.setLayout(new BorderLayout());
    pan2.add(new JScrollPane(table), BorderLayout.CENTER);
    pan2.add(label5, BorderLayout.NORTH);
    add(pan1, BorderLayout.NORTH);
    add(pan2, BorderLayout.CENTER);
    button1.addActionListener(this);
    button2.addActionListener(this);
    validate();
  }
  public void actionPerformed(ActionEvent e1) {
    String s1 = text1.getText();
    String s2 = text2.getText();
    String s3 = text3.getText();
//  String s4;
//  String s4=(String)list.getSelectedItem();
    int m = Integer.parseInt(s3); //ѧ��
//  int n=Integer.parseInt(s4);//ѧ��
//   int a=0;
//    a=list.getSelectedIndex();
    //  a2=b.getSelectedIndex();
    /*   switch(a){
       case 0;s4="2008";break;
       case 1;s4="2009";break;
       case 2;s4="2010";break;
       case 3;s4="2011";break;
      // case 0;s4="2008";break;
      }*/
    if (e1.getSource() == button1) {
      int i = 0;
      for (int j = 0; j < 20; j++) { //���µĽ��д��ȥ
        for (int x = 0; x < 3; x++ ) {
          a[j][x] = "";
          repaint();
        }
      }
      ResultSet rs;
      try {Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
      catch (ClassNotFoundException e2) {}
      try {
        Connection con = DriverManager.getConnection ("jdbc:odbc:student2", "user2", "u002"); //����Դ
        Statement sql = con.createStatement();
        String record = "(" + "'" + s1 + "'" + "," + "'" + s2 + "'" + "," + m + ")";
        String insert = "INSERT INTO course VALUES " + record;

        //  String delete="DELETE��FROM course WHERE C_name='s2'";
        // sql.executeUpdate("INSERT INTO course VALUES ('s1','s2',m)");
        sql.executeUpdate(insert);
        //sql.executeUpdate(delete);
        rs = sql.executeQuery("SELECT * FROM course");
        while (rs.next()) {
          String kechengdaima = rs.getString(1);
          String kechengmingcheng = rs.getString(2);
          String xuefen = rs.getString(3);
          //Date chushengnianyue=rs.getDate(4);
          // String xueqi=rs.getString(4);
          // Date ruxiaoshijian=rs.getDate(6);
          //  String xuenian=rs.getString(5);
          a[i][0] = kechengdaima; a[i][1] = kechengmingcheng; a[i][2] = xuefen;
          // a[i][3]=xueqi;a[i][4]=xuenian;//a[i][5]=ruxiaoshijian;
          i++;
        } pack();
        con.close();
        //label5.setForeground(Color.red);
        //label5.setText("��ѯ���:�鵽��"+i+"����");
      } catch (SQLException e3) {}
    }

    else if (e1.getSource() == button2) {
      /* text1.setText(null);
      text2.setText(null);
      text3.setText(null);
      label5.setForeground(Color.black);
      label5.setText("���¿�ʼ��ѯ");
      */
      for (int j = 0; j < 25; j++) {
        for (int x = 0; x < 3; x++ ) {
          a[j][x] = "";
          repaint();//��ձ��
        }
      }
    }
    ResultSet rs;
    try {Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
    catch (ClassNotFoundException e2) {}
    try {
      Connection con = DriverManager.getConnection ("jdbc:odbc:mydb", "1", "setting"); //����Դ
      Statement sql = con.createStatement();
      //String record="("+"'"+s1+"'"+","+"'"+s2+"'"+","+m+")";
      // String insert="INSERT INTO course VALUES"+record;
      // String kechengmingcheng;
      // String xuefen;
      String update = "UPDATE course SET Credit=" + m + " WHERE C_name=" + "'" + s2 + "'";
      //  String delete="DELETE��FROM course WHERE kechengmingcheng='s2'";
      // sql.executeUpdate("INSERT INTO course VALUES ('s1','s2',m)");
      sql.executeUpdate(update);
      //sql.executeUpdate(delete);
      rs = sql.executeQuery("SELECT * FROM course");
      int i = 0;
      while (rs.next()) {
        String kechengdaima = rs.getString(1);
        String kechengmingcheng = rs.getString(2);
        String xuefen = rs.getString(3);
        //Date chushengnianyue=rs.getDate(4);
        // String xueqi=rs.getString(4);
        // Date ruxiaoshijian=rs.getDate(6);
        //  String xuenian=rs.getString(5);
        a[i][0] = kechengdaima; a[i][1] = kechengmingcheng; a[i][2] = xuefen;
        // a[i][3]=xueqi;a[i][4]=xuenian;//a[i][5]=ruxiaoshijian;
        i++;
      } pack();
      con.close();
      //label5.setForeground(Color.red);
      //label5.setText("��ѯ���:�鵽��"+i+"����");
    } catch (SQLException e3) {}

  }

}
