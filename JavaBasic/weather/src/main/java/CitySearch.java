import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.text.DecimalFormat;

import org.json.*;
import javax.swing.*;
import javax.swing.event.*;

public class CitySearch extends JPanel implements Runnable {
    private JLabel cityLabel;
    private JTextField textField;
    private JButton searchButton;
    private JList<String> resultList;
    private double[] lat = new double[3];
    private double[] lon = new double[3];

    public CitySearch() {
        setLayout(new GridBagLayout());
        setFont(new Font("楷书", Font.BOLD, 16));
        setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        setBackground(Color.PINK);
        setForeground(Color.BLACK);

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        cityLabel = createLabel("City", Font.BOLD, 16);
        textField = new JTextField(7);
        DefaultListModel<String> listModel = new DefaultListModel<>();
        listModel.addElement("");
        listModel.addElement("");
        listModel.addElement("");
        resultList = new JList<>(listModel);
        resultList.setVisible(false);
        resultList.setVisibleRowCount(3);
        resultList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        resultList.addListSelectionListener(new MyListSelectionHandler(resultList, lat, lon));
        searchButton = new JButton();
        ImageIcon icon = new ImageIcon(
                "D:\\Study\\study\\JavaBasic\\weather\\src\\main\\resources\\photos\\search.png");
        ImageIcon resizedIcon = resizeIcon(icon, 20, 20); // 设置缩放后的大小
        searchButton.setIcon(resizedIcon);
        searchButton.addActionListener(new SearchListener(textField, resultList, lat, lon));

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = 1;
        gbc.weighty = 1;
        add(cityLabel, gbc);
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 3;
        gbc.gridheight = 1;
        gbc.weightx = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        add(textField, gbc);
        gbc.gridx = 4;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = 1;
        add(searchButton, gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 5;
        gbc.gridheight = 3;
        gbc.weightx = 1;
        gbc.weighty = 3;
        gbc.fill = GridBagConstraints.BOTH;
        add(resultList, gbc);
    }

    public void run() {
        while (true) {
            try {
                // Thread.sleep(100);
            } catch (Exception e) {

            }
        }
    }

    private static ImageIcon resizeIcon(ImageIcon icon, int width, int height) {
        Image img = icon.getImage();
        Image resizedImg = img.getScaledInstance(width, height, Image.SCALE_SMOOTH);
        return new ImageIcon(resizedImg);
    }

    private JLabel createLabel(String text, int style, int fontSize) {
        JLabel label = new JLabel(text);
        label.setFont(new Font("楷书", style, fontSize));
        return label;
    }

    public void setPriority(int priority) {
        Thread.currentThread().setPriority(priority);
    }
}

class SearchListener implements ActionListener {
    private JTextField text;
    private JList<String> result;
    private double[] lat;
    private double[] lon;

    public SearchListener(JTextField textField, JList<String> resultList, double[] _lat, double[] _lon) {
        text = textField;
        result = resultList;
        lat = _lat;
        lon = _lon;
    }

