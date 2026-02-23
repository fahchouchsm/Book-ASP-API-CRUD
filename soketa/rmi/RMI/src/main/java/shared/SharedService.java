package shared;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface SharedService extends Remote {
   public void print(String msg) throws RemoteException;
   public int multi(int x, int y) throws RemoteException;
   public int facto(int n) throws RemoteException;
}
