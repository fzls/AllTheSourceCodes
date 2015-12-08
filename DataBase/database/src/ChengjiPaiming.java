import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ChengjiPaiming extends JFrame implements ActionListener {
  JLabel label1, label2, label3, label4, label5, label6;
  JButton button1, button2;
  JComboBox list1, list2;
  JTextField text1, text2;
  JPanel panel1 = new JPanel();
  JPanel panel2 = new JPanel();
  Object a[][];
//Object col[]={"课程号","选课人数","最高分","最低分","平均分","分数段人数"};
  Object col[] = {"ID", "NAME", "RANK"};
  JTable table;      //建表
//Connection ccon;
//Statement sql; ResultSet rs;

  public ChengjiPaiming(String s) {
    super(s);
    setBounds(150, 50, 1000, 618);
    setVisible(false);
    Toolkit tool = this.getToolkit();
    Image image = tool.getImage("login.png");
    this.setIconImage(image);
    label2 = new JLabel("DEPARTMENT", JLabel.CENTER);
    label1 = new JLabel("YEAR", JLabel.CENTER);
//  label3=new JLabel("分数",JLabel.CENTER);
//  label4=new JLabel("FROM",JLabel.CENTER);
//  label5=new JLabel("TO",JLabel.CENTER);
    label6 = new JLabel("RESULTS", JLabel.CENTER);
    button1 = new JButton("QUERY");
    button2 = new JButton("RESET");
//  text1=new JTextField(4);
//  text2=new JTextField(4);
    list1 = new JComboBox();
    //  list2=new JComboBox();
    list1.addItem("2002");
    list1.addItem("2009");
    list1.addItem("2010");
    list1.addItem("2011");
    text1 = new JTextField(8);
    /*   list2.addItem("信息管理");
       list2.addItem("英语");
       list2.addItem("中文");
       list2.addItem("金融");
       list2.addItem("数学");
       list2.addItem("心理");
       list2.addItem("建筑");
       list2.addItem("艺术");
       list2.addItem("经济");*/
    a = new Object[25][6];
    table = new JTable(a, col); //完成建表
    //panel1.setLayout(new)
    panel1.add(label1);
    panel1.add(list1);
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
    panel2.add(new JScrollPane(table), BorderLayout.CENTER); //加滚动条
    panel2.add(label6, BorderLayout.NORTH);
    add(panel1, BorderLayout.NORTH);
    add(panel2, BorderLayout.CENTER);
    button1.addActionListener(this);
    button2.addActionListener(this);
    validate();
  }
  public void actionPerformed(ActionEvent e1) {
//  String s1=text1.getText();
    String s2 = text1.getText();
//  float m=Float.parseFloat(s1);//转换数据类型
//  float n=Float.parseFloat(s2);

    String s1 = (String)list1.getSelectedItem(); //下拉列表选择，年份
    // String s2=(String)list2.getSelectedItem();//不加（String）数据类型不兼容
    if (e1.getSource() == button1) {
      int i = 0;
      for (int j = 0; j < 20; j++) { //将新的结果写上去
        for (int x = 0; x < 6; x++ ) {
          a[j][x] = "";
          repaint();
        }
      }
      try {Class. forName ( "sun.jdbc.odbc.JdbcOdbcDriver" );}
      catch (ClassNotFoundException e2) {} //建立JDBC-ODBC桥接器
      try {
        Connection con = DriverManager.getConnection ("jdbc:odbc:student2", "user2", "u002"); //数据源
        Statement sql = con.createStatement();
        ResultSet rs = sql.executeQuery("SELECT distinct student.* FROM sc,student where sc.s_id =student.s_id and  Ayear LIKE '%" + s1 + "%' ");
        while (rs.next()) {
          String xingming = rs.getString(1);
          String xuehao = rs.getString(2);

          // Date chushengnianyue=rs.getDate(4);


          String GPA = String('i');
          //   String fenshuduanrenshu=rs.getString(6);
          // Date ruxiaoshijian=rs.getDate(6);
          a[i][0] = xingming; a[i][1] = xuehao;
          a[i][2] = i + 1;
          i++;
        } pack();
        con.close();
        label6.setForeground(Color.red);
        label6.setText("RESULT");
      } catch (SQLException e3) {}
    } else if (e1.getSource() == button2) {
      text1.setText(null);
      //  text2.setText(null);
      //text3.setText(null);
      label6.setForeground(Color.black);
      label6.setText("REQUERY");

      for (int j = 0; j < 25; j++) {
        for (int x = 0; x < 6; x++ ) {
          a[j][x] = "";
          repaint();//清空表格
        }
      }

    }
  }
  private String String(char charAt) {
    // TODO Auto-generated method stub
    return null;
  }


}
