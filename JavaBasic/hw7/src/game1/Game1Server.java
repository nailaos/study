package game1;


import javax.management.AttributeList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;

public class Game1Server extends Thread {

    public int port, number;
    public String result;
    public int cnt;
    public int lower_bound, upper_bound;
    public int limit;

    public Game1Server(int tport, int tnumber, int tl, int tu, int tlimit) {
        super();
        port = tport;
        number = tnumber;
        result = "no result yet";
        cnt = 0;
        lower_bound = tl;
        upper_bound = tu;
        limit = tlimit;
    }
    public void run() {

        try {
            ServerSocket ss = new ServerSocket(port);

            System.out.println("server running");
            Socket s = ss.accept();
            System.out.println("client "+s.getInetAddress().getLocalHost()+"connected");

            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));

            String mess = br.readLine();

            System.out.println(mess);
            int t;
            while(!mess.equals("bye")) {
                System.out.println("server got:" + mess);
                if(mess.equals("hello")){
                    bw.write(String.valueOf(lower_bound)+"\n"+String.valueOf(upper_bound)+"\n"+String.valueOf(limit)+"\n");
                    bw.flush();
                    mess = br.readLine();
                    continue;
                }
                t = Integer.parseInt(mess);
                cnt++;
                if(cnt > limit) {
                    bw.write("exceed limit\nbye\n");;
                    bw.flush();
                    return;
                }
                if(t < number) {
                    bw.write("<\n");
                }
                else if (t > number) {
                    bw.write(">\n");
                }
                else {
                    bw.write("Correct!\n");
                    bw.write("bye\n");
                    bw.flush();
                    System.out.println("game over");
                    break;
                }
                bw.flush();
                mess = br.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
            result = "run time error" + String.valueOf(e);
            return ;
        }

        result = "Correct!";
    }

    public int return_count() {
        return cnt;
    }
}