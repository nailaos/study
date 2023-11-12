package colorword;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ColorWord {
    public static void main(String[] args) {
        JFrame frame = new JFrame("ColorWord");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTextField text = new JTextField("Welcome to java world");
        Font font = new Font(Font.DIALOG, Font.BOLD, 18);
        text.setFont(font);
        text.setEditable(false);
        text.setHorizontalAlignment(JTextField.CENTER);

        ButtonGroup group = new ButtonGroup();
        JRadioButton red = new JRadioButton("red");
        JRadioButton blue = new JRadioButton("blue");
        JRadioButton black = new JRadioButton("black");
        group.add(red);
        group.add(blue);
        group.add(black);

        red.addActionListener(new ColorChangeListener(text, Color.RED));
        blue.addActionListener(new ColorChangeListener(text, Color.BLUE));
        black.addActionListener(new ColorChangeListener(text, Color.BLACK));
        red.setEnabled(true);
        blue.setEnabled(true);
        black.setEnabled(true);

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(text, BorderLayout.CENTER);

        JPanel radioPanel = new JPanel();
        radioPanel.add(red);
        radioPanel.add(blue);
        radioPanel.add(black);
        panel.add(radioPanel, BorderLayout.NORTH);

        frame.getContentPane().add(panel);
        frame.setSize(800, 300);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

class ColorChangeListener implements ActionListener {
    private JTextField text;
    private Color color;

    public ColorChangeListener(JTextField text, Color color) {
        this.text = text;
        this.color = color;
    }

    public void actionPerformed(ActionEvent e) {
        text.setForeground(color);
    }
}