#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //Função responsavel por cadastrar usúarios no sistema
{
	//Inicio criçaõ de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando inforção do usúario
	scanf("%s", cpf); //%s referece a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar o valor das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo 'w' siguinifica escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,","); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coleta informações do usúario
	scanf("%s",nome); //%s referece a strings
	
	file = fopen(arquivo, "a"); // Arbre o arquivo
	fprintf(file,nome);
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coleta informaçãoes do usúario
	scanf("%s",sobrenome); //%s referece a strings
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,sobrenome);
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coleta informações do usúario
	scanf("%s",cargo); //%s referece a strings
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file,cargo);
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa o sistema
	
} // Final da função registrar

int deletar() // Função responsavel por deletar usúarios
{
	//Criação da variáveis/strings
	char cpf[40];
	//Final das variáveis/strings
	
	printf("Digite o CPF do usúario a ser deletado: "); //Coleta o CPF que o usúario deseja deletar
	scanf("%s",cpf); //%S referece a strings
	
	remove(cpf); // Dlera o CPF escolhido pelo usúario
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo
	
	if(file == NULL) // Teste para validar se o CPF digitado está cadastrado
	{
		printf("O usúario não se encontra no sistema!\n"); // Retorna de inforção para o usúario
		system("pause"); // Pausa o sistema
	} // Final da validação
	
} // Final da funçaõ deletar

int consultar() // Função responsavel por consultar usúarios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Criação das variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Final das variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); // Coleta o CPF que o usúario deseja consultar
	scanf("%s",cpf); //%s referece a strings
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo
	
	if(file == NULL) // Teste para validar se o CPF digitado não está cadastrado
	{
		printf("Não foi possível localizar o arquivo!\n"); // Retornada ao usúario caso o CPF informado não esteja cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Validação para o CPF Digitado que se encontra cadastrado
	{
		printf("\nEssas são as informações do usuário: "); // Retorno ao usúario caso o CPF seja encontrado
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa o sistema
	
} // Final da função consultar 



int main()
{
	int opcao=0; //Definido as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ### \n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); // Final do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); // Responsavel por limpar a tela
	    
	    
	    switch(opcao) // Inicio da seleção do menu
	    {
	    	case 1:
	    	registrar(); //Chamada de funções
	    	break;
	    		
	    	case 2:
	    	consultar();
	    	break;
	    	
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	default:
	    	printf("Essa opção não está disponivel!\n");
	    	system("pause");
	    	break;	
		} //final da seleção
	    
	 
	}
}
