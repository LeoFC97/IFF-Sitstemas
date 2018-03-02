package Model;

import java.awt.Color;
import java.awt.Graphics;

@SuppressWarnings("serial")

public class Janela extends Vao
{
	int largura,comprimento;
	public Janela(int x,int y,int tamanho,int direcao)
	{
		super(x, y, tamanho);
		this.x = x;
		this.y = y;
		this.tamanho = tamanho;
		this.direcao = direcao;
	}

	@Override
	public void desenhar(Graphics g)
	{
		super.paint(g);
		g.setColor(Color.MAGENTA);
		if(direcao==1)
		{
			largura=100;
			comprimento=5;
			g.drawRect(x, y, largura, comprimento);
			g.drawRect(x, y, largura+5, comprimento);
		}
		if(direcao==0)
		{
			largura=5;
			comprimento=100;
			g.drawRect(x, y, largura, comprimento);
			g.drawRect(x+5, y, largura, comprimento);
		}
		if(direcao==3)
		{
			largura=50;
			comprimento=5;
			g.drawRect(x, y, largura, comprimento);
			g.drawRect(x, y+5, largura, comprimento);
		}
		if(direcao==4)
		{
			largura=5;
			comprimento=50;
			g.drawRect(x, y, largura, comprimento);
			g.drawRect(x+5, y, largura, comprimento);
		}
	}
}
