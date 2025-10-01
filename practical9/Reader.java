public class Reader extends Thread {

private DataAccessPolicyManager2 accessManager;

public Reader (DataAccessPolicyManager2 accessManager) {
this.accessManager = accessManager;
}

public void run() {
while (true) {
System.out.println("Reader waiting");
accessManager.acquireReadLock();
System.out.println("Reader acquired read lock");

try{
sleep ((int)(Math.random()*2000));
} catch (InterruptedException e) {}

System.out.println("Reader finished reading, releasing lock");
accessManager.releaseReadLock();

try{
sleep ((int)(Math.random()*2000));
} catch (InterruptedException e) {}
}
}
}
