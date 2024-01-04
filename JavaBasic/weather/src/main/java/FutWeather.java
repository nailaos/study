import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;
import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import javax.swing.*;
import org.json.*;

public class FutWeather extends JPanel implements Runnable {
    private String[] weeks = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    private String[] weatherInfo = new String[5];
    private int myWeek;
    private JLabel[] weatherIcons;
    private CreatePolygon weatherGraph;

    public FutWeather() {
        setLayout(new GridBagLayout());
        setBackground(Color.GREEN);

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.BOTH;
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.weightx = 0.25;

        weatherIcons = new JLabel[5];

        // 添加星期、日期、天气图标、温度曲线等组件
        for (int i = 0; i < 5; i++) {
            gbc.gridheight = 1;
            gbc.gridx = i;
            gbc.gridy = 0;
            gbc.weighty = 0;
            add(createHeaderLabel(i), gbc);

            gbc.gridy = 1;
            gbc.weighty = 0;
            add(createDateLabel(i), gbc);

            gbc.gridy = 2;
            gbc.weighty = 0.1;
            weatherIcons[i] = createWeatherIcon();
            add(weatherIcons[i], gbc);
        }

        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 5;
        gbc.gridheight = 3; // 调整为 2 行高度
        gbc.weightx = 1;
        gbc.weighty = 0.9;
        gbc.fill = GridBagConstraints.BOTH;
        weatherGraph = new CreatePolygon();
        add(weatherGraph, gbc);
    }

    public void run() {
        while (true) {
            try {
                if (DataPool.isFutUpdate() && DataPool.isNetConnect()) {
                    update();
                    DataPool.setFutUpdate(false);
                } else {
                    // Thread.sleep(1000);
                }
            } catch (Exception e) {

            }
        }
    }

    private JLabel createHeaderLabel(int column) {
        JLabel label = new JLabel(getDayHeader(column));
        label.setFont(DataPool.getFont(Font.BOLD, 3));
        label.setHorizontalAlignment(SwingConstants.CENTER);
        return label;
    }

    private JLabel createDateLabel(int column) {
        JLabel label = new JLabel(getDate(column));
        label.setFont(DataPool.getFont(Font.BOLD, 3));
        label.setHorizontalAlignment(SwingConstants.CENTER);
        return label;
    }

    private JLabel createWeatherIcon() {
        JLabel label = new JLabel();
        try {
            Icon myIcon = new ImageIcon(
                    "D:\\Study\\study\\JavaBasic\\weather\\src\\main\\resources\\photos\\10d@2x.png");
            label.setIcon(myIcon);
        } catch (Exception e) {
            System.out.println("error with finding icon");
        }
        label.setHorizontalAlignment(SwingConstants.CENTER);
        return label;
    }

    private String getDayHeader(int column) {
        if (column == 0) {
            LocalDate date = LocalDate.now();
            DayOfWeek dayOfWeek = date.getDayOfWeek();
            myWeek = dayOfWeek.getValue();
            return "Tonight";
        } else {
            return weeks[(myWeek + column) % 7];
        }
    }

    private String getDate(int column) {
        LocalDate currentDate = LocalDate.now().plusDays(column);
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM/dd");
        String formattedDate = currentDate.format(formatter);
        return formattedDate;
    }

