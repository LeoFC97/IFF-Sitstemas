package Dados;

public class PessoaEvento
{
	public String id,cpf;

	public PessoaEvento(String iD, String cpF)
	{
		this.id=iD;
		this.cpf=cpF;
				
	}
	public String getID()
	{
		return id;
	}
	public String getCPF()
	{
		return cpf;
	}
}
