package serverClientThreads;

import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static int compteur = 0;

    public static void main(String[] args) {
        int port = 3000;
        try (ServerSocket ss = new ServerSocket(port)) {
            System.out.println("server runing on port " + port);
            while (true) {
                Socket s = ss.accept();
                compteur++;
                GestionClient gc = new GestionClient(s);
                gc.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
