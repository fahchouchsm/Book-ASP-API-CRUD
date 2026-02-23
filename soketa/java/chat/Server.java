package chat;

import java.net.ServerSocket;

public class Server {
    public static int id = 0;

    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(3000);
            System.out.println("the server is running on port " + ss.getLocalPort());
            while (true) {
                GestionClient gc = new GestionClient(ss.accept());
                gc.run();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}