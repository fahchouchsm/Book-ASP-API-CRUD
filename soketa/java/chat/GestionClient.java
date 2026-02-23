package chat;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class GestionClient extends Thread {
    Socket s = new Socket();

    public GestionClient(Socket s) {
        this.s = s;
    }

    public void run() {
        try {
            PrintWriter out = new PrintWriter(s.getOutputStream());
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
