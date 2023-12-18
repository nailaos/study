package game1;

import java.net.*;
import java.io.*;

public class Game1Client {
    String myHost;
    int myPort;

    Game1Client(String host, int port) {
        myHost = host;
        myPort = port;
    }

    int run() {
        int ans = 0;
        try {
            Socket myClient = new Socket(myHost, myPort);
            BufferedReader br = new BufferedReader(new InputStreamReader(myClient.getInputStream()));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(myClient.getOutputStream()));
            bw.write("hello\n");
            bw.flush();
            int x = Integer.parseInt(br.readLine());
            int y = Integer.parseInt(br.readLine());
            br.readLine();
            ans = (x + y) / 2;
            bw.write(String.format("%d\n", ans));
            bw.flush();
            String mess = br.readLine();
            while (!mess.equals("bye")) {
                if (mess.equals("<")) {
                    x = ans + 1;
                    ans = (x + y) / 2;
                } else if (mess.equals(">")) {
                    y = ans - 1;
                    ans = (x + y) / 2;
                } else
                    break;
                bw.write(String.format("%d\n", ans));
                bw.flush();
                mess = br.readLine();
            }
            myClient.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return ans;
    }
}
