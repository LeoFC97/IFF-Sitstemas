package Dados;

public class Pessoa
{
	public String nome,cpf,email;
	
	public Pessoa(String nomE, String cpF, String emaiL)
	{
		this.nome=nomE;
		this.cpf=cpF;
		this.email=emaiL;
	}
	public String getNome()
	{
		return nome;
	}
	public String getCPF()
	{
		return cpf;
	}
	public String getEmail()
	{
		return email;
	}
}
