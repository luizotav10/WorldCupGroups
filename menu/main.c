#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"



int main()
{
    srand(time(NULL));
    setlocale(LC_ALL," ");
    int opcao;
    system("cls");
    printf("\t\t\t\t\t\t  Selecione uma das opcoes:\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t    MENU\t\t\t\t\t\t\t");
    printf("\n");
    printf("\n\t\t\t\t\t\t|1-Instrucoes\t\t  |\n\t\t\t\t\t\t|2-Cadastrar Classificados|\n\t\t\t\t\t\t|3-Sortear Grupos\t  |\n\t\t\t\t\t\t|4-Log do Sorteio\t  |\n\t\t\t\t\t\t|5-Qual a Probabilidade?  |\n\t\t\t\t\t\t|6-Sair\t\t\t  |");
    printf("\n\n");

    do{
    scanf("%d",&opcao);
    switch(opcao){
    case 1:
        Intrucoes();
    break;
    case 2:
        CadastrarClassificados();
    break;
    case 3:
        sorteio();

    break;
    case 4:
        logdosorteio();

    break;
    case 5:
        probabilidadesorteio();

    break;

    }
    }while(opcao!=6);
    if(opcao==6){
        Sair();
    }
    return 0;
}
