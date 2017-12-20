package Interface;

import java.awt.Font;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import Dados.BD;
import Dados.Evento;
import Dados.Pessoa;


public class Janela_Nova_Atividade extends JPanel
{
	JLabel lb_nome,lb_id,lb_data,lb_data_explicativo, lb_local; //labels 
	JButton bt_ok,bt_limpar; //botoes
	JTextField  en_nome,en_id,en_data,en_local;
	String  nome,id,data,local; //variaveis para receber os dados do entry
	
	Janela_Nova_Atividade()
	{
		this.setSize(300,300);
		this.setLocation(300,300);
		this.setLayout(null);

		/*
		 * Botoes
		 */
		
		//botao ok
		bt_ok= new JButton("Confirma");
		bt_ok.setSize(100,20);
		bt_ok.setLocation(40,145);
		bt_ok.addMouseListener(new Ouvinte());
		this.add(bt_ok);
		//botao ok
		
		//botao limpar
		bt_limpar= new JButton("Limpar");
		bt_limpar.setSize(100,20);
		bt_limpar.setLocation(160,145);
		bt_limpar.addMouseListener(new Ouvinte());
		this.add(bt_limpar);
		//botao limpar
		
		/*
		 * Labels
		 */
		//label do nome
		lb_nome=new JLabel("Nome:");
		lb_nome.setSize(45,20);
		lb_nome.setLocation(20,20);
		this.add(lb_nome);
		//label do nome

		//label com o id
		lb_id=new JLabel("ID:");
		lb_id.setSize(45,20);
		lb_id.setLocation(20,45);
		this.add(lb_id);
		//label com o id
		
		//label com o local
		lb_local=new JLabel("Local:");
		lb_local.setSize(45,20);
		lb_local.setLocation(20,70);
		this.add(lb_local);
		//label com o local
		
		//label com o data2
		lb_data_explicativo=new JLabel("(DDMMAAAA)");
		lb_data_explicativo.setSize(65,20);
		lb_data_explicativo.setLocation(20,110);
		Font f = new Font("SansSerif", Font.BOLD, 8);
		lb_data_explicativo.setFont(f);
		this.add(lb_data_explicativo);
		//label com o data2
		
		//label com o data
		lb_data=new JLabel("Data:");
		lb_data.setSize(45,20);
		lb_data.setLocation(20,95);
		this.add(lb_data);
		//label com o data
		
		/*
		 * Entrys
		 */
		//Entry do nome
		en_nome=new JTextField("");
		en_nome.setSize(200,20);
		en_nome.setLocation(70,20);
		this.add(en_nome);
		//Entry do nome
		
		//Entry do id
		en_id=new JTextField("");
		en_id.setSize(200,20);
		en_id.setLocation(70,45);
		this.add(en_id);
		//Entry do id
		
		//Entry do local
		en_local=new JTextField("");
		en_local.setSize(200,20);
		en_local.setLocation(70,70);
		this.add(en_local);
		//Entry do local
		
		//Entry do data
		en_data=new JTextField("");
		en_data.setSize(200,20);
		en_data.setLocation(70,95);
		this.add(en_data);
		//Entry do data
		
		this.setVisible(true);
	}
	private class Ouvinte extends MouseAdapter
	{
		BD banco2;
		Evento evento;
		public Ouvinte()
		{
			banco2=new BD("");
		}
		@Override
		public void mouseClicked(MouseEvent e) 
		{
			if(e.getSource() == bt_ok )
			{
				nome = en_nome.getText();
				id = en_id.getText();
				data=en_data.getText();
				local=en_local.getText();
				if (local.trim().equals("")||nome.trim().equals("")||id.trim().equals("")||data.trim().equals(""))
				{
					new Janela_Erro("Preencha todos os campos");
				}
				else
				{
					evento = new Evento(nome,id,data,local);
					banco2.salvar(evento);
					en_data.setText("");
					en_id.setText("");
					en_nome.setText("");
					en_local.setText("");
				}
			}
			if(e.getSource() == bt_limpar)
			{
				en_data.setText("");
				en_id.setText("");
				en_nome.setText("");
			}
		}
	}
	
}
