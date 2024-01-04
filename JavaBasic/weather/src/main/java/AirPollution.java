import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URL;

import javax.swing.*;

import org.json.JSONArray;
import org.json.JSONObject;

public class AirPollution extends JPanel implements Runnable {
    private JLabel AQI_indexLabel;
    private JLabel pollutionLevelLabel;
    private JLabel pollutionLabel;
    private JLabel mainPollutantsLabels;
    private String mainPollutants;
    private int[] iAqi = new int[6];
    private int AQI;
    static String[] components = { "so2", "no2", "pm10", "co", "o3", "pm2_5" };
    static String[] pollutants = { "SO<sub>2</sub>", "NO<sub>2</sub>", "PM<sub>10</sub>", "CO", "O<sub>3</sub>",
            "PM<sub>2.5</sub>" };
    static String[] pollutionCategory = { "Excellent", "Good", "Lightly Polluted", "Moderatory Polluted",
            "Heavily Polluted", "Severely Polluted" };
    static float[][] array = {
            { 0, 0, 0, 0, 0, 0, 0 },
            { 50, 150, 100, 50, 5000, 160, 35 },
            { 100, 500, 200, 150, 10000, 200, 75 },
            { 150, 650, 700, 250, 35000, 300, 115 },
            { 200, 800, 1200, 350, 60000, 400, 150 },
            { 300, 1600, 2340, 420, 90000, 800, 250 },
            { 400, 2100, 3090, 500, 120000, 1000, 350 },
            { 500, 2620, 3840, 600, 150000, 1200, 500 }
    };

    public AirPollution() {
        setLayout(new GridBagLayout());
        setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        setBackground(Color.PINK);

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        AQI_indexLabel = createLabel("AQI: 175", Font.BOLD, 3);
        pollutionLevelLabel = createLabel("Moderatory Polluted", Font.BOLD, 3);
        pollutionLabel = createLabel("Main Pollutants:", Font.BOLD, 3);

        mainPollutants = "PM2.5";
        mainPollutantsLabels = createLabel(mainPollutants, Font.BOLD, 3);

        gbc.gridx = 0;
        gbc.gridy = 0;
        add(AQI_indexLabel, gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        add(pollutionLevelLabel, gbc);
        gbc.gridx = 0;
        gbc.gridy = 2;
        add(pollutionLabel, gbc);
        gbc.gridx = 0;
        gbc.gridy = 3;
        add(mainPollutantsLabels, gbc);
    }

    public void run() {
        while (true) {
            try {
                if (DataPool.isAirUpdate() && DataPool.isNetConnect()) {
                    update();
                    DataPool.setAirUpdate(false);
                } else {
                    // Thread.sleep(1000);
                }
            } catch (Exception e) {

            }
        }
    }

    private JLabel createLabel(String text, int style, int fontSize) {
        JLabel label = new JLabel(text);
        label.setFont(DataPool.getFont(style, fontSize));
        return label;
    }

    public void update() throws Exception {
        String apiKey = "9ae0a4b092f7f2ad31336e4f62cabb82";
        String url = "https://api.openweathermap.org/data/2.5/air_pollution?lat=" + DataPool.getLat() + "&lon="
                + DataPool.getLon() + "&units=metric&appid="
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
            JSONObject jsonObject = new JSONObject(response.toString());
            JSONArray componentArray = jsonObject.getJSONArray("list");
            JSONObject pollutionObiect = componentArray.getJSONObject(0);
            JSONObject componentObject = pollutionObiect.getJSONObject("components");
            int ans = 0;
            AQI = 0;
            for (int i = 0; i < 6; i++) {
                float val = componentObject.getFloat(components[i]);
                int row = searchColumn(i + 1, val);
                iAqi[i] = calculateIAQI(row, i + 1, val);
                if (iAqi[i] > AQI) {
                    AQI = iAqi[i];
                    ans = i;
                }
            }
            mainPollutants = "<html>" + pollutants[ans];
            for (int i = 0; i < 6; i++) {
                if (ans == i)
                    continue;
                if (AQI == iAqi[i])
                    mainPollutants += "&nbsp;" + pollutants[i];
            }
            mainPollutants += "</html>";
            int level = getLevel(AQI);
            AQI_indexLabel.setText("AQI: " + AQI);
            pollutionLevelLabel.setText(pollutionCategory[level]);
            mainPollutantsLabels.setText(mainPollutants);
        } else {
            throw new java.net.ConnectException("HTTP Error Code: " + responseCode);
        }
    }

    private int searchColumn(int column, float value) {
        int res = 0;
        while (res < 8 && value > array[res][column]) {
            res++;
        }
        return res;
    }

    private int calculateIAQI(int row, int column, float val) {
        if (row == 0)
            return 0;
        if (row == 8)
            return (int) array[7][column];
        float k = (array[row][0] - array[row - 1][0]) / (array[row][column] - array[row - 1][column]);
        int res = (int) (k * (val - array[row - 1][column]) + array[row - 1][0]);
        return res;
    }

    private int getLevel(int x) {
        if (x < 51)
            return 0;
        if (x < 101)
            return 1;
        if (x < 151)
            return 2;
        if (x < 201)
            return 3;
        if (x < 301)
            return 4;
        return 5;
    }
}