    public void update() throws Exception {
        String apiKey = "9ae0a4b092f7f2ad31336e4f62cabb82";
        String url = "https://api.openweathermap.org/data/2.5/forecast?lat=" + DataPool.getLat() + "&lon="
                + DataPool.getLon() + "&units=metric&appid="
                + apiKey;
        java.net.URL obj = new URI(url).toURL();
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
        // Set request method to "GET"
        con.setRequestMethod("GET");

        int responseCode = con.getResponseCode();
        if (responseCode != HttpURLConnection.HTTP_OK) {
            throw new java.net.ConnectException("HTTP Error Code: " + responseCode);
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
        String inputLine;
        StringBuilder response = new StringBuilder();

        while ((inputLine = in.readLine()) != null) {
            response.append(inputLine);
        }
        in.close();

        // 使用 org.json 解析 JSON
        JSONObject jsonObject = new JSONObject(response.toString());

        JSONArray weatherArray = jsonObject.getJSONArray("list");
        boolean[] visited = new boolean[5];
        int len = weatherArray.length();
        for (int i = 0; i < len; i++) {
            JSONObject weatherObject = weatherArray.getJSONObject(i);
            String dateTimeString = weatherObject.getString("dt_txt");
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            LocalDateTime dateTime = LocalDateTime.parse(dateTimeString, formatter);
            String datePartString = dateTime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            String timePartString = dateTime.format(DateTimeFormatter.ofPattern("HH:mm:ss"));
            LocalDate datePart = LocalDate.parse(datePartString, DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            LocalDate today = LocalDate.now();
            ZoneOffset zoneOffset = ZoneOffset.ofTotalSeconds(DataPool.getTimezone());
            ZonedDateTime zonedDateTime = today.atStartOfDay().atZone(zoneOffset);
            LocalDate convertedDate = zonedDateTime.toLocalDate();
            int dayDifference = (int) java.time.temporal.ChronoUnit.DAYS.between(convertedDate, datePart);
            if (dayDifference >= 0 && dayDifference < 5) {
                if (timePartString.substring(0, 2).equals("24"))
                    continue;
                JSONObject mainObiect = weatherObject.getJSONObject("main");
                float tmp_max = mainObiect.getFloat("temp_max");
                float tmp_min = mainObiect.getFloat("temp_min");
                if (tmp_max > weatherGraph.maxTemperatures[dayDifference] || !visited[dayDifference]) {
                    weatherGraph.maxTemperatures[dayDifference] = tmp_max;
                }
                if (tmp_min < weatherGraph.minTemperatures[dayDifference] || !visited[dayDifference]) {
                    weatherGraph.minTemperatures[dayDifference] = tmp_min;
                    visited[dayDifference] = true;
                }
                if (timePartString.substring(0, 2).equals("12")) {
                    JSONArray theDayWeather = weatherObject.getJSONArray("weather");
                    JSONObject theWeather = theDayWeather.getJSONObject(0);
                    weatherInfo[dayDifference] = theWeather.getString("icon");
                }
                if (dayDifference == 0 && timePartString.substring(0, 2).equals("18")) {
                    JSONArray theDayWeather = weatherObject.getJSONArray("weather");
                    JSONObject theWeather = theDayWeather.getJSONObject(0);
                    weatherInfo[dayDifference] = theWeather.getString("icon");
                    weatherGraph.tonightValid = true;
                }
            }
        }
        for (int i = 1; i < 5; i++) {
            String onlineImageUrl = "https://openweathermap.org/img/wn/" + weatherInfo[i] + "@2x.png";
            java.net.URL onlineurl = new URI(onlineImageUrl).toURL();
            Icon newIcon = new ImageIcon(onlineurl);
            weatherIcons[i].setIcon(newIcon);
        }
        weatherGraph.repaint();
    }
}

class CreatePolygon extends JPanel {
    protected float[] maxTemperatures = { 25, 17, 17, 13, 12 };
    protected float[] minTemperatures = { 12, 12, 9, 9, 8 };
    protected boolean tonightValid = false;
    private float maxTmp;
    private float minTmp;
    private JLabel[] maxTmpLabels = new JLabel[5];
    private JLabel[] minTmpLabels = new JLabel[5];

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (JLabel label : maxTmpLabels)
            if (label != null)
                remove(label);

        for (JLabel label : minTmpLabels)
            if (label != null)
                remove(label);

        setLayout(null);
        setBackground(Color.GREEN);
        int width = getWidth();
        int height = getHeight();
        int xInterval = width / 5;
        int xStart = xInterval / 2;
        int[] xPoints = new int[10];
        int[] yPoints = new int[10];
        maxTmp = maxTemperatures[1];
        minTmp = minTemperatures[1];
        for (int i = 0; i < 5; i++) {
            if (maxTemperatures[i] > maxTmp)
                maxTmp = maxTemperatures[i];
            if (minTemperatures[i] < minTmp)
                minTmp = minTemperatures[i];
        }
        float k = (float) ((160.0 - height) / (maxTmp - minTmp));
        float b = (float) (height - 80.0);
        for (int i = 0; i < 5; i++) {
            xPoints[i] = xPoints[9 - i] = xStart + xInterval * i;
            yPoints[i] = (int) (k * (maxTemperatures[i] - minTmp) + b);
            yPoints[9 - i] = (int) (k * (minTemperatures[i] - minTmp) + b);
        }

        g.setColor(Color.ORANGE);
        g.fillPolygon(xPoints, yPoints, 10);

        for (int i = 0; i < 5; i++) {
            maxTmpLabels[i] = new JLabel(maxTemperatures[i] + "\u2103");
            minTmpLabels[i] = new JLabel(minTemperatures[i] + "\u2103");

            maxTmpLabels[i].setFont(DataPool.getFont(Font.BOLD, 4));
            minTmpLabels[i].setFont(DataPool.getFont(Font.BOLD, 4));

            int w = 60;
            int h = 20;

            int x = xStart + xInterval * i - w / 2;
            int y = yPoints[i] - h - 20;
            maxTmpLabels[i].setBounds(x, y, w, h);
            y = yPoints[9 - i] + 20;
            minTmpLabels[i].setBounds(x, y, w, h);

            maxTmpLabels[i].setHorizontalAlignment(SwingConstants.CENTER);
            minTmpLabels[i].setHorizontalAlignment(SwingConstants.CENTER);

            add(maxTmpLabels[i]);
            add(minTmpLabels[i]);
        }
    }
}