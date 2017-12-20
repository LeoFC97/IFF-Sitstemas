package Interface;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Janela_Sobre extends JPanel

{
	JLabel lb_nome,lb_nome_professor,lb_data,lb_git,lb_materia;
	JButton bt_git;
	
	public Janela_Sobre()
	{
		this.setSize(380,300);
		this.setLayout(null);
		
		/*
		 * Labels
		 */
		//label com meu nome
		lb_nome=new JLabel("Aluno: Leonardo Fernandes Costa");
		lb_nome.setSize(300,20);
		lb_nome.setLocation(20,20);
		this.add(lb_nome);
		//label com meu nome
		
		//label com o nome do professor
		lb_nome_professor=new JLabel("Professor: Jonivan Coutinho Lisboa");
		lb_nome_professor.setSize(300,20);
		lb_nome_professor.setLocation(20,45);
		this.add(lb_nome_professor);
		//label com o nome do professor
		
		//botao do git
		bt_git=new JButton("GitHub");
		bt_git.setSize(85,20);
		bt_git.setLocation(80,80);
		bt_git.addMouseListener(new Ouvinte());
		this.add(bt_git);
		//botao do git
		
	/*	//label da data
		lb_data=new JLabel("23/11/2017");
		lb_data.setSize(120,20);
		lb_data.setLocation(100,160);
		this.add(lb_data);
		*///label da data
		this.setVisible(true);
	}
	public class Ouvinte implements MouseListener{
		
		
		@Override
		public void mouseClicked(MouseEvent arg0)
		{
			if(arg0.getSource()==bt_git)
			{
				new Git().setVisible(true);
			}
		}

		@Override
		public void mouseEntered(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseExited(MouseEvent arg0) {
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
