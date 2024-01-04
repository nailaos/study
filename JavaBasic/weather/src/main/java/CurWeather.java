import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import javax.swing.*;
import java.net.*;

import org.json.*;

public class CurWeather extends JPanel implements Runnable {
    private JLabel temperatureLabel;
    private JLabel conditionLabel;
    private JLabel windLabel;
    private JLabel humidityLabel;
    private JLabel cloudsLabel;
    private JLabel weatherLabel;

    public CurWeather() {
        setLayout(new GridBagLayout());
        setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        setBackground(Color.PINK);

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        // 创建显示天气信息的各个标签
        temperatureLabel = createLabel("15\u2103", Font.BOLD, 1);
        conditionLabel = createLabel("Clear Sky", Font.BOLD, 2);
        windLabel = createLabel("Wind: 0.2 m/s", Font.PLAIN, 4);
        humidityLabel = createLabel("Humidity: 56%", Font.PLAIN, 4);
        cloudsLabel = createLabel("Clouds: 100%", Font.PLAIN, 4);

        // 创建天气状况图标面板
        weatherLabel = new JLabel();
        try {
            Icon myIcon = new ImageIcon(
                    "D:\\Study\\study\\JavaBasic\\weather\\src\\main\\resources\\photos\\10d@2x.png");
            weatherLabel.setIcon(myIcon);
        } catch (Exception e) {

        }

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.gridheight = 3;
        add(weatherLabel, gbc);
        gbc.gridx = 2;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        add(temperatureLabel, gbc);
        gbc.gridx = 2;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        add(conditionLabel, gbc);
        gbc.gridx = 2;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        add(cloudsLabel, gbc);
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = 0.5;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        add(windLabel, gbc);
        gbc.gridx = 2;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = 0.5;
        add(humidityLabel, gbc);
    }

    public void run() {
        while (true) {
            try {
                if (DataPool.isCurUpdate() && DataPool.isNetConnect()) {
                    update();
                    DataPool.setCurUpdate(false);
                } else {
                    // Thread.sleep(1000);
                }
            } catch (ConnectException ce) {
                displayNetworkErrorDialog("网络连接异常，请检查网络设置");
            } catch (SocketTimeoutException ste) {
                displayNetworkErrorDialog("网络连接超时，请稍后重试");
            } catch (java.io.IOException ioe) {
                displayNetworkErrorDialog("网络连接错误，请稍后重试");
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }

    private void displayNetworkErrorDialog(String message) {
        DataPool.setNetConnect(false);
        showAlertDialog("网络错误", message);
    }

    private void showAlertDialog(String title, String message) {
        JOptionPane.showMessageDialog(null, message, title, JOptionPane.ERROR_MESSAGE);
    }

    private JLabel createLabel(String text, int style, int fontSize) {
        JLabel label = new JLabel(text);
        label.setFont(DataPool.getFont(style, fontSize));
        return label;
    }

    public void update() throws Exception {
        String apiKey = "9ae0a4b092f7f2ad31336e4f62cabb82";
        String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + DataPool.getLat() + "&lon="
                + DataPool.getLon() + "&units=metric&appid="
                + apiKey;
        URL obj = new URI(url).toURL();

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

        // 从 JSON 对象中获取你需要的字段
        JSONObject mainObject = jsonObject.getJSONObject("main");
        String temp = mainObject.getInt("temp") + "\u2103";
        String humd = "Humidity: " + mainObject.getInt("humidity") + "%";
        temperatureLabel.setText(temp);
        humidityLabel.setText(humd);

        int timezone = jsonObject.getInt("timezone");
        DataPool.setTimezone(timezone);

        JSONArray weatherArray = jsonObject.getJSONArray("weather");
        JSONObject weatherObject = weatherArray.getJSONObject(0);
        String condition = weatherObject.getString("description");
        String weatherIcon = weatherObject.getString("icon");

        JSONObject windObject = jsonObject.getJSONObject("wind");
        String wind = "Wind: " + windObject.getFloat("speed") + " m/s";

        JSONObject cloudObject = jsonObject.getJSONObject("clouds");
        String cloud = "Clouds: " + cloudObject.getInt("all") + "%";
        conditionLabel.setText(condition);
        windLabel.setText(wind);
        cloudsLabel.setText(cloud);

        String onlineImageUrl = "https://openweathermap.org/img/wn/" + weatherIcon + "@2x.png";
        URL onlineurl = new URI(onlineImageUrl).toURL();
        Icon newIcon = new ImageIcon(onlineurl);
        weatherLabel.setIcon(newIcon);
    }
}
