package Interface;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import Dados.BD;
import Dados.Pessoa;
import Dados.PessoaEvento;

public class Janela_Listar extends JPanel
{
	JTextArea ta_informacoes;
	JScrollPane scroll;
	JTextField en_id;
	JButton bt_ok;
	JLabel lb_texto,lb_id;
	
	Janela_Listar()
	{
		this.setSize(600, 20);
		this.setLayout(null);
		OuvinteListarPessoa Lp;
		Lp = new OuvinteListarPessoa();
		
		lb_texto = new JLabel("Pesquise os partipantes do evento");
		lb_texto.setSize(200,20);
		lb_texto.setLocation(220,0);
		this.add(lb_texto);
		
		bt_ok = new JButton("OK");
		bt_ok.setSize(100,30);
		bt_ok.setLocation(400,100);
		bt_ok.addMouseListener(Lp);
		this.add(bt_ok);
		
		ta_informacoes =new JTextArea();
		ta_informacoes.setSize(300,200);
		ta_informacoes.setLocation(35,35);
		ta_informacoes.setEditable(true);
	    this.add(ta_informacoes);
	    
	    scroll = new JScrollPane();
	    scroll.setViewportView(ta_informacoes);
	    scroll.setSize(300,200);
	    scroll.setLocation(35,25);
	    this.add(scroll);
	    
	    lb_id = new JLabel("ID");
	    lb_id.setSize(50,30);
	    lb_id.setLocation(380,65);
		this.add(lb_id);
		
		en_id = new JTextField();
		en_id.setSize(120,20);
		en_id.setLocation(400,70);
		this.add(en_id);
	}
		public class OuvinteListarPessoa implements MouseListener
		{
			String cpf,id;
			int i,j;
			BD aux;
			Object[] v;
			Object[] p;
			public OuvinteListarPessoa()
			{
				aux=new BD("");
			}

			@Override
			public void mouseClicked(MouseEvent arg0)
			{
				id = en_id.getText();
				v=aux.obterLista("PessoaEvento");
				p = aux.obterLista("Pessoa");
				ta_informacoes.setText("");
				for(i=0;i<aux.getCont3();i++)
				{
					PessoaEvento varPessoaEvento = (PessoaEvento)v[i];
					if(id.equals(varPessoaEvento.getID())) 
					{
						ta_informacoes.append(varPessoaEvento.getCPF() + "   -   " + varPessoaEvento.getID() + "\n");  
					}
				}
			}
			@Override
			public void mouseEntered(MouseEvent arg0)
			{
				// TODO Auto-generated method stub
				
			}
			@Override
			public void mouseExited(MouseEvent arg0)
			{
				// TODO Auto-generated method stub
				
			}
			@Override
			public void mousePressed(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}
			@Override
			public void mouseReleased(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}
		}
	}
