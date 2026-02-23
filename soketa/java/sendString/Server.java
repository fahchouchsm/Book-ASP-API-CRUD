package sendString;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(3000);
            System.out.println("server is runing ");
            while (true) {
                Socket s = ss.accept();
                System.out.println(s.getInetAddress() + " :");
                BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
                String res = in.readLine();
                System.out.println("" + res);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}