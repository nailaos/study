import javax.swing.*;
import javax.swing.Timer;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main extends JFrame {

    private JLabel titleLabel;
    private JLabel timeLabel;

    public Main() {
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel titlePanel = new JPanel();
        titlePanel.setBackground(Color.ORANGE);
        titlePanel.setLayout(new FlowLayout(FlowLayout.CENTER));

        titleLabel = new JLabel(getMyTitle());
        titlePanel.add(titleLabel, BorderLayout.CENTER);
        titlePanel.setBorder(BorderFactory.createMatteBorder(0, 0, 2, 0, Color.BLACK));

        timeLabel = new JLabel(getCurrentTime());
        timeLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        titlePanel.add(timeLabel, BorderLayout.EAST);

        Timer timer = new Timer(1000, e -> updateTitle());
        timer.start();

        JPanel contentPanel = new JPanel();

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(titlePanel, BorderLayout.NORTH);
        getContentPane().add(contentPanel, BorderLayout.CENTER);
    }

    private void updateTitle() {
        timeLabel.setText(getCurrentTime());
    }

    private String getCurrentTime() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm");
        return dateFormat.format(new Date());
    }

    private String getMyTitle() {
        // String title = "Weather for ";
        return "Weather for Beijing, CN";
    }

    // private Font getBoldFont(int size) {

    // }

    public static void main(String[] args) {
        Main weatherApp = new Main();
        weatherApp.setVisible(true);
    }
}
