package primeiroPrograma;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
 
public class Janela extends JFrame{
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JButton bOK, bLimpa;
    JLabel lA,lB,lC,lDelta,lX1,lX2;
    JTextField tA,tB,tC,tDelta,tX1,tX2;
       
        //CONSTRUTOR
        public Janela(){
            OuvinteCalc oC;
            OuvinteLimp oL;
            oC = new OuvinteCalc();
            oL = new OuvinteLimp();
            this.setSize(700,450);
            this.setTitle("EU ESTIVE AQUI");
            this.setResizable(false);
            this.setLocation(450,200);
            this.setDefaultCloseOperation(EXIT_ON_CLOSE);
            this.setLayout(null);
           
            //Botões
            bOK = new JButton("Calcular");
            bOK.setSize(100,30);
            bOK.setLocation(180,350);
            bOK.addMouseListener(oC);
            this.add (bOK);
           
            bLimpa = new JButton("Limpar");
            bLimpa.setSize(100,30);
            bLimpa.setLocation(450,350);
            bLimpa.addMouseListener(oL);
            this.add (bLimpa);
           
            //LABELS
                //esquerda
            lA = new JLabel("Valor de A:");
            lA.setSize(80,30);
            lA.setLocation(90,100);
            this.add (lA);
           
            lB = new JLabel("Valor de B:");
            lB.setSize(80,30);
            lB.setLocation(90,150);
            this.add (lB);
           
            lC = new JLabel("Valor de C:");
            lC.setSize(80,30);
            lC.setLocation(90,200);
            this.add (lC);
                //direita
           
            lDelta = new JLabel("Delta:");
            lDelta.setSize(50,30);
            lDelta.setLocation(410,100);
            this.add (lDelta);
           
            lX1 = new JLabel("X1:");
            lX1.setSize(50,30);
            lX1.setLocation(410,150);
            this.add (lX1);
           
            lX2 = new JLabel("X2:");
            lX2.setSize(50,30);
            lX2.setLocation(410,200);
            this.add (lX2);
           
            //Textos
                //esquerda
            tA = new JTextField();
            tA.setSize(80,30);
            tA.setLocation(170,100);
            this.add (tA);
           
            tB = new JTextField();
            tB.setSize(80,30);
            tB.setLocation(170,150);
            this.add (tB);
           
            tC = new JTextField();
            tC.setSize(80,30);
            tC.setLocation(170,200);
            this.add (tC);
           
                //direita
            tDelta = new JTextField();
            tDelta.setSize(80,30);
            tDelta.setLocation(460,100);
            tDelta.setEditable(false);
            this.add (tDelta);
           
            tX1 = new JTextField();
            tX1.setSize(80,30);
            tX1.setLocation(460,150);
            tX1.setEditable(false);
            this.add (tX1);
           
            tX2 = new JTextField();
            tX2.setSize(80,30);
            tX2.setLocation(460,200);
            tX2.setEditable(false);
            this.add (tX2);
           
           
            this.setVisible(true);
        }
   
   
        //OUVINTELIMPAR
        public class OuvinteLimp implements MouseListener{
       
            public void mouseClicked(MouseEvent arg0) {
                tA.setText("");
                tB.setText("");
                tC.setText("");
            }

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}


			public void mouseReleased(MouseEvent e) {			
			}
			public void mouseEntered(MouseEvent e) {
				// 
			}
			public void mouseExited(MouseEvent e) {	
			}
        }
 
        //OUVINTECALCULAR
        public class OuvinteCalc implements MouseListener{
            double a,b,c;
            Equacao eq;
            public void mouseClicked(MouseEvent arg0) {
                a = Double.parseDouble(tA.getText());
                b = Double.parseDouble(tB.getText());
                c = Double.parseDouble(tC.getText());
                eq = new Equacao(a,b,c);
               
                tDelta.setText(Double.toString(eq.delta()));
                tX1.setText(Double.toString(eq.x1()));
                tX2.setText(Double.toString(eq.x2()));
            }
			public void mousePressed(MouseEvent e) {				
			}
			public void mouseReleased(MouseEvent e) {				
			}
			public void mouseEntered(MouseEvent e) {				
			}
			public void mouseExited(MouseEvent e) {				
			}
        }
       
}