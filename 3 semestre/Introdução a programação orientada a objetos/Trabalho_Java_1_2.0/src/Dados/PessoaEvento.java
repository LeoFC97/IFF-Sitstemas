package Dados;

public class PessoaEvento
{
	public String id,cpf;

	public PessoaEvento(String cpF, String iD)
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