    public void actionPerformed(ActionEvent e) {
        JButton searchButton = (JButton) e.getSource();
        searchButton.setEnabled(false);
        String content = text.getText();
        text.setText(content);
        if (content.isEmpty()) {
            showUnavailableMessage();
            searchButton.setEnabled(true);
            return;
        }
        try {
            String apiKey = "9ae0a4b092f7f2ad31336e4f62cabb82";
            String url = "https://api.openweathermap.org/geo/1.0/direct?q=" + content + "&limit=5&appid="
                    + apiKey;
            URL obj = new URI(url).toURL();

            HttpURLConnection con = (HttpURLConnection) obj.openConnection();
            // Set request method to "GET"
            con.setRequestMethod("GET");

            int responseCode = con.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {
                BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
                String inputLine;
                StringBuilder response = new StringBuilder();

                while ((inputLine = in.readLine()) != null) {
                    response.append(inputLine);
                }
                in.close();

                JSONArray resArray = new JSONArray(response.toString());
                int n = resArray.length();
                if (resArray.length() == 0) {
                    showUnavailableMessage();
                } else {
                    DefaultListModel<String> model = new DefaultListModel<>();
                    for (int i = 0; i < Math.min(3, n); i++) {
                        JSONObject cityObject = resArray.getJSONObject(i);
                        String ans = cityObject.getString("name");
                        try {
                            ans += "," + cityObject.getString("state");
                        } catch (Exception ee) {

                        }
                        ans += "," + cityObject.getString("country");
                        double _lat = cityObject.getDouble("lat");
                        double _lon = cityObject.getDouble("lon");
                        lat[i] = _lat;
                        lon[i] = _lon;
                        String formattedLat = new DecimalFormat("0.0").format(_lat);
                        String latDirection = (_lat >= 0) ? "N" : "S";
                        String finalLat = formattedLat + latDirection;
                        String formattedLon = new DecimalFormat("0.0").format(_lon);
                        String lonDirection = (_lon >= 0) ? "E" : "W";
                        String finalLon = formattedLon + lonDirection;
                        ans += "," + finalLat + "," + finalLon;
                        model.addElement(ans);
                    }
                    result.setModel(model);
                    result.setVisible(true);
                    result.setVisibleRowCount(3);
                }
            }
        } catch (ConnectException ce) {
            System.out.println(ce);
            displayNetworkErrorDialog("网络连接异常，请检查网络设置");
        } catch (SocketTimeoutException ste) {
            System.out.println(ste);
            displayNetworkErrorDialog("网络连接超时，请稍后重试");
        } catch (java.io.IOException ioe) {
            System.out.println(ioe);
            displayNetworkErrorDialog("网络连接错误，请稍后重试");
        } catch (Exception eeee) {
            System.out.println(eeee);
        } finally {
            searchButton.setEnabled(true);
        }
    }

    private void displayNetworkErrorDialog(String message) {
        DataPool.setNetConnect(false);
        showAlertDialog("网络错误", message);
    }

    private void showAlertDialog(String title, String message) {
        JOptionPane.showMessageDialog(null, message, title, JOptionPane.ERROR_MESSAGE);
    }

    private void showUnavailableMessage() {
        DefaultListModel<String> model = new DefaultListModel<>();
        model.addElement("unavailable");
        result.setModel(model);
        result.setVisible(true);
        result.setVisibleRowCount(1);

        Timer timer = new Timer(1000, new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                DefaultListModel<String> emptyModel = new DefaultListModel<>();
                result.setModel(emptyModel);
                result.setVisible(false);
                ((Timer) evt.getSource()).stop(); // 停止定时器
            }
        });
        timer.setRepeats(false); // 只执行一次
        timer.start();
    }
}

class MyListSelectionHandler implements ListSelectionListener {
    private JList<String> list;
    private double[] lat;
    private double[] lon;

    public MyListSelectionHandler(JList<String> list, double[] lat, double[] lon) {
        this.list = list;
        this.lat = lat;
        this.lon = lon;
    }

    public void valueChanged(ListSelectionEvent e) {
        if (!e.getValueIsAdjusting()) {
            try {
                int val = list.getSelectedIndex();
                String selectedValue = list.getSelectedValue();
                if (selectedValue == null)
                    return;
                if (selectedValue.equals("unavailable"))
                    return;
                String[] fields = selectedValue.split(",");
                String name = fields[0];
                String country = (fields.length == 5) ? fields[2] : fields[1];
                DataPool.setCountry(country);
                DataPool.setName(name);
                DataPool.setLat(lat[val]);
                DataPool.setLon(lon[val]);
                DataPool.setAirUpdate(true);
                DataPool.setCurUpdate(true);
                DataPool.setFutUpdate(true);
                list.removeListSelectionListener(this);
                DefaultListModel<String> model = new DefaultListModel<>();
                list.setModel(model);
                list.setVisible(false);
                list.addListSelectionListener(this);
            } catch (Exception eee) {

            }
        }
    }
}
