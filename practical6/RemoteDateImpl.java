import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
import java.util.Date;
public class RemoteDateImpl extends UnicastRemoteObject implements RemoteDate
{
public RemoteDateImpl()throws RemoteException {}
// This is the implementation of the remote method getDate()
public Date getDate() throws RemoteException {
return new Date();
}
public long add(long a, long b) throws RemoteException {
return (a + b);
}

public static void main(String[] args) {
try {
RemoteDate dateServer = new RemoteDateImpl();
Naming.rebind("DateServer", dateServer);
}
catch (Exception e) {
System.err.println(e);
}
}
}
