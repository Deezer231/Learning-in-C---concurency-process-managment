
import java.net.*;
import java.io.*;

public class DateServer {
    private static int connectionCount = 0; //keep tracks of connections

    public static void main(String[] args) throws IOException {
        try {
            ServerSocket sock = new ServerSocket(6013);
            System.out.println("Server is running");

            while (true) {
                Socket client = sock.accept();
                connectionCount++;
                System.out.println("Accepted connection number" + connectionCount);

                // new worker thread
                WorkerThread worker = new WorkerThread(client, connectionCount);
                Thread t = new Thread(worker);
                t.start();
            }
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
