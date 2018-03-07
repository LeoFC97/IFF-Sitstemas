package Interface;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class Janela_Erro extends JFrame
{
	JLabel lb_erro; //labels 

	Janela_Erro(String mensagem_erro)
	{
		this.setSize(300,95);
		this.setTitle("Erro");
		this.setResizable(false);
		this.setLocation(300,300);
		this.setLayout(null);
		
		lb_erro=new JLabel("Erro: "+mensagem_erro);
		lb_erro.setSize(250,20);
		lb_erro.setLocation(20,10);
		this.add(lb_erro);
		
		this.setVisible(true);
	}

}
