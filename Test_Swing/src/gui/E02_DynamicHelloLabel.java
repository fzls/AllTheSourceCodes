package gui;

import java.util.concurrent.TimeUnit;

import javax.swing.SwingUtilities;

public class E02_DynamicHelloLabel {
	static DynamicHelloLabel dhl;
	public static void main(String[] args) throws Exception {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() { dhl = new DynamicHelloLabel(); }
		});
		TimeUnit.SECONDS.sleep(2);
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				for (int i = 0; i < dhl.labels.length; i++)
					dhl.labels[i].setText("LABEL: " + i);
			}
		});
	}
} ///:~