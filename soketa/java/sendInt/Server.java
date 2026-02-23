package sendInt;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(3000);
            System.out.println("server is runing ");
            while (true) {
                Socket s = ss.accept();
                System.out.println("client connected");
                InputStream in = s.getInputStream();
                int res = (int) in.read();
                System.out.println("le message est " + res);
                OutputStream out = s.getOutputStream();
                out.write(res * 2);
                System.out.println("the response " + res * 2 + " was send");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}