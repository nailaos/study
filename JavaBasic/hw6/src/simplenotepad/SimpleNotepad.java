package simplenotepad;

import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.*;
import java.io.*;

public class SimpleNotepad {
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        JTextArea text = new JTextArea();
        JScrollPane myText = new JScrollPane(text);

        panel.add(myText, BorderLayout.CENTER);

        Font myFont = new Font("Arial", Font.PLAIN, 14);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem openFile = new JMenuItem("Open");
        JMenuItem saveFile = new JMenuItem("Save");

        openFile.addActionListener(new OpenFileListener(text));
        saveFile.addActionListener(new SaveFileListener(text));

        fileMenu.add(openFile);
        fileMenu.add(saveFile);
        menuBar.add(fileMenu);

        frame.setJMenuBar(menuBar);

        JLabel label = new JLabel("lvjiaxin's notepad");
        label.setHorizontalAlignment(SwingConstants.RIGHT);
        label.setFont(myFont);

        panel.add(label, BorderLayout.SOUTH);

        frame.add(panel);

        frame.setSize(800, 600);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

class OpenFileListener implements ActionListener {
    private JTextArea text;

    OpenFileListener(JTextArea _text) {
        text = _text;
    }

    public void actionPerformed(ActionEvent f) {
        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(null);
        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try (BufferedReader reader = new BufferedReader(new FileReader(selectedFile))) {
                StringBuilder content = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    content.append(line).append("\n");
                }
                text.setText(content.toString());
            } catch (IOException e) {
                System.out.println(e);
            }
        }
    }
}

class SaveFileListener implements ActionListener {
    private JTextArea text;

    SaveFileListener(JTextArea _text) {
        text = _text;
    }

    public void actionPerformed(ActionEvent f) {
        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showSaveDialog(null);
        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(selectedFile))) {
                writer.write(text.getText());
            } catch (IOException e) {
                System.out.println(e);
            }
        }
    }
}
