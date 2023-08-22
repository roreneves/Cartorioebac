#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o responsavel por cadastrar us�arios no sistema
{
	//Inicio cri�a� de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando infor��o do us�ario
	scanf("%s", cpf); //%s referece a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar o valor das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo 'w' siguinifica escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,","); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coleta informa��es do us�ario
	scanf("%s",nome); //%s referece a strings
	
	file = fopen(arquivo, "a"); // Arbre o arquivo
	fprintf(file,nome);
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coleta informa��oes do us�ario
	scanf("%s",sobrenome); //%s referece a strings
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,sobrenome);
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coleta informa��es do us�ario
	scanf("%s",cargo); //%s referece a strings
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,cargo);
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa o sistema
	
} // Final da fun��o registrar

int deletar() // Fun��o responsavel por deletar us�arios
{
	//Cria��o da vari�veis/strings
	char cpf[40];
	//Final das vari�veis/strings
	
	printf("Digite o CPF do us�ario a ser deletado: "); //Coleta o CPF que o us�ario deseja deletar
	scanf("%s",cpf); //%S referece a strings
	
	remove(cpf); // Dlera o CPF escolhido pelo us�ario
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo
	
	if(file == NULL) // Teste para validar se o CPF digitado est� cadastrado
	{
		printf("O us�ario n�o se encontra no sistema!\n"); // Retorna de infor��o para o us�ario
		system("pause"); // Pausa o sistema
	} // Final da valida��o
	
} // Final da fun�a� deletar

int consultar() // Fun��o responsavel por consultar us�arios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Cria��o das vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Final das vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); // Coleta o CPF que o us�ario deseja consultar
	scanf("%s",cpf); //%s referece a strings
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo
	
	if(file == NULL) // Teste para validar se o CPF digitado n�o est� cadastrado
	{
		printf("N�o foi poss�vel localizar o arquivo!\n"); // Retornada ao us�ario caso o CPF informado n�o esteja cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Valida��o para o CPF Digitado que se encontra cadastrado
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Retorno ao us�ario caso o CPF seja encontrado
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa o sistema
	
} // Final da fun��o consultar 



int main()
{
	int opcao=0; //Definido as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); // Final do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); // Responsavel por limpar a tela
	    
	    
	    switch(opcao) // Inicio da sele��o do menu
	    {
	    	case 1:
	    	registrar(); //Chamada de fun��es
	    	break;
	    		
	    	case 2:
	    	consultar();
	    	break;
	    	
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	default:
	    	printf("Essa op��o n�o est� disponivel!\n");
	    	system("pause");
	    	break;	
		} //final da sele��o
	    
	 
	}
}
