package server;

import shared.SharedService;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class SharedServiceImp extends UnicastRemoteObject implements SharedService {
    public SharedServiceImp() throws RemoteException {
        super();
    }

    @Override
    public void print(String msg) throws RemoteException {
        System.out.println(msg);
    }

    @Override
    public int multi(int x, int y) throws RemoteException {
        return x * y;
    }

    @Override
    public int facto(int n) throws RemoteException {
        int res = 1;
        for(int i = 1; i <= n; i++) {
            res = res * i;
        }
        return res;
    }
}
