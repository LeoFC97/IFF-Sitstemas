package Model;

import java.awt.Graphics;

import javax.swing.JFrame;

@SuppressWarnings("serial")

public abstract class Vao extends JFrame
{
	int x;
	int y;
	int tamanho;
	int direcao;
	
	abstract void desenhar(Graphics g);
	
	public Vao(int x,int y,int tamanho)
	{
		this.x=x;
		this.y=y;
		this.tamanho=tamanho;
	}

}
