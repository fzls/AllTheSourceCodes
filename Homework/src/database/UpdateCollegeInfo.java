package database;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Vector;

/**
 * Created by Silence on 2015/12/12.
 */
public class UpdateCollegeInfo {
    private JTextField old_ID;
    private JTextField ID;
    private JTextField name;
    private JButton 更改Button;
    private JButton 退出Button;
    private JTable tableView;
    private JPanel panel;
    private JScrollPane afterUpdate;
    private JFrame frame;

    public UpdateCollegeInfo() {
        frame = new JFrame("UpdateCollegeInfo");
        frame.setContentPane(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
        tableView.setVisible(false);

        退出Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.setVisible(false);
            }
        });

        更改Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DefaultTableModel tableModel = new DefaultTableModel();
                createTableModel(tableModel);
                tableView.setModel(tableModel);
                try {
                    Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, "failed to load the driver function", "ERROR", JOptionPane.ERROR_MESSAGE);
                }
                try {
                    Connection con = DriverManager.getConnection("jdbc:odbc:fzls", "sa", "test");
                    Statement st = con.createStatement();
                    String old_Col_id = old_ID.getText();
                    String Col_id = ID.getText();
                    String Col_name = name.getText();
                    String query = "UPDATE college  SET Col_id = '" + Col_id + "', Col_name = '" + Col_name + "' WHERE Col_id = '" + old_Col_id + "'";
                    System.out.print("TEST");
                    st.executeUpdate(query);

                    ResultSet rs = st.executeQuery("SELECT * FROM college");
                    while (rs.next()) {
                        Vector vcRows = new Vector();
                        vcRows.addElement(rs.getString(1));
                        vcRows.addElement(rs.getString(2));
                        tableModel.addRow(vcRows);
                    }
                    rs.close();
                    st.close();
                    con.close();
                    tableView.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
                    tableView.setVisible(true);
                    frame.pack();
                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, "failed to excute the SQL statement\n"+ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                }
            }
            private void createTableModel(DefaultTableModel JTableModel) {
                JTableModel.addColumn("Col_id");
                JTableModel.addColumn("Col_name");
            }
        });
    }
    public static void main(String[] args) {
        UpdateCollegeInfo updateCollegeInfo = new UpdateCollegeInfo();
    }
    }



