import javax.swing.*;
import javax.swing.border.AbstractBorder;
import java.awt.*;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.*;

public class Weather {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Weather App");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setMinimumSize(new Dimension(1200, 900));

        // 创建和添加主面板
        WeatherAppPanel mainPanel = new WeatherAppPanel();
        frame.getContentPane().add(mainPanel);
        frame.pack();

        frame.setVisible(true);
    }
}

// 主面板
class WeatherAppPanel extends JPanel {
    private TitlePanel titlePanel;
    private CurWeather curweatherPanel;
    private FutWeather futureweatherPanel;
    private AirPollution airPanel;
    private CitySearch cityPanel;
    // 添加其他面板或组件的引用

    public WeatherAppPanel() {
        setLayout(new GridBagLayout());
        setBackground(Color.CYAN);
        GridBagConstraints myGrid = new GridBagConstraints();
        myGrid.insets = new Insets(5, 5, 5, 5);

        titlePanel = new TitlePanel();
        myGrid.gridx = 0;
        myGrid.gridy = 0;
        myGrid.gridwidth = 6;
        myGrid.anchor = GridBagConstraints.NORTH;
        myGrid.fill = GridBagConstraints.HORIZONTAL;
        add(titlePanel, myGrid);

        cityPanel = new CitySearch();
        cityPanel.setBorder(new RoundedBorder());
        myGrid.gridx = 0;
        myGrid.gridy = 1;
        myGrid.gridwidth = 2;
        myGrid.gridheight = 1;
        myGrid.weightx = 2;
        myGrid.weighty = 1;
        myGrid.anchor = GridBagConstraints.SOUTHEAST;
        myGrid.fill = GridBagConstraints.BOTH;
        add(cityPanel, myGrid);

        curweatherPanel = new CurWeather();
        curweatherPanel.setBorder(new RoundedBorder());
        myGrid.gridx = 0;
        myGrid.gridy = 2;
        myGrid.gridwidth = 2;
        myGrid.gridheight = 2;
        myGrid.weightx = 2;
        myGrid.weighty = 2;
        myGrid.anchor = GridBagConstraints.NORTHWEST;
        myGrid.fill = GridBagConstraints.BOTH;
        add(curweatherPanel, myGrid);

        futureweatherPanel = new FutWeather();
        futureweatherPanel.setBorder(new RoundedBorder());
        myGrid.gridx = 2;
        myGrid.gridy = 1;
        myGrid.gridwidth = 4;
        myGrid.gridheight = 4;
        myGrid.weightx = 4;
        myGrid.weighty = 4;
        myGrid.anchor = GridBagConstraints.EAST;
        myGrid.fill = GridBagConstraints.BOTH;
        add(futureweatherPanel, myGrid);

        airPanel = new AirPollution();
        airPanel.setBorder(new RoundedBorder());
        myGrid.gridx = 0;
        myGrid.gridy = 4;
        myGrid.gridwidth = 2;
        myGrid.gridheight = 1;
        myGrid.weightx = 2;
        myGrid.weighty = 1;
        myGrid.fill = GridBagConstraints.BOTH;
        add(airPanel, myGrid);
        // 添加其他面板或组件的初始化代码
        new Thread(titlePanel).start();
        new Thread(curweatherPanel).start();
        new Thread(futureweatherPanel).start();
        new Thread(airPanel).start();
        new Thread(cityPanel).start();
        cityPanel.setPriority(Thread.MAX_PRIORITY);
    }
}

// 标题面板
class TitlePanel extends JPanel implements Runnable {
    private JLabel titleLabel;
    private JLabel timeLabel;
    private static int cnt = 0;

    public TitlePanel() {
        // 设置布局和背景色等
        setLayout(new BorderLayout());
        setBackground(Color.ORANGE);
        setBorder(BorderFactory.createMatteBorder(0, 0, 2, 0, Color.BLUE));

        // 创建标题标签并添加到标题面板
        titleLabel = new JLabel(getMyTitle());
        titleLabel.setForeground(Color.BLACK);
        titleLabel.setFont(DataPool.getFont(Font.BOLD, 2));

        timeLabel = new JLabel(getCurrentTime());
        timeLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        timeLabel.setFont(DataPool.getFont(Font.BOLD, 3));

        add(titleLabel, BorderLayout.WEST);
        add(timeLabel, BorderLayout.EAST);

        setPreferredSize(new Dimension(getPreferredSize().width, 70));
    }

    public void run() {
        while (true) {
            try {
                updateTitle();
                Thread.sleep(1000);
                cnt++;
                cnt %= 60;
                if (cnt == 0) {
                    DataPool.setAirUpdate(true);
                    DataPool.setCurUpdate(true);
                    DataPool.setFutUpdate(true);
                }
                if (!DataPool.isNetConnect() && cnt % 5 == 0) {
                    if (isNetworkConnected())
                        DataPool.setNetConnect(true);
                }
            } catch (Exception e) {

            }
        }
    }

    public static boolean isNetworkConnected() {
        try {
            String apiKey = "9ae0a4b092f7f2ad31336e4f62cabb82";
            String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + DataPool.getLat() + "&lon="
                    + DataPool.getLon() + "&units=metric&appid="
                    + apiKey;
            URL obj = new URI(url).toURL();

            HttpURLConnection con = (HttpURLConnection) obj.openConnection();
            // Set request method to "GET"
            con.setRequestMethod("GET");

            int responseCode = con.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {
                return true;
            }
            return false;
        } catch (Exception e) {
            return false;
        }
    }

    private String getMyTitle() {
        return "  Weather for " + DataPool.getName() + ", " + DataPool.getCountry();
    }

    private void updateTitle() {
        titleLabel.setText(getMyTitle());
        timeLabel.setText(getCurrentTime());
    }

    private String getCurrentTime() {
        // 将秒转换为毫秒
        long timezoneOffsetMillis = DataPool.getTimezone() * 1000L;

        // 创建一个 SimpleDateFormat 对象，并指定时区偏移
        SimpleDateFormat dateFormat = new SimpleDateFormat("MM-dd HH:mm");
        dateFormat.setTimeZone(TimeZone.getTimeZone("GMT")); // 设置时区为 GMT，即格林尼治标准时间
        dateFormat.setTimeZone(new SimpleTimeZone((int) timezoneOffsetMillis, "Custom")); // 应用时区偏移

        // 返回格式化后的时间字符串
        return dateFormat.format(new Date()) + "  ";
    }
}

class RoundedBorder extends AbstractBorder {
    private static final int ARC_RADIUS = 10;

    public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) {
        super.paintBorder(c, g, x, y, width, height);

        Graphics2D g2d = (Graphics2D) g.create();

        g2d.setStroke(new BasicStroke(2.0f));
        g2d.setColor(Color.BLACK); // 边框颜色
        g2d.drawRoundRect(x, y, width - 1, height - 1, ARC_RADIUS, ARC_RADIUS);

        g2d.dispose();
    }

    public Insets getBorderInsets(Component c) {
        return new Insets(5, 5, 5, 5); // 调整边框与面板内容的距离
    }
}