package Interface;

import java.awt.event.MouseAdapter;

import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import Dados.BD;
import Dados.Pessoa;


@SuppressWarnings("serial")
public class Janela_Nova_Pessoa extends JPanel
{
	JLabel lb_nome,lb_cpf,lb_email,lb_titulo; //labels 
	JButton bt_ok,bt_limpar; //botoes
	JTextField  en_nome,en_cpf,en_email;
	String  nome,cpf,email; //variaveis para receber os dados do entry
	public Janela_Nova_Pessoa()
	{
		this.setSize(600,200);
		this.setLayout(null);
		
		lb_titulo = new JLabel("Cadastre uma nova Pessoa");
		lb_titulo.setSize(200,20);
		lb_titulo.setLocation(220,0);
		this.add(lb_titulo);
		
		bt_limpar = new JButton("Limpar");
		bt_limpar.setSize(100,30);
		bt_limpar.setLocation(350,120);
		bt_limpar.addMouseListener(new Ouvinte());
		this.add(bt_limpar);
		
		bt_ok = new JButton("Confirmar");
		bt_ok.setSize(100,30);
		bt_ok.setLocation(350,45);
		bt_ok.addMouseListener(new Ouvinte());
		this.add(bt_ok);
		
		lb_cpf = new JLabel("Cpf:");
		lb_cpf.setSize(130,50);
		lb_cpf.setLocation(35,30);
		this.add(lb_cpf);
		
		lb_nome = new JLabel("Nome:");
		lb_nome.setSize(130,50);
		lb_nome.setLocation(35,70);	
		this.add(lb_nome);
		
		lb_email = new JLabel("Email");
		lb_email.setSize(130,50);
		lb_email.setLocation(35,110);
		this.add(lb_email);
		
		en_cpf = new JTextField();
		en_cpf.setSize(120,20);
		en_cpf.setLocation(80,45);
		this.add(en_cpf);
		
		en_nome = new JTextField();
		en_nome.setSize(120,20);
		en_nome.setLocation(80,85);
		this.add(en_nome);
		
		
		en_email = new JTextField();
		en_email.setSize(120,20);
		en_email.setLocation(80,125);
		this.add(en_email);
		
		this.setVisible(true);
		
	}
	private class Ouvinte extends MouseAdapter
	{
		BD banco;
		Pessoa pessoa;
		public Ouvinte()
		{
			banco=new BD("");
		}
		@Override
		public void mouseClicked(MouseEvent e) 
		{
			if(e.getSource() == bt_ok )
			{
				nome = en_nome.getText();
				cpf = en_cpf.getText();
				email=en_email.getText();
				if (nome.trim().equals("")||cpf.trim().equals("")||email.trim().equals(""))
				{
					new Janela_Erro("Preencha todos os campos");
				}
				else
				{
					pessoa = new Pessoa(nome,cpf,email);
					banco.salvar(pessoa);
					en_email.setText("");
					en_cpf.setText("");
					en_nome.setText("");
				}
			}
			if(e.getSource() == bt_limpar)
			{
				en_email.setText("");
				en_cpf.setText("");
				en_nome.setText("");
			}
		}
	}
	
}
