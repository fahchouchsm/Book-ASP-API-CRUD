package sendInt;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            while (true) {
                Socket s = new Socket("localhost", 3000);
                System.out.println("connected in ");
                Scanner sc = new Scanner(System.in);
                OutputStream out = s.getOutputStream();
                int number = sc.nextInt();
                out.write(number);
                System.out.println("message sent " + number);

                InputStream in = s.getInputStream();
                int res = in.read();

                System.out.println("received from the server " + res);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
