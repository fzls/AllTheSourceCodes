package database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Silence on 2015/12/13.
 */
public class UpdateModule {
    private JButton 学院信息Button;
    private JButton 系别信息Button;
    private JButton 课程信息Button;
    private JButton 学生信息Button;
    private JButton 学生选课信息Button;
    private JButton 教师信息Button;
    private JButton 教师授课信息Button;
    private JButton 用户信息Button;
    private JButton 退出Button;
    private JPanel panel;
    private JFrame frame;

    public UpdateModule() {
        frame = new JFrame("UpdateModule");
        frame.setContentPane(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
        学院信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                UpdateCollege updateCollege = new UpdateCollege();
            }
        });
        系别信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
                UpdateDepartment updateDepartment = new UpdateDepartment();
            }
        });
        课程信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
//                UpdateClass updateClass = new UpdateClass();
            }
        });
        学生信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
//                UpdateStudent updateStudent = new UpdateStudent();
            }
        });
        学生选课信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
//                UpdateStudentTimetable updateStudentTimetable = new UpdateStudentTimetable();
            }
        });
        教师信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
//                UpdateTeacher updateTeacher = new UpdateTeacher();
            }
        });
        教师授课信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
//                UpdateTeacherTimetable updateTeacherTimetable = new UpdateTeacherTimetable();
            }
        });
        用户信息Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //TODO
//                UpdateUser updateUser = new UpdateUser();
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
        UpdateModule updateModule = new UpdateModule();

    }
}
