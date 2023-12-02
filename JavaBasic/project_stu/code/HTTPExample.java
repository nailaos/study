import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URI;

public class HTTPExample {

    public static void main(String[] args) throws Exception {
        String url = "https://api.openweathermap.org/data/2.5/weather?lat=39.906217&lon=116.3912757&units=metric&appid={API KEY}";   
        URL obj = new URI(url).toURL();
        
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
        // Set request method to "GET"
        con.setRequestMethod("GET");

        int responseCode = con.getResponseCode();
        if (responseCode != 200); // Process network exception.
        // Read the response
        BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
        
    }
}

