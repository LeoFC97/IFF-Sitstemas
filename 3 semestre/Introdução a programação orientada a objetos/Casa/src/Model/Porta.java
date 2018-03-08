package Model;

import java.awt.Color;
import java.awt.Graphics;

public class Porta extends Vao
{
	int largura=70;
	int comprimento=5;
	public Porta(int x, int y,int tamanho , int direcao)
	{
		super(x,y,tamanho);
		this.x=x;
		this.y=y;
		this.tamanho=tamanho;
		this.direcao=direcao;
	
	}
	void desenhar(Graphics g) {
		super.paint(g);
		g.setColor(Color.green);
		if(direcao==1)
		{
			largura=70;
			comprimento=5;
			g.drawRect(x, y, largura, comprimento);
			g.drawLine(x+70,y,x,y-70);
		}
		else
		{
			largura=5;
			comprimento=70;
			g.drawRect(x, y, largura, comprimento);
			g.drawLine(x, y, x-70, y+70);
		}
		
	}
	
}
 