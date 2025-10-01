
class WorkerThread implements Runnable {
    private Socket client;
    private int clientNumber;

    public WorkerThread(Socket client, int clientNumber) {
        this.client = client;
        this.clientNumber = clientNumber;
    }

    public void run() {
        try {
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

            // Send the date to the client
            pout.println(new java.util.Date().toString());

            // Inform client that the server finished processing
            pout.println("Finished processing client " + clientNumber);

            client.close();
        } catch (IOException ioe) {
            System.err.println("Error handling client " + clientNumber + ": " + ioe);
        }
    }
}
