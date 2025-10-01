public class Writer extends Thread {
DataAccessPolicyManager2 lockManager;
public Writer (DataAccessPolicyManager2 lockManager) {
}

public void run() {
while (true) {

try{
sleep ((int)(Math.random()*500));
} catch (InterruptedException e) {}

System.out.println("Writer finished Writing, releasing lock");
lockManager.releaseReadLock();

try{
sleep ((int)(Math.random()*2000)); //
} catch (InterruptedException e) {}
}
}
}
