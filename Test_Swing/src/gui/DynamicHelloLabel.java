//: gui/E02_DynamicHelloLabel.java
/******************** Exercise 02 ************************
* Modify HelloLabel.java to show that label addition is
* dynamic, by adding a random number of labels.
*********************************************************/
package gui;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.util.concurrent.*;
class DynamicHelloLabel extends JFrame {
	private static Random rnd = new Random(47);
	JLabel[] labels;
	DynamicHelloLabel() {
		super("Hello Label");
		setLayout(new FlowLayout());
		int numOfLabels = rnd.nextInt(100) + 1;
		labels = new JLabel[numOfLabels];
		for (int i = 0; i < numOfLabels; i++)
			add(labels[i] = new JLabel("label: " + i));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(300, 100);
		setVisible(true);
	}
}
