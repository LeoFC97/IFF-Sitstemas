package Interface;

import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTabbedPane;

@SuppressWarnings("serial")
public class Janela_Principal extends JFrame
{
	JButton bt_sobre,bt_cadastro_pessoa,bt_cadastro_atividade,bt_linkar; //botoes
	JTabbedPane abas;

	
	public Janela_Principal()
	{
		this.setSize(600,300);
		this.setLocationRelativeTo(null);
		this.setTitle("Gerenciar eventos");
		this.setResizable(false);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.getContentPane().setBackground(new Color(224,255,255));
		
		abas = new JTabbedPane();
		
		abas.addTab("Cadastrar Pessoas", new Janela_Nova_Pessoa());
		abas.addTab("Cadastrar Eventos", new Janela_Nova_Atividade());
		abas.addTab("Inscrição No Evento ", new Janela_Linkar());
		abas.addTab("Listar Inscritos", new Janela_Listar());
		abas.addTab("Sobre", new Janela_Sobre());
		 
		
		this.add(abas);
		this.setVisible(true);
	}
}

