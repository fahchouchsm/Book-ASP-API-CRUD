package serverClientThreads;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.SocketException;

public class GestionClient extends Thread {
    private Socket s;

    public GestionClient(Socket s) {
        this.s = s;
    }

    public void run() {
        try {
            System.out.println(Server.compteur + " est connecter");
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            while (true) {
                String req = in.readLine();
                if (req == null) {
                    System.out.println("client has disconnected");
                    break;
                }
                PrintWriter pw = new PrintWriter(s.getOutputStream(), true);
                pw.println("the request length is " + req.length());
            }
        } catch (SocketException se) {
            System.out.println("client has disconnected");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                s.close();
                Server.compteur--;
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }
}
