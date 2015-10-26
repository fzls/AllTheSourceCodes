//containers
JFrame {
	frame.add(label);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(300, 100);
	frame.setVisible(true);
	frame.setLayout(new FlowLayout());
	frame.setLayout(new BorderLayout()) {//default
		add(BorderLayout.NORTH, new JButton("North"));
		add(BorderLayout.SOUTH, new JButton("South"));
		add(BorderLayout.EAST, new JButton("East"));
		add(BorderLayout.WEST, new JButton("West"));
		add(BorderLayout.CENTER, new JButton("Center"));
	}
	frame.setLayout(new GridLayout(3, 1));
	//MORE COMPLICATED
	frame.setLayout(new GridBagLayout());
	frame.setLayout(new TableLayout());//not in Swing, but can be downloaded from the java.sun.com
	frame.setLayout(new BoxLayout());//simplified version of GridBagLayoout


}

JPanel {
	TitledBorder
}

JScrollPane

JApplet

JWindow

JDialog

//components
JLabel {
	Icons
}

JButton {
	button.addActionListener();
	BasicArrowButton
	JToggleButton
	JCheckBox
	JRadioButton
	ButtonGroup
	AbstractButton
}

setToolTipText(String);

JTextField

Borders

JCheckBox

JRadioButton

JComboBox {
	setEditable();
}

JList {
	getSelectedValues();
}

JTabbedPane

JOptionPane {
	showMessageDialog
	showConfirmDialog
	showOptionDialog
	showInputDialog
}

JPasswordField

JMenuBar {
	JMenu{
		JMenuItem
		JCheckBoxMenuItem
		JRadioButtonMenuItem
	}
	JPopupMenu
}



JTextArea

JMenuItem

JComboBox

JFileChooser


Cursor

//classes

class ButtonListener implements ActionListener {
	public void actionPerformed(ActionEvent e) {
		String name = ((JButton)e.getSource()).getText();
		txt.setText(name);
	}
}


SwingUtilities.invokeLater(new Runnable() {
	public void run() {
		for (int i = 0; i < dhl.labels.length; i++)
			dhl.labels[i].setText("LABEL: " + i);
	}
});

public class SwingConsole {
	public static void run(final JFrame f, final int width, final int height) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				f.setTitle(f.getClass().getSimpleName());
				f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				f.setSize(width, height);
				f.setVisible(true);
			}
		});
	}
}


