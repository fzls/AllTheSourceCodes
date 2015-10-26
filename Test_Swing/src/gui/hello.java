package gui;
import javax.swing.*;

public class hello {

	public static void main(String[] args) {
		JFrame frame = new JFrame("hello world");
		JLabel label = new JLabel("a label");
		frame.add(label);
//		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 100);
		frame.setVisible(true);
		
	}

}
