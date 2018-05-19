package Questao9;

import javax.swing.JOptionPane;

public class Circulo {

	static double raio;
	
	Circulo()
	{
		raio = Float.parseFloat (JOptionPane.showInputDialog("Raio do circulo: "));
		
	}
	
	static double calcularArea()
	{
		return (Math.PI*Math.PI)*raio;
	}
	
	static double calcularPerimetro()
	{
		return 2*Math.PI * raio;
	}
	
	static double calcularDiametro()
	{
		return raio*2;
		
	}
}
