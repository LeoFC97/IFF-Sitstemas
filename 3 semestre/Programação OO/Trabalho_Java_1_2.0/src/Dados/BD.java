package Dados;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class BD {
	String path;
	int cont1, cont2, cont3;
	public BD(String path) {
		this.path = path;
	} 
	
	public void salvar(Object obj){
		BufferedWriter arq;
		try {
			if(obj instanceof Pessoa) {
				arq = new BufferedWriter(new FileWriter(path+"pessoa.txt",true));
				arq.write("\n"+((Pessoa)obj).getCPF()+"|"+((Pessoa)obj).getNome()+"|"+((Pessoa)obj).getEmail()+"\r\n");
				arq.close();
			}
			if(obj instanceof Evento) {
				arq = new BufferedWriter(new FileWriter(path+"evento.txt",true));
				arq.write(((Evento)obj).getNome()+"|"+((Evento)obj).getData()+"|"+((Evento)obj).getLocal()+"|"+((Evento)obj).getID()+"\r\n");
				arq.close();
			}
			if(obj instanceof PessoaEvento) {
				arq = new BufferedWriter(new FileWriter(path+"pessoa_evento.txt",true));
				arq.write(((PessoaEvento)obj).getCPF()+"|"+((PessoaEvento)obj).getID()+"\n");
				arq.close();
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public Object[] obterLista(String tipo) {
		Object[] lista = new Object[1000];
		BufferedReader arq;
		String linha;
		StringTokenizer tokens;
		cont1 = 1;
		try {
			if(tipo.equals("Pessoa")) {
				arq = new BufferedReader(new FileReader(path+"pessoa.txt"));
				while(arq.ready()) {
					linha = arq.readLine();
					tokens = new StringTokenizer(linha,"|");
					String cp = tokens.nextToken();
					String np = tokens.nextToken();
					String ep = tokens.nextToken();
					Pessoa p = new Pessoa(np, cp, ep);
					lista[cont1] = p;
					cont1++;
				}
				arq.close();
			}
			if(tipo.equals("Evento")) {
				arq = new BufferedReader(new FileReader(path+"evento.txt"));
				cont2 =0;
				while(arq.ready()) {
					linha = arq.readLine();
					tokens = new StringTokenizer(linha,"|");
					String na = tokens.nextToken();
					String ta = tokens.nextToken();
					String la = tokens.nextToken();
					String IDa = tokens.nextToken();
					Evento a = new Evento(na, ta, la, IDa);
					lista[cont2] = a;
					cont2++;
				}
				arq.close();
			}
			if(tipo.equals("PessoaEvento")) {
				arq = new BufferedReader(new FileReader(path+"pessoa_evento.txt"));
				cont3=0;
				while(arq.ready()) {
					linha = arq.readLine();
					tokens = new StringTokenizer(linha,"|");
					String np = tokens.nextToken();
					String na = tokens.nextToken();
					PessoaEvento pa = new PessoaEvento(np, na);
					lista[cont3] = pa;
					cont3++;
				}
				arq.close();	
			}
		
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		return lista;
	}
	
	public int getCont1(){
		return cont1;
	}
	public int getCont2(){
		return cont2;
	}
	public int getCont3(){
		return cont3;
	}
}