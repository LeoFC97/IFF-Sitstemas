package Cliente;

import java.awt.Color;
import javax.swing.*;

import Servidor.ServidorInterface;

import java.awt.event.*;
import java.rmi.RemoteException;
import java.rmi.Naming;

public class JanelaGrafica extends JFrame{                      
	private static final long serialVersionUID = 1L;
	
	JLabel lbId, lbServidor, lbMensagem;
	JTextField tfId, tfServidor, tfMensagem;
	JButton btConectar, btEnviar, btGit;
	JTextArea batePapo;
	JScrollPane scroll;
	
	ServidorInterface server;
	int bcont = 0;
	String Buffer[], texto; 
	
	JanelaGrafica(){
		this.setSize(680, 520);
		this.setResizable(false);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setTitle("Chat Service");
		this.getContentPane().setLayout(null);	
		this.getContentPane().setBackground(Color.white);
		this.setLocationRelativeTo(null);
		
		OuvinteConectar oC = new OuvinteConectar();
		OuvinteEnviar oE = new OuvinteEnviar();
		OuvinteGit oG = new OuvinteGit();
		
		//Botao do git
		btGit = new JButton();
		btGit.setText("GitHub");
		btGit.setSize(100, 20);
		btGit.setLocation(520, 30);
		btGit.addMouseListener(oG);
		this.add(btGit);

		
		// Configura Id
		lbId = new JLabel();
		lbId.setText("Nome:");
		lbId.setSize(100, 20);
		lbId.setLocation(10, 30);
		this.add(lbId);

		tfId = new JTextField();
		tfId.setSize(120, 20);
		tfId.setLocation(50, 30);
		this.add(tfId);
		
		// Configura Servidor
		lbServidor = new JLabel();
		lbServidor.setText("Servidor: ");
		lbServidor.setSize(100, 20);
		lbServidor.setLocation(190, 30);
		this.add(lbServidor);

		tfServidor = new JTextField();
		tfServidor.setSize(120, 20);
		tfServidor.setText("localhost/servidor_do_chat");
		tfServidor.setEditable(false);
		tfServidor.setLocation(250, 30);
		this.add(tfServidor);
		
		// Botao Conectar
		btConectar = new JButton();
		btConectar.setText("CONECTAR");
		btConectar.setSize(100, 20);
		btConectar.setLocation(400, 30);
		btConectar.addMouseListener(oC);
		this.add(btConectar);		

		// Area do Bate-papo
		batePapo = new JTextArea();
		scroll = new JScrollPane(batePapo);
		scroll.setSize(600, 375);
		scroll.setLocation(30, 60);
		scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		batePapo.setEditable(false);
		batePapo.setText("Esperando conexão...");
		this.add(scroll);
		
		// Configura Mensagem
		lbMensagem = new JLabel();
		lbMensagem.setText("Mensagem:");
		lbMensagem.setSize(150, 20);
		lbMensagem.setLocation(30, 450);
		this.add(lbMensagem);

		tfMensagem = new JTextField();
		tfMensagem.setSize(310, 20);
		tfMensagem.setLocation(110, 450);
		this.add(tfMensagem);
		
		btEnviar = new JButton();
		btEnviar.setText("ENVIAR");
		btEnviar.setSize(100, 20);
		btEnviar.setLocation(430, 450);
		btEnviar.addMouseListener(oE);
		this.add(btEnviar);
		
		this.setVisible(true);
	}
	
	public class OuvinteEnviar implements MouseListener{
		public void mouseClicked(MouseEvent arg0){
			try {server.receberMensagem(tfId.getText()+": "+tfMensagem.getText());}
			catch (RemoteException e) {JOptionPane.showMessageDialog(null, "Erro ao enviar mensagem!");}
		}
		public void mousePressed(MouseEvent e){}
		public void mouseReleased(MouseEvent e){}
		public void mouseEntered(MouseEvent e){}
		public void mouseExited(MouseEvent e){}
	}
	
	public class OuvinteGit implements MouseListener{
		public void mouseClicked(MouseEvent arg0)
		{
			new Misc.btGit().setVisible(true);
		}

		public void mousePressed(MouseEvent e){}
		public void mouseReleased(MouseEvent e){}
		public void mouseEntered(MouseEvent e){}
		public void mouseExited(MouseEvent e){}
	}
	
	
	public class OuvinteConectar implements MouseListener{
		public void mouseClicked(MouseEvent arg0){
			try {
				server = (ServidorInterface) Naming.lookup("rmi://localhost/servidor_do_chat");
				JOptionPane.showMessageDialog(null, "Servidor conectado!");
			}
			catch (Exception e) {JOptionPane.showMessageDialog(null, "Erro ao conectar no Servidor!");}
			ClienteThread atualizarChat = new ClienteThread(server, batePapo);
			atualizarChat.start();
		}
		public void mousePressed(MouseEvent e){}
		public void mouseReleased(MouseEvent e){}
		public void mouseEntered(MouseEvent e){}
		public void mouseExited(MouseEvent e){}
	}
	
	public static void main(String[] args) {new JanelaGrafica();}
}