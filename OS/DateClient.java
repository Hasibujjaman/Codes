// Socket Programming for IPC in a client-server model
// This is the client side of the DateServer-DateClient pair.
import java.net.*;
import java.io.*;

public class DateClient {
    public static void main(String[] args) {
        try {
            /* make connection to server socket */
            Socket sock = new Socket("127.0.0.1", 6013); // 

            System.out.println("Connection made with server: " + sock.getInetAddress().getHostAddress() + " on port " + sock.getPort());

            InputStream in = sock.getInputStream();
            BufferedReader bin = new BufferedReader(new InputStreamReader(in));
            /* read the date from the socket */
            String line;
            while ((line = bin.readLine()) != null)
                System.out.println(line);
            /* close the socket connection */
            sock.close();
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}