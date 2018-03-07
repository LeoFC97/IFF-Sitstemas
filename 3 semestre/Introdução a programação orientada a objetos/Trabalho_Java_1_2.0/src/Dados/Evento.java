package Dados;

public class Evento
{
	public String nome,id,data,local;
	
	public Evento(String nomE,String iD,String datA,String locaL)
	{
		this.nome=nomE;
		this.id=iD;
		this.data=datA;
		this.local=locaL;
	}
	public String getNome()
	{
		return nome;
	}
	public String getID()
	{
		return id;
	}
	public String getData()
	{
		return data;
	}
	public String getLocal()
	{
		return local;
	}
}
