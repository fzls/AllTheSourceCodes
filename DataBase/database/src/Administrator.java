import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.util.Date;
import java.text.SimpleDateFormat;
public class Administrator extends JFrame implements ActionListener {
	JMenuBar menubar;
    JMenu menu1,menu2;
    JMenuItem item1_1,item1_2,item2_1,item2_2;
    JButton button1,button2,button3,button4,button5,button6;
    JLabel label1,label2;
    JToolBar toolbar;
    JSplitPane split;
    Date nowTime=new Date();

    public Administrator(String s) {
    	super(s);
    	setBounds(450,200,420,400);
    	setVisible(false);
    		Toolkit tool=this.getToolkit();
	Image image=tool.getImage("login.png");
	this.setIconImage(image);
    //	setLayout(new FlowLayout());
    	validate();
    	Icon icon=new ImageIcon("����Ա.jpg");
    	menubar=new JMenuBar();
    	menu1=new JMenu("����");
    	menu2=new JMenu("����");
    	item1_1=new JMenuItem("���µ���");
    	item1_2=new JMenuItem("�˳�");
    	item2_1=new JMenuItem("ʹ�ð���");
    	item2_2=new JMenuItem("����ϵͳ");
    //	label1=new JLabel("xianzaishijianshi",JLabel.RIGHT);
    	label1=new JLabel(icon);
    	SimpleDateFormat matter=new SimpleDateFormat("���˴ε����ʱ����:yyyy��MM��dd��HHʱmm��");//ʱ�䲻��䣿��
        label2=new JLabel(matter.format(nowTime),JLabel.CENTER);
    	button1=new JButton("�޸Ŀγ���Ϣ");
    //	button2=new JButton("ɾ���γ���Ϣ");
    /*	button3=new JButton("�ɼ���ѯ");
    	button4=new JButton("�γ̲�ѯ");
    	button5=new JButton("ѡ�β�ѯ");
    	button6=new JButton("Ժϵ��ѯ");*/
    	button1.setToolTipText("�޸Ŀγ���Ϣ");
    //	button2.setToolTipText("ɾ���γ���Ϣ");
    /*	button3.setToolTipText("��ѯ����");
    	button4.setToolTipText("��ѯ����");
    	button5.setToolTipText("��ѯ����");
    	button6.setToolTipText("��ѯ����");*/
    //	panel=new JPanel();
        toolbar=new JToolBar();
    //	panel.setLayout(new GridLayout(2,3));
    /*	panel.add(button1);
    	panel.add(button2);
    	panel.add(button3);
    	panel.add(button4);
    	panel.add(button5);
    	panel.add(button6);*/
    	toolbar.add(button1);
    //	toolbar.add(button2);
    //	toolbar.add(button3);
    //	toolbar.add(button4);
    //	toolbar.add(button5);
    //	toolbar.add(button6);
    	menu1.add(item1_1);
    	menu1.add(item1_2);
    	menu2.add(item2_1);
    	menu2.add(item2_2);
    	menubar.add(menu1);
    	menubar.add(menu2);
    	/*setJMenuBar(menubar);
    	add(label1);
    	add(label2);
    	add(panel);*/
    	split=new JSplitPane(JSplitPane.VERTICAL_SPLIT,menubar,toolbar);
       add(split,BorderLayout.NORTH);
      add(label1,BorderLayout.CENTER);
       add(label2,BorderLayout.SOUTH);
        item1_1.addActionListener(this);
      item1_2.addActionListener(this);
      item2_1.addActionListener(this);
      item2_2.addActionListener(this);
      button1.addActionListener(this);
    //  button2.addActionListener(this);
    }

     public void actionPerformed(ActionEvent e){
     	if(e.getSource()==item1_1)
     	{Login lg=new Login("�û�����");//�ڱ���ʱ�ȰѸþ�ע�͵������Login��Login��������ٱ������
        setVisible(false);
     	}
     	if(e.getSource()==item1_2)
     	{System.exit(0);}

     	if(e.getSource()==item2_1)
     	{introduction_2 intro=new introduction_2("���ܽ���");
     	intro.setVisible(true);
     	}
     	if(e.getSource()==item2_2)
     	{JOptionPane.showMessageDialog(this,"                 �����ѯϵͳ\n                 �ڶ�С��(�Ź�0901�� ����\n                 ��Ա�����ַ� �ɳ�Զ\n                 ����� ���� ����\n                 ��ϵ���䣺3090102377@zju.edu.cn ","���ݿ��ѯϵͳ",JOptionPane.PLAIN_MESSAGE);
     	}
     	if(e.getSource()==button1)
     	{Update t=new Update("�γ���Ϣ�޸�");
     	t.setVisible(true);
     	}
     //	if(e.getSource()==button3){
     	//	TeacherCourse tc=new TeacherCourse("�������");
     //		tc.setVisible(true);
     	//}*/


     }
}