import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Janela extends JFrame
{
	JButton bt_calcular,bt_limpar;
	JLabel lb_A,lb_B,lb_C,lb_Delta,lb_X1,lb_X2;
	JTextField en_A,en_B,en_C,en_Delta,en_X1,en_X2;
	public Janela()
	{
		Ouvinte_Limpar o_limpar;
		o_limpar =new Ouvinte_Limpar();
		Ouvinte_Ok o_ok;
		o_ok = new Ouvinte_Ok();
		this.setSize(450,300);
		this.setTitle("Calculadora Segundo Grau");
		this.setResizable(false);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLayout(null);
		this.getContentPane().setBackground(new Color(224,255,255));

		en_A = new JTextField();
		en_A.setSize(100,30);
		en_A.setLocation(100,10);
		this.add(en_A);
		
		en_B = new JTextField();
		en_B.setSize(100,30);
		en_B.setLocation(100,40);
		this.add(en_B);
		
		en_C = new JTextField();
		en_C.setSize(100,30);
		en_C.setLocation(100,70);
		this.add(en_C);
		
		lb_A = new JLabel("Valor de A: ");
		lb_A.setSize(100,30);
		lb_A.setLocation(20,10);
		this.add(lb_A);
		
		lb_B = new JLabel("Valor de B: ");
		lb_B.setSize(100,30);
		lb_B.setLocation(20,40);
		this.add(lb_B);
		
		lb_C = new JLabel("Valor de C: ");
		lb_C.setSize(100,30);
		lb_C.setLocation(20,70);
		this.add(lb_C);
		
		lb_Delta = new JLabel("Valor de Delta: ");
		lb_Delta.setSize(100,30);
		lb_Delta.setLocation(230,10);
		this.add(lb_Delta);
		
		lb_X1 = new JLabel("Valor de X1: ");
		lb_X1.setSize(100,30);
		lb_X1.setLocation(230,40);
		this.add(lb_X1);
	
		en_Delta = new JTextField();
		en_Delta.setSize(100,30);
		en_Delta.setLocation(320,10);
		en_Delta.setEditable(false);
		this.add(en_Delta);
		
		en_X1 = new JTextField();
		en_X1.setSize(100,30);
		en_X1.setLocation(320,40);
		en_X1.setEditable(false);
		this.add(en_X1);
		
		en_X2 = new JTextField();
		en_X2.setSize(100,30);
		en_X2.setLocation(320,70);
		en_X2.setEditable(false);
		this.add(en_X2);
		
		
		lb_X2 = new JLabel("Valor de X2: ");
		lb_X2.setSize(100,30);
		lb_X2.setLocation(230,70);
		this.add(lb_X2);
		
		
		bt_calcular =new JButton ("Calcular");
		bt_calcular.setSize(100,30);
		bt_calcular.setLocation(90,200);
		bt_calcular.addMouseListener(o_ok);
		this.add (bt_calcular);
		
		bt_limpar =new JButton ("Limpar");
		bt_limpar.setSize(100,30);
		bt_limpar.setLocation(200,200);
		bt_limpar.addMouseListener(o_limpar);
		this.add(bt_limpar);
		
		this.setVisible(true);
		
	}
	public class Ouvinte_Limpar implements  MouseListener 
	{

		@Override
		public void mouseClicked(MouseEvent e) {
			en_A.setText("");
			en_B.setText("");
			en_C.setText("");
			en_Delta.setText("");
			en_X1.setText("");
			en_X2.setText("");
			
			
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
	public class Ouvinte_Ok implements  MouseListener 
	{

		@Override
		public void mouseClicked(MouseEvent e) {
			double a,b,c;
			Equacao eq;
			a=Double.parseDouble(en_A.getText());
			b=Double.parseDouble(en_B.getText());
			c=Double.parseDouble(en_C.getText());
			eq= new Equacao(a,b,c);
			
			en_Delta.setText(Double.toString(eq.delta()));
			en_X1.setText(Double.toString(eq.x1()));
			en_X2.setText(Double.toString(eq.x2()));
			
			
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
