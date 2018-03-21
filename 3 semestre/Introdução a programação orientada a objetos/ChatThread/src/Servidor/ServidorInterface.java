package Servidor;

import java.rmi.*;

public interface ServidorInterface extends Remote{
	public void receberMensagem(String m) throws RemoteException;
	public int obterContador() throws RemoteException;
	public String obterMensagem(int n) throws RemoteException;
}