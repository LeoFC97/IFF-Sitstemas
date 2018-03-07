package primeiroPrograma;
 
public class Equacao
{
    double a,b,c;
    Equacao(double a,double b,double c)
    {
        this.a=a;
        this.b=b;
        this.c=c;
    }
    double delta() { return b*b-4*a*c; }
    double x1() {return -b+Math.sqrt(this.delta())/(2*a); }
    double x2() {return -b-Math.sqrt(this.delta())/(2*a); }
}