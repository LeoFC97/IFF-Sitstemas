package Servidor;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class ServidorMain {
	public static void main(String[] args){
		try {
			LocateRegistry.createRegistry(1099);
			Host server = new Host();
			Naming.rebind("rmi://localhost/servidor_do_chat" ,server);
		}
		catch(Exception e){e.printStackTrace();}
	}
}
	