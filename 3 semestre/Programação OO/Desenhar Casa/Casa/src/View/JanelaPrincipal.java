 package View;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;

import Model.Casa;
import Model.Comodo;
import Model.Janela;
import Model.Passagem;
import Model.Porta;
import Model.Vao;

public class JanelaPrincipal  extends JFrame
{
	/**
	 * 
	 */
	private static final long serialVersionUID = -1798612011309687656L;
	Casa minhaCasa;
	public JanelaPrincipal()
	{
		setSize(700, 700);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		getContentPane().setLayout(null);
		setVisible(true);
		minhaCasa = new Casa(550,650);
		
		minhaCasa.adicionarComodo(new Comodo("Cozinha",60, 60, 300,150));
		minhaCasa.adicionarComodo(new Comodo("Quarto",370, 60, 220,300));
		minhaCasa.adicionarComodo(new Comodo("Banheiro",370, 370, 220,100));
		minhaCasa.adicionarComodo(new Comodo("Sala",60, 220, 300,250));
		minhaCasa.adicionarComodo(new Comodo("Varanda",60, 480, 300,210));
		minhaCasa.adicionarComodo(new Comodo("Garagem",370, 480, 220,210));
		minhaCasa.adicionarVao(new Passagem(200,210, 0,0));
		minhaCasa.adicionarVao(new Passagem(280,470, 0,1));
		minhaCasa.adicionarVao(new Passagem(360,390, 0,2));
		minhaCasa.adicionarVao(new Passagem(360,280, 0,2));
		minhaCasa.adicionarVao(new Janela(150, 50, 0, 1));
		minhaCasa.adicionarVao(new Janela(430, 50, 0, 1));
		minhaCasa.adicionarVao(new Janela(590, 150, 0, 0));
		minhaCasa.adicionarVao(new Janela(50, 300, 0, 0));
		minhaCasa.adicionarVao(new Janela(100, 470, 0, 1));
		minhaCasa.adicionarVao(new Janela(590, 395, 0, 4));
		minhaCasa.adicionarVao(new Porta(370,460, 0,1));
		minhaCasa.adicionarVao(new Porta(370,350, 0,1));
		minhaCasa.adicionarVao(new Porta(350,400, 0,0));


	}
	public void paint(Graphics g)
	{
		super.paint(g);
		minhaCasa.desenhar(g);
	}
	
}

