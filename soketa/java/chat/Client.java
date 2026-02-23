package chat;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Socket s = new Socket();
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintWriter out = new PrintWriter(s.getOutputStream());
            Scanner sc = new Scanner(System.in);
            while (true) {
                String req = sc.nextLine();
                if (req.equals(req)) {
                    break;
                }
                out.println(req);
                System.out.println(in.readLine());
            }
            sc.close();
            s.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
