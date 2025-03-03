// Socket Programming for IPC in a client-server model
// This is the server side of the DateServer-DateClient pair.
import java.net.*;
import java.io.*;

public class DateServer {
    public static void main(String[] args) {
        try {
            ServerSocket sock = new ServerSocket(6013);
            System.out.println("Server socket created " + sock.getInetAddress().getHostAddress() + " on port " + sock.getLocalPort());

            /* now listen for connections */
            while (true) {
                Socket client = sock.accept(); // blocks until a client connects
                System.out.println("Connection made with client: " + client.getInetAddress().getHostAddress() + " on port " + client.getPort());

                PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
                /* write the Date to the socket */
                pout.println(new java.util.Date().toString());
                /* close the socket and resume */
                /* listening for connections */
                client.close();
            }
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
