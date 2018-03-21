package Cliente;

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

import Servidor.ServidorInterface;


public class ClienteThread extends Thread{
	
	int id;
	ServidorInterface server;
	JTextArea batePapo;
	
	ClienteThread(ServidorInterface server, JTextArea batePapo){
		this.server = server;
		this.batePapo = batePapo;
	}
	
	public void run(){
		try{
			String texto = new String();
			int bcont = 0;
			
			while(true){
				while (bcont < server.obterContador()){
				texto = texto + "\n" + server.obterMensagem(bcont);
					bcont++;
				}
				batePapo.setText(texto);
				Thread.sleep(500);
			}
		}
		catch(Exception e) {JOptionPane.showMessageDialog(null, "Erro ao atualizar bate-papo!");}
	}
}