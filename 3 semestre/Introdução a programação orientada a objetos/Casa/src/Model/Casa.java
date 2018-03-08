package Model;

import java.awt.Graphics;

import javax.swing.JFrame;

public class Casa 
{
	/**
	 * 
	 */
	int largura, altura;
	int numComodos,numVaos;
	Comodo[] comodos;
	Vao[] vaos;
	public Casa(int largura, int altura)
	{
		this.largura = largura;
		this.altura = altura;
		numVaos=0;
		numComodos=0;
		comodos=new Comodo[20];
		vaos=new Vao[20];
	}
	public void adicionarComodo(Comodo x)
	{
		comodos[numComodos]=x;
		numComodos++;
	}
	public void adicionarVao(Vao x)
	{
		vaos[numVaos]=x;
		numVaos++;
	}
	public void desenhar(Graphics g)
	{
		g.drawRect(50,50,this.largura,this.altura);
		int i;
		for(i=0;i<numComodos;i++)
		{
			comodos[i].desenhar(g);
		}
		for(i=0;i<numVaos;i++)
		{
			vaos[i].desenhar(g);
		}
	}
}
