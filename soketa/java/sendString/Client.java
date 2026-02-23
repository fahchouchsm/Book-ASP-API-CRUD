package sendString;

import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            while (true) {
                Socket s = new Socket("localhost", 3000);
                System.out.println("connected in " + s.getOutputStream());
                Scanner sc = new Scanner(System.in);
                PrintWriter out = new PrintWriter(s.getOutputStream());
                String message = sc.nextLine();
                out.println(message);
                out.flush();
                System.out.println("message sent: " + message);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
