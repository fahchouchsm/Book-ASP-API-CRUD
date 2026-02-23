package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

class Server {
    public static void main(String[] args){
        try{
            SharedServiceImp imp = new SharedServiceImp();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("SharedService", imp);
            System.out.println("server is running");

        }catch (Exception e) {
            e.printStackTrace();
        }
    }
}