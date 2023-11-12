package drawarc;

import javax.swing.*;
import java.awt.*;

public class DrawArc {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setTitle("DrawArc");
        f.setBounds(100, 100, 600, 600);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setContentPane(new MyPanel());
        f.setVisible(true);
    }
}

class MyPanel extends JPanel {
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        int panelWidth = getWidth();

        int rectWidth = 10;
        int rectHeight = 280;
        int rectX = (panelWidth - rectWidth) / 2;
        int rectY = 195;

        g.setColor(Color.GREEN);
        g.fillRect(rectX, rectY, rectWidth, rectHeight);

        int centerX = panelWidth / 2;
        int centerY = rectY;
        int radius = 100;
        int x = centerX - radius;
        int y = centerY - radius;
        int diametre = 2 * radius;
        int arcAngle = 30;
        int startAngle = -45 - arcAngle / 2;

        g.setColor(Color.BLUE);
        for (int i = 0; i < 4; i++) {
            startAngle += 90;
            g.fillArc(x, y, diametre, diametre, startAngle, arcAngle);
        }

        String text = "Welcome to Java world";
        int textX = 20;
        int textY = 440;
        Font font = new Font(Font.DIALOG, Font.PLAIN, 18);

        g.setFont(font);
        g.setColor(Color.BLACK);
        g.drawString(text, textX, textY);
    }
}