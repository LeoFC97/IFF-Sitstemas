package Servidor;

import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class Host extends UnicastRemoteObject implements ServidorInterface{
	
	private static final long serialVersionUID = 1L;

	int cont;
	String msg;
	String listaMsg[];
	
	public Host() throws RemoteException {
		this.listaMsg = new String[1000];
		this.cont = 0;
		System.out.println("Servidor ativo!");
	}
	
	public synchronized void receberMensagem(String m) throws RemoteException {
		this.listaMsg[cont] = m;
		System.out.println(m);
		this.cont++;
		int x;
		if (this.cont == 1000) {
			for(x=0;x<50;x++){ this.listaMsg[x] = this.listaMsg[x + 950];
			this.cont = x;
			}
		}
	}
	
	public synchronized int obterContador() throws RemoteException {return this.cont;}
	
	public synchronized String obterMensagem(int n) throws RemoteException {return this.listaMsg[n];}
}
