package serverClientThreads;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("127.0.0.1", 3000);
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);
            Scanner sc = new Scanner(System.in);
            while (true) {
                String msg = sc.nextLine();
                if (msg.equals("exit")) {
                    break;
                }
                out.println(msg);
                String res = in.readLine();
                System.out.println(res);
            }
            System.out.println("disconnected");
            sc.close();
            s.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
