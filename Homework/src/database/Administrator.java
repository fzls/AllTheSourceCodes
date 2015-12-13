package database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by 风之凌殇 on 2015/12/13.
 */
public class Administrator {
    private JButton 更新Button;
    private JButton 添加Button;
    private JButton 删除Button;
    private JButton 退出Button;
    private JPanel panel;
    private JFrame frame;

    public Administrator() {
        frame = new JFrame("Administrator");
        frame.setContentPane(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);

        更新Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                UpdateModule updateModule = new UpdateModule();
            }
        });

        添加Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
                AddModule addModule = new AddModule();
            }
        });


        删除Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
                RemoveModule removeModule = new RemoveModule();
            }
        });
        退出Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.setVisible(false);
            }
        });
    }

    public static void main(String[] args) {
        Administrator administrator = new Administrator();
    }
}
