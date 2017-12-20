package Interface;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import Dados.BD;
import Dados.PessoaEvento;

public class Janela_Linkar extends JPanel
{
	JButton bt_ok,bt_limpar; //botoes
	JTextField  en_cpf,en_id; //entrada de dados
	JLabel lb_id,lb_cpf; //labels 
	String  cpf,id; //variaveis para receber os dados do entry


	Janela_Linkar()
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
		//label do CPF
		lb_cpf=new JLabel("CPF:");
		lb_cpf.setSize(45,20);
		lb_cpf.setLocation(20,20);
		this.add(lb_cpf);
		//label do CPF
		
		//label com o id
		lb_id=new JLabel("ID:");
		lb_id.setSize(45,20);
		lb_id.setLocation(20,45);
		this.add(lb_id);
		//label com o id
		
		/*
		 * Entrys
		 */

		//Entry do nome
		en_cpf=new JTextField("");
		en_cpf.setSize(200,20);
		en_cpf.setLocation(70,20);
		this.add(en_cpf);
		//Entry do nome
		
		//Entry do id
		en_id=new JTextField("");
		en_id.setSize(200,20);
		en_id.setLocation(70,45);
		this.add(en_id);
		//Entry do id
		
		this.setVisible(true);

	}
	private class Ouvinte extends MouseAdapter
	{
		PessoaEvento a;
		String cpf, id;
		BD aux;
		int i,k;
		Object[] v;
		public Ouvinte()
		{
			aux = new BD("");
		}
		public void mouseClicked(MouseEvent e) 
		{
			if(e.getSource() == bt_ok )
			{
				cpf = en_cpf.getText();
				id = en_id.getText();
				if (id.trim().equals("")||cpf.trim().equals(""))
				{
					new Janela_Erro("Preencha todos os campos");
				}
				else
				{
					cpf=en_cpf.getText();
					id=en_id.getText();
					v = aux.obterLista("PessoaEvento");
					k=0;
					for(i=0;i<aux.getCont3();i++)
					{
						PessoaEvento varPessoaEvento = (PessoaEvento)v[i];
						if((cpf.equals(varPessoaEvento.getCPF())) && (id.equals(varPessoaEvento.getID())))
						{ 
							k++;
							JOptionPane.showMessageDialog(null, "O CPF já está cadastrado neste evento.");
						}
					}
					if(k == 0)
					{
						a = new PessoaEvento(cpf,id);
						aux.salvar(a);
						en_id.setText("");
						en_cpf.setText("");
					}
				}
			}
			if(e.getSource() == bt_limpar)
			{
				en_cpf.setText("");
				en_id.setText("");
			}
		}
	}
}
