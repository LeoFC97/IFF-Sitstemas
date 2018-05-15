package Questao9;

import javax.swing.JOptionPane;

public class Main {

	public static void main(String[] args)
	{
		new Circulo();
		JOptionPane.showMessageDialog(null, Circulo.calcularArea());
		JOptionPane.showMessageDialog(null, Circulo.calcularDiametro());
		JOptionPane.showMessageDialog(null, Circulo.calcularPerimetro());
		
	}

}
