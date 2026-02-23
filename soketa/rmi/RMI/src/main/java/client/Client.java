package client;

import shared.SharedService;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args){
        try{
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            SharedService sharedService = (SharedService) registry.lookup("SharedService");

            System.out.println(sharedService.facto(10));
            System.out.println(sharedService.multi(5, 6));

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}