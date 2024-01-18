#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings
#include <iostream>

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings

	FILE *file; //Cria o arquivo no BD
	file = fopen(arquivo, "a"); //Cria o arquivo no BD
	fprintf(file, cpf); //Salvo o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

    sprintf(arquivo, "%s.txt", cpf);

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo para escrita!\n");
        return 1; // Mensagem de erro
    }

    // Escreve as informações no arquivo
    fprintf(file, "%s,%s,%s,%s\n", cpf, nome, sobrenome, cargo);

    fclose(file);

	printf("Usuário cadastrado com sucesso!\n");
    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Repetindo bib. de idiomas pra essa função

    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!\n");
        return 1; // Mensagem de erro
    }

    // Informações do arquivo
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", cpf, nome, sobrenome, cargo) == 4)
    {
        printf("CPF: %s\n", cpf);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s\n", sobrenome);
        printf("Cargo: %s\n", cargo);
        printf("\n");
    }

    fclose(file);

    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    //Mensagens ao deletar usuário
    if (remove(cpf) == 0) //Caso de usuário existente
    {
    	printf("Usuário deletado com sucesso!\n");
	}
	else 			//Caso de usuário não registrado
	{
		printf("Usuário não encontrado. Verifique o CPF e tente novamente.\n");
	}
	
	system("pause");
}

int main()
{
    int opcao = 0;
    int laco = 1;
    std::string senhadigitada;
    std::string cpf_digitado;

    std::cout << "### Cartório da EBAC ###\n\n";
    std::cout << "Login de administrador!\n\nDigite o CPF: ";
    std::cin >> cpf_digitado;
    
    std::cout << "Digite a senha: ";
    std::cin >> senhadigitada;

	if (cpf_digitado == "admin" && senhadigitada == "admin")
    {
    

	    for (laco = 1; laco == 1;)
	    {
	        system("cls");
	        setlocale(LC_ALL, "Portuguese");
	
	        printf("### Cartório da EBAC ###\n\n");
	        printf("Escolha a opção desejada do menu: \n\n");
	        printf("\t1 - Registrar Nomes\n");
	        printf("\t2 - Consultar Nomes\n");
	        printf("\t3 - Deletar Nomes\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Opção: "); // fim do menu
	
	        scanf("%d", &opcao); // armazenando escolha do usuário
	
	        system("cls"); // limpar a tela
	
	        switch (opcao)
	        {
	        case 1:
	            registro();
	            break;
	
	        case 2:
	            consulta();
	            break;
	
	        case 3:
	            deletar();
	            break;
	            
	        case 4:
	        	printf("Obrigado por utilizar o sistema!\n");
	        	return 0;
	        	break;
	
	        default:
	            printf("Essa opção não está disponível!\n");
	            system("pause");
	            break;
	        }//fechando casos switch
	    }//fechando função "for"
	}//fechando if de senha correta
	
	else
	    std::cout << "Login ou senha incorretos!\n";
	
    return 0;
}

