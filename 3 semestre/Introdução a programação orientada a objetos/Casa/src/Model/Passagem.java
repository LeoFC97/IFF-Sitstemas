package Model;

import java.awt.Color;
import java.awt.Graphics;

@SuppressWarnings("serial")
public class Passagem extends Vao
{
	int largura = 150;
	int comprimento=10;
	public Passagem(int x,int y,int tamanho, int direcao)
	{
		super(x,y,tamanho);
		this.x=x;
		this.y=y;
		this.tamanho=tamanho;
		this.direcao=direcao;
	}

	@Override
	public
	void desenhar(Graphics g)
	{
		super.paint(g);
		g.setColor(Color.LIGHT_GRAY);
		if(direcao==0)
		{
			g.drawRect(x, y, largura,comprimento);
		}
		if(direcao==1)
		{
			largura=70;
			comprimento = 10;
			g.drawRect(x,y,largura,comprimento);
		}
		if(direcao==2)
		{
			largura=10;
			comprimento=70;
			g.drawRect(x, y, largura, comprimento);
		}
		
	}
	
}

