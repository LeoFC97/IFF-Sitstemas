package Model;

import java.awt.Graphics;

import javax.swing.JFrame;

public class Comodo extends JFrame
{
	String nome;
	int largura,altura;
	int x,y;
	public Comodo(String nome,int x,int y,int largura,int altura)
	{
		super();
		this.nome =nome;
		this.x=x;
		this.y=y;
		this.largura = largura;
		this.altura=altura;
	}
	
	public int getX()
	{
		return x;
	}
	public int getY()	
	{
		return y;
	}
	public String getNome()
	{
		return nome;
	}
	public float getLargura()
	{
		return largura;
	}
	public float getAltura()
	{
		return altura; 
	}
	
	public void desenhar (Graphics g)	
	{
		super.paint(g);
		g.drawRect(x, y, largura, altura);
		g.drawString(nome,x+10,y+15);
	}
}
