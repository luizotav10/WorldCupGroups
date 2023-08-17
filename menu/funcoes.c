#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcoes.h"
#include <windows.h>

pote1 p1[8];
pote2 p2[8];
pote3 p3[8];
pote4 p4[8];
grupos g[32];
int vls1[8];
int vls2[8];
int vls3[8];
int vls4[8];

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void aleatorio(int *v)
{
    int rnd[8],i,aux;
    for(i=0;i<8;i++)
    {
        rnd[i]=0+(rand () % 8);
    }

    for(i=0;i<7;i++)
    {
        aux=v[rnd[i]];
        v[rnd[i]]=v[rnd[i+1]];
        v[rnd[i+1]]=aux;
    }

}

void aleatorio1(int *v)
{

    int random[7],i,aux;

    for(i=0;i<7;i++)
    {
        random[i]=1+(rand () % 7);
    }

    for(i=0;i<6;i++)
    {
        aux=v[random[i]];
        v[random[i]]=v[random[i+1]];
        v[random[i+1]]=aux;
    }
}

void aleatoriog(int *v)
{
    int rnd[3],i,aux;
    for(i=0;i<3;i++)
    {
        rnd[i]=0+(rand () % 3);
    }

    for(i=0;i<2;i++)
    {
        aux=v[rnd[i]];
        v[rnd[i]]=v[rnd[i+1]];
        v[rnd[i+1]]=aux;
    }
}


void Intrucoes(){


    int escolha;
    system("cls");
    printf("\n");
    printf("\t--------------------|Instrucoes de uso para o simulador de sorteio de grupos|------------------------\t\n\n");
    printf("\tA utilizacao do software independe do cadastro dos classificados, ou seja os times a serem sorteados.\t\n");
    printf("\tPorem, caso o usuario deseje utilizar, precisara apenas informar os nomes as classificacoes dos times\t\n");
    printf("\te as confederacoes pertencentes. Para a utilizacao do programa o usuario tem acesso ao seguinte menu:\t\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t    MENU\t\t\t\t\t\t\t");
    printf("\n");
    printf("\n\t\t\t\t\t\t|1-Instrucoes\t\t  |\n\t\t\t\t\t\t|2-Cadastrar Classificados|\n\t\t\t\t\t\t|3-Sortear Grupos\t  |\n\t\t\t\t\t\t|4-Log do Sorteio\t  |\n\t\t\t\t\t\t|5-Qual a Probabilidade?  |\n\t\t\t\t\t\t|6-Sair\t\t\t  |");
    printf("\n\n");
    printf("\tA opcao 3-Sorteio de grupos o usuario tem acesso ao sorteio no estilo oficial de sorteio da FIFA ao vivo.\t\n");
    printf("\tA opcao 4-Log do Sorteio apresentara a sequencia em que os grupos foram formados no sorteio realizado.\t\n\n");
    printf("\tA opcao 5- Qual a probabilidade? ira solicitar 2 a 4 selecoes e o programa ira calcular e apresentar\t\n");
    printf("\tna tela qual a probabilidade destas selecoes pertencerem ao mesmo grupo.\n\n");
    printf("\tA opcao 6-Sair encerra o simulador de sorteio de grupos da copa do mundo\n\n\n");
    printf("Tecle 1 para encerrar as instrucoes");
    scanf("%d",&escolha);
    if(escolha==1){
        printf("\nFim das instrucoes\n");
        main();
    }

}


void CadastrarClassificados(){

    FILE *paisescadastrados;
    classificados c[32];
    int i=0,j=0,aux=0;
    system("cls");
    printf("\t Cadastro de Classificados para a FIFA World Cup 2018\n\n\n");//mudar cor
    printf("Cadastrando Classificado 1, pais sede:\n\n");
    printf("Qual pais ira sediar a copa do mundo?\n");
    setbuf(stdin, NULL);
    fgets(c[0].pais,20,stdin);
    c[0].pais[strlen(c[0].pais)-1]='\0';
    printf("\n");
    printf("O pais sede pertence a qual confederação?\n");
    printf("1- UEFA \n2- CONMEBOL \n3- CONCACAF \n4- CAF \n5- AFC\n");
    do{
        scanf("%d",&c[0].confederacao);
    }while(c[0].confederacao<1||c[0].confederacao>5);
    c[0].ranking=0;
    system("cls");

    for(i=1;i<32;i++)
    {
        printf("\t Cadastro de Classificados para a FIFA World Cup 2018\n\n\n");//mudar cor
        printf("Cadastrando Classificado %d:\n\n", i+1);
        printf("Digite o nome do pais de numero %d:\n", i+1);
        setbuf(stdin, NULL);
        fgets(c[i].pais,20,stdin);
        c[i].pais[strlen(c[i].pais)-1]='\0';
        printf("\n");


        printf("Digite a confederacao que o pais %s pertence: \n", c[i].pais);
        printf("1- UEFA \n2- CONMEBOL \n3- CONCACAF \n4- CAF \n5- AFC\n");
        do{
            scanf("%d",&c[i].confederacao);
        }while(c[i].confederacao<1||c[i].confederacao>5);
        printf("\n");

        printf("Defina o ranking do/da %s:\n", c[i].pais);
        scanf("%d",&c[i].ranking);


        printf("\n");
        system("cls");

    }

    paisescadastrados = fopen("lista de cadastrados.txt","w");

    for(aux=0;j<32;aux++)
    {
        for(i=0;i<32;i++)
        {
            if(c[i].ranking==aux)
            {
                fprintf(paisescadastrados,"%s %d %d\n",c[i].pais, c[i].confederacao, c[i].ranking);
                j++;
            }
        }
    }

    fclose(paisescadastrados);
    main();
}


void Sair(){
    int escolha;
    do{
    system("cls");
    printf("\tDeseja mesmo sair?\n\t1-Sim\t2-Nao\n");
    scanf("%d",&escolha);
    if(escolha==1){
        exit(0);
    }
    if(escolha==2){
        main();
    }
    }while(escolha!=1 && escolha!=2);
}

void potes()
{
    //setlocale(LC_ALL, "Portuguese");
    FILE *fp;
    int i;
    fp=fopen("lista de cadastrados.txt","r");
    rewind(fp);

        for(i=0;i<8;i++)
        {
            fscanf(fp,"%s", p1[i].pais1);
            fscanf(fp,"%d", &p1[i].confederacao1);
            fscanf(fp,"%d", &p1[i].ranking1);
        }
        for(i=0;i<8;i++)
        {
            fscanf(fp,"%s", p2[i].pais2);
            fscanf(fp,"%d", &p2[i].confederacao2);
            fscanf(fp,"%d", &p2[i].ranking2);
        }
        for(i=0;i<8;i++)
        {
            fscanf(fp,"%s", p3[i].pais3);
            fscanf(fp,"%d", &p3[i].confederacao3);
            fscanf(fp,"%d", &p3[i].ranking3);
        }
        for(i=0;i<8;i++)
        {
            fscanf(fp,"%s", p4[i].pais4);
            fscanf(fp,"%d", &p4[i].confederacao4);
            fscanf(fp,"%d", &p4[i].ranking4);
        }



    fclose(fp);

}
void probabilidadesorteio()
{
    potes();
    int i,aux,j,x,n,k=0,num=0,z;
    float probabilidade;
    int v1[8]={0,1,2,3,4,5,6,7};
    int v2[8]={0,1,2,3,4,5,6,7};
    int v3[8]={0,1,2,3,4,5,6,7};
    int v4[8]={0,1,2,3,4,5,6,7};

    prob *p = NULL;
    system("cls");
    printf("\t\tDigite quantas selecoes serao inseridas 'de 2 a 4'\n\t\t");
    do
    {
        scanf("%d",&n);
    }while(n!=2&&n!=4&&n!=3);

    p=(prob*)malloc(n*sizeof(prob));

    system("cls");
    gotoxy(13,3);
    printf("POTE 1");
    gotoxy(5,4);
    printf("Pais");
    gotoxy(20,4);
    printf("Ranking");
    for(i=0;i<8;i++)
    {
        gotoxy(3,5+i);
        printf("%s",p1[i].pais1);
        gotoxy(23,5+i);
        printf("%d",p1[i].ranking1);

    }

    gotoxy(43,3);
    printf("POTE 2");
    gotoxy(35,4);
    printf("Pais");
    gotoxy(50,4);
    printf("Ranking");
    for(i=0;i<8;i++)
    {
        gotoxy(33,5+i);
        printf("%s",p2[i].pais2);
        gotoxy(53,5+i);
        printf("%d",p2[i].ranking2);

    }

    gotoxy(73,3);
    printf("POTE 3");
    gotoxy(65,4);
    printf("Pais");
    gotoxy(80,4);
    printf("Ranking");
    for(i=0;i<8;i++)
    {
        gotoxy(63,5+i);
        printf("%s",p3[i].pais3);
        gotoxy(83,5+i);
        printf("%d",p3[i].ranking3);

    }

    gotoxy(103,3);
    printf("POTE 4");
    gotoxy(95,4);
    printf("Pais");
    gotoxy(110,4);
    printf("Ranking");
    for(i=0;i<8;i++)
    {
        gotoxy(93,5+i);
        printf("%s",p4[i].pais4);
        gotoxy(113,5+i);
        printf("%d",p4[i].ranking4);

    }

    printf("\n\n\n");

    for(i=0;i<n;i++)
    {
        if(i==2)
        {
            gotoxy(60,15);
        }
        if(i==3)
        {
            gotoxy(60,23);
        }
        printf("\tDigite o pais de numero %d \n\n\t-",i+1);
        setbuf(stdin, NULL);
        if(i==2)
        {
            gotoxy(60,17);
        }
        if(i==3)
        {
            gotoxy(60,25);
        }
        fgets(p[i].paisp,20,stdin);
        p[i].paisp[strlen(p[i].paisp)-1]='\0';
        printf("\n");
        if(i==2)
        {
            gotoxy(60,19);
        }
        if(i==3)
        {
            gotoxy(60,27);
        }
        printf("\tDigite o ranking do pais de numero %d \n\n\t-",i+1);
        if(i==2)
        {
            gotoxy(60,21);
        }
        if(i==3)
        {
            gotoxy(60,29);
        }
        scanf("%d",&p[i].rankingp);
        printf("\n\n");
    }
    system("cls");
    printf("\t\t\tProcessando dados, aguarde alguns segundos...");
    printf("\n\n");

    for(k=0;k<1000000;k++)
    {

    dnv:
    aleatorio1(v1);
    aleatorio(v2);
    aleatorio(v3);
    aleatorio(v4);



    for(i=0;i<32;i++)
    {
        g[i].confederacaog=0;
    }

    /////////// P O T E 1 /////////////////
    for(i=0;i<8;i++)
    {
        strcpy(g[i].paisg,p1[v1[i]].pais1);
        g[i].confederacaog=p1[v1[i]].confederacao1;
        g[i].rankingg=p1[v1[i]].ranking1;
    }

    ///////// P O T E 2 /////////////

    for(j=0;j<8;j++)//FOR DO POTE 2
    {
        aux=p2[v2[j]].confederacao2;
        for(i=0;i<8;i++)//FOR DAS POSIÇOES DO POTE 2
    {
        if(g[i+8].confederacaog==0)
        {

            if(aux!=1&&g[i].confederacaog==aux)
            {
                while((g[i].confederacaog==aux))
                {
                    i++;
                    if(g[i+8].confederacaog!=0)
                    {
                        i++;
                    }
                    if(i>7)
                    {
                        goto dnv;
                    }
                }
                if(g[i+8].confederacaog==0)
                {
                    strcpy(g[i+8].paisg,p2[v2[j]].pais2);
                    g[i+8].confederacaog=p2[v2[j]].confederacao2;
                    g[i+8].rankingg=p2[v2[j]].ranking2;
                    i=20;
                }


            }
            else
            {
                strcpy(g[i+8].paisg,p2[v2[j]].pais2);
                g[i+8].confederacaog=p2[v2[j]].confederacao2;
                g[i+8].rankingg=p2[v2[j]].ranking2;
                i=20;

            }

        }

    }

    }

    //////////// P O T E 3 /////////////////

    for(j=0;j<8;j++)
    {
        aux=p3[v3[j]].confederacao3;
        for(i=0;i<8;i++)
        {
            if(g[i+16].confederacaog==0)
            {
                x=0;
                if(aux==1&&(g[i].confederacaog==1&&g[i+8].confederacaog==1))
                {
                    x=1;
                    while(g[i].confederacaog==1&&g[i+8].confederacaog==1)
                    {
                        i++;
                        if(g[i+16].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }

                    if(g[i+16].confederacaog==0)
                    {
                        strcpy(g[i+16].paisg,p3[v3[j]].pais3);
                        g[i+16].confederacaog=p3[v3[j]].confederacao3;
                        g[i+16].rankingg=p3[v3[j]].ranking3;
                        i=100;
                    }
                }

                if(aux!=1&&(g[i].confederacaog==aux||g[i+8].confederacaog==aux))
                {
                    x=1;
                    while(g[i].confederacaog==aux||g[i+8].confederacaog==aux)
                    {
                        i++;
                        if(g[i+16].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }

                    if(g[i+16].confederacaog==0)
                    {
                        strcpy(g[i+16].paisg,p3[v3[j]].pais3);
                        g[i+16].confederacaog=p3[v3[j]].confederacao3;
                        g[i+16].rankingg=p3[v3[j]].ranking3;
                        i=100;
                    }

                }
                if(x==0)
                {
                    strcpy(g[i+16].paisg,p3[v3[j]].pais3);
                    g[i+16].confederacaog=p3[v3[j]].confederacao3;
                    g[i+16].rankingg=p3[v3[j]].ranking3;
                    i=100;
                    x=0;

                }


            }
        }
    }

    //////////// P O T E 4 ///////////////////

    for(j=0;j<8;j++)
    {
        aux=p4[v4[j]].confederacao4;
        for(i=0;i<8;i++)
        {
            if(g[i+24].confederacaog==0)
            {
                x=0;
                if(aux==1&&((g[i].confederacaog==1&&g[i+8].confederacaog==1)||(g[i].confederacaog==1&&g[i+16].confederacaog==1)||(g[i+8].confederacaog==1&&g[i+16].confederacaog==1)))
                {
                    x=1;
                    while((g[i].confederacaog==1&&g[i+8].confederacaog==1)||(g[i].confederacaog==1&&g[i+16].confederacaog==1)||(g[i+8].confederacaog==1&&g[i+16].confederacaog==1))
                    {
                        i++;
                        if(g[i+24].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }

                    if(g[i+24].confederacaog==0)
                    {
                        strcpy(g[i+24].paisg,p4[v4[j]].pais4);
                        g[i+24].confederacaog=p4[v4[j]].confederacao4;
                        g[i+24].rankingg=p4[v4[j]].ranking4;
                        i=100;
                    }
                }

                if(aux!=1&&(g[i].confederacaog==aux||g[i+8].confederacaog==aux||g[i+16].confederacaog==aux))
                {
                    x=1;
                    while(g[i].confederacaog==aux||g[i+8].confederacaog==aux||g[i+16].confederacaog==aux)
                    {
                        i++;
                        if(g[i+24].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }
                    if(g[i+24].confederacaog==0)
                    {
                        strcpy(g[i+24].paisg,p4[v4[j]].pais4);
                        g[i+24].confederacaog=p4[v4[j]].confederacao4;
                        g[i+24].rankingg=p4[v4[j]].ranking4;
                        i=100;
                    }

                }
                if(x==0)
                {
                    strcpy(g[i+24].paisg,p4[v4[j]].pais4);
                    g[i+24].confederacaog=p4[v4[j]].confederacao4;
                    g[i+24].rankingg=p4[v4[j]].ranking4;
                    i=100;
                    x=0;
                }



            }
        }
    }
    for(i=0;i<32;i++)
    {
        if(g[i].confederacaog==0)
        {
            goto dnv;
        }
    }

    if(n==2)
    {

        for(i=0;i<8;i++)
        {
            if(p[0].rankingp==g[0+i].rankingg||p[0].rankingp==g[8+i].rankingg||p[0].rankingp==g[16+i].rankingg||p[0].rankingp==g[24+i].rankingg)
            {

                if(p[1].rankingp==g[0+i].rankingg||p[1].rankingp==g[8+i].rankingg||p[1].rankingp==g[16+i].rankingg||p[1].rankingp==g[24+i].rankingg)
                {

                    num++;
                }

            }
        }

    }

    if(n==3)
    {

        for(i=0;i<8;i++)
        {
            if(p[0].rankingp==g[0+i].rankingg||p[0].rankingp==g[8+i].rankingg||p[0].rankingp==g[16+i].rankingg||p[0].rankingp==g[24+i].rankingg)
            {

                if(p[1].rankingp==g[0+i].rankingg||p[1].rankingp==g[8+i].rankingg||p[1].rankingp==g[16+i].rankingg||p[1].rankingp==g[24+i].rankingg)
                {
                    if(p[2].rankingp==g[0+i].rankingg||p[2].rankingp==g[8+i].rankingg||p[2].rankingp==g[16+i].rankingg||p[2].rankingp==g[24+i].rankingg)
                    {
                        num++;
                    }


                }

            }
        }

    }

    if(n==4)
    {

        for(i=0;i<8;i++)
        {
            if(p[0].rankingp==g[0+i].rankingg||p[0].rankingp==g[8+i].rankingg||p[0].rankingp==g[16+i].rankingg||p[0].rankingp==g[24+i].rankingg)
            {

                if(p[1].rankingp==g[0+i].rankingg||p[1].rankingp==g[8+i].rankingg||p[1].rankingp==g[16+i].rankingg||p[1].rankingp==g[24+i].rankingg)
                {
                    if(p[2].rankingp==g[0+i].rankingg||p[2].rankingp==g[8+i].rankingg||p[2].rankingp==g[16+i].rankingg||p[2].rankingp==g[24+i].rankingg)
                    {
                        if(p[3].rankingp==g[0+i].rankingg||p[3].rankingp==g[8+i].rankingg||p[3].rankingp==g[16+i].rankingg||p[3].rankingp==g[24+i].rankingg)
                        {
                            num++;
                        }
                    }


                }

            }
        }

    }



    }
    probabilidade= (float) num/1000000;
    probabilidade=probabilidade*100;
    system("cls");
    printf("\t\t\tA probabilidade dessas selecoes estarem no mesmo grupo e de %.2f\n\n\n", probabilidade);
    free(p);
    printf("Digite '1' para retornar ao Menu principal");
    do
    {
        scanf("%d",&z);
    }while(z!=1);
    main();


}

void sorteio()
{
    potes();
    int i,aux,j,x,y,aux1,aux2,aux8;

    int v1[8]={0,1,2,3,4,5,6,7};
    int v2[8]={0,1,2,3,4,5,6,7};
    int v3[8]={0,1,2,3,4,5,6,7};
    int v4[8]={0,1,2,3,4,5,6,7};
    int g1[3]={8,16,24};
    char paisaux[20];
    int confederacaoaux;
    dnv:
    aleatorio1(v1);
    aleatorio(v2);
    aleatorio(v3);
    aleatorio(v4);

    for(i=0;i<32;i++)
    {
        g[i].confederacaog=0;
    }

    /////////// P O T E 1 /////////////////
    for(i=0;i<8;i++)
    {
        strcpy(g[i].paisg,p1[v1[i]].pais1);
        g[i].confederacaog=p1[v1[i]].confederacao1;
    }

    ///////// P O T E 2 /////////////

    for(j=0;j<8;j++)//FOR DO POTE 2
    {
        aux=p2[v2[j]].confederacao2;
        for(i=0;i<8;i++)//FOR DAS POSIÇOES DO POTE 2
    {
        if(g[i+8].confederacaog==0)
        {

            if(aux!=1&&g[i].confederacaog==aux)
            {
                while((g[i].confederacaog==aux))
                {
                    i++;
                    if(g[i+8].confederacaog!=0)
                    {
                        i++;
                    }
                    if(i>7)
                    {
                        goto dnv;
                    }
                }
                if(g[i+8].confederacaog==0)
                {
                    strcpy(g[i+8].paisg,p2[v2[j]].pais2);
                    g[i+8].confederacaog=p2[v2[j]].confederacao2;
                    i=20;
                }


            }
            else
            {
                strcpy(g[i+8].paisg,p2[v2[j]].pais2);
                g[i+8].confederacaog=p2[v2[j]].confederacao2;
                i=20;

            }

        }

    }

    }

    //////////// P O T E 3 /////////////////

    for(j=0;j<8;j++)
    {
        aux=p3[v3[j]].confederacao3;
        for(i=0;i<8;i++)
        {
            if(g[i+16].confederacaog==0)
            {
                x=0;
                if(aux==1&&(g[i].confederacaog==1&&g[i+8].confederacaog==1))
                {
                    x=1;
                    while(g[i].confederacaog==1&&g[i+8].confederacaog==1)
                    {
                        i++;
                        if(g[i+16].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }

                    if(g[i+16].confederacaog==0)
                    {
                        strcpy(g[i+16].paisg,p3[v3[j]].pais3);
                        g[i+16].confederacaog=p3[v3[j]].confederacao3;
                        i=100;
                    }
                }

                if(aux!=1&&(g[i].confederacaog==aux||g[i+8].confederacaog==aux))
                {
                    x=1;
                    while(g[i].confederacaog==aux||g[i+8].confederacaog==aux)
                    {
                        i++;
                        if(g[i+16].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }

                    if(g[i+16].confederacaog==0)
                    {
                        strcpy(g[i+16].paisg,p3[v3[j]].pais3);
                        g[i+16].confederacaog=p3[v3[j]].confederacao3;
                        i=100;
                    }

                }
                if(x==0)
                {
                    strcpy(g[i+16].paisg,p3[v3[j]].pais3);
                    g[i+16].confederacaog=p3[v3[j]].confederacao3;
                    i=100;
                    x=0;

                }


            }
        }
    }

    //////////// P O T E 4 ///////////////////

    for(j=0;j<8;j++)
    {
        aux=p4[v4[j]].confederacao4;
        for(i=0;i<8;i++)
        {
            if(g[i+24].confederacaog==0)
            {
                x=0;
                if(aux==1&&((g[i].confederacaog==1&&g[i+8].confederacaog==1)||(g[i].confederacaog==1&&g[i+16].confederacaog==1)||(g[i+8].confederacaog==1&&g[i+16].confederacaog==1)))
                {
                    x=1;
                    while((g[i].confederacaog==1&&g[i+8].confederacaog==1)||(g[i].confederacaog==1&&g[i+16].confederacaog==1)||(g[i+8].confederacaog==1&&g[i+16].confederacaog==1))
                    {
                        i++;
                        if(g[i+24].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }

                    if(g[i+24].confederacaog==0)
                    {
                        strcpy(g[i+24].paisg,p4[v4[j]].pais4);
                        g[i+24].confederacaog=p4[v4[j]].confederacao4;
                        i=100;
                    }
                }

                if(aux!=1&&(g[i].confederacaog==aux||g[i+8].confederacaog==aux||g[i+16].confederacaog==aux))
                {
                    x=1;
                    while(g[i].confederacaog==aux||g[i+8].confederacaog==aux||g[i+16].confederacaog==aux)
                    {
                        i++;
                        if(g[i+24].confederacaog!=0)
                        {
                            i++;
                        }
                        if(i>7)
                        {
                            goto dnv;
                        }
                    }
                    if(g[i+24].confederacaog==0)
                    {
                        strcpy(g[i+24].paisg,p4[v4[j]].pais4);
                        g[i+24].confederacaog=p4[v4[j]].confederacao4;
                        i=100;
                    }

                }
                if(x==0)
                {
                    strcpy(g[i+24].paisg,p4[v4[j]].pais4);
                    g[i+24].confederacaog=p4[v4[j]].confederacao4;
                    i=100;
                    x=0;
                }



            }
        }
    }
    for(i=0;i<32;i++)
    {
        if(g[i].confederacaog==0)
        {
            goto dnv;
        }
    }

    for(j=0;j<8;j++)
    {
        aleatoriog(g1);

        for(i=0;i<2;i++)
        {
            strcpy(paisaux,g[g1[i]].paisg);
            confederacaoaux=g[g1[i]].confederacaog;

            strcpy(g[g1[i]].paisg,g[g1[i+1]].paisg);
            g[g1[i]].confederacaog=g[g1[i+1]].confederacaog;

            strcpy(g[g1[i+1]].paisg,paisaux);
            g[g1[i+1]].confederacaog=confederacaoaux;
        }

        for(i=0;i<3;i++)
        {
            g1[i]=g1[i]+1;
        }

    }
    system("cls");
    printf("\n");

    for(i=0;i<8;i++)
    {
        vls1[i]=v1[i];
        vls2[i]=v2[i];
        vls3[i]=v3[i];
        vls4[i]=v4[i];
    }


    gotoxy(40,1);
    printf("SORTEIO DOS GRUPOS DA FIFA WORLD CUP");
    gotoxy(22,5);
    printf("Grupo A");
    gotoxy(43,5);
    printf("Grupo B");
    gotoxy(63,5);
    printf("Grupo C");
    gotoxy(83,5);
    printf("Grupo D");
    gotoxy(22,14);
    printf("Grupo E");
    gotoxy(43,14);
    printf("Grupo F");
    gotoxy(63,14);
    printf("Grupo G");
    gotoxy(83,14);
    printf("Grupo H");

    aux=1;
    aux1=1;

    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p1[v1[j]].pais1,g[i].paisg))
        {
            i++;
        }

        if(i<4)
        {
            aux=aux+20;
            gotoxy(aux,7);
            printf("1)%s",g[i].paisg);
        }
        if(i>=4&&i<8)
        {
            aux1=aux1+20;
            gotoxy(aux1,16);
            printf("1)%s",g[i].paisg);

        }
        do
        {
            gotoxy(1,20);
            printf("\n\n");
            printf("Digite 1 para continuar...\n");
            scanf("%d",&aux8);
        }while(aux8!=1);
    }

    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p2[v2[j]].pais2,g[i].paisg))
        {
            i++;

        }
        if(i>=8&&i<12)
        {
            if(i==8) gotoxy(21,8);
            if(i==9) gotoxy(41,8);
            if(i==10) gotoxy(61,8);
            if(i==11) gotoxy(81,8);

            printf("2)%s",g[i].paisg);

        }
        if(i>=12&&i<16)
        {
            if(i==12) gotoxy(21,17);
            if(i==13) gotoxy(41,17);
            if(i==14) gotoxy(61,17);
            if(i==15) gotoxy(81,17);
            printf("2)%s",g[i].paisg);

        }
        if(i>=16&&i<20)
        {
            if(i==16) gotoxy(21,9);
            if(i==17) gotoxy(41,9);
            if(i==18) gotoxy(61,9);
            if(i==19) gotoxy(81,9);
            printf("3)%s",g[i].paisg);

        }
        if(i>=20&&i<24)
        {
            if(i==20) gotoxy(21,18);
            if(i==21) gotoxy(41,18);
            if(i==22) gotoxy(61,18);
            if(i==23) gotoxy(81,18);
            printf("3)%s",g[i].paisg);

        }

        if(i>=24&&i<28)
        {
            if(i==24) gotoxy(21,10);
            if(i==25) gotoxy(41,10);
            if(i==26) gotoxy(61,10);
            if(i==27) gotoxy(81,10);
            printf("4)%s",g[i].paisg);

        }

        if(i>=28&&i<32)
        {
            if(i==28) gotoxy(21,19);
            if(i==29) gotoxy(41,19);
            if(i==30) gotoxy(61,19);
            if(i==31) gotoxy(81,19);
            printf("4)%s",g[i].paisg);

        }


        do
        {
            gotoxy(1,20);
            printf("\n\n\n");
            scanf("%d",&aux8);
        }while(aux8!=1);
    }


    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p3[v3[j]].pais3,g[i].paisg))
        {
            i++;

        }
        if(i>=8&&i<12)
        {
            if(i==8) gotoxy(21,8);
            if(i==9) gotoxy(41,8);
            if(i==10) gotoxy(61,8);
            if(i==11) gotoxy(81,8);

            printf("2)%s",g[i].paisg);

        }
        if(i>=12&&i<16)
        {
            if(i==12) gotoxy(21,17);
            if(i==13) gotoxy(41,17);
            if(i==14) gotoxy(61,17);
            if(i==15) gotoxy(81,17);
            printf("2)%s",g[i].paisg);

        }
        if(i>=16&&i<20)
        {
            if(i==16) gotoxy(21,9);
            if(i==17) gotoxy(41,9);
            if(i==18) gotoxy(61,9);
            if(i==19) gotoxy(81,9);
            printf("3)%s",g[i].paisg);

        }
        if(i>=20&&i<24)
        {
            if(i==20) gotoxy(21,18);
            if(i==21) gotoxy(41,18);
            if(i==22) gotoxy(61,18);
            if(i==23) gotoxy(81,18);
            printf("3)%s",g[i].paisg);

        }

        if(i>=24&&i<28)
        {
            if(i==24) gotoxy(21,10);
            if(i==25) gotoxy(41,10);
            if(i==26) gotoxy(61,10);
            if(i==27) gotoxy(81,10);
            printf("4)%s",g[i].paisg);

        }

        if(i>=28&&i<32)
        {
            if(i==28) gotoxy(21,19);
            if(i==29) gotoxy(41,19);
            if(i==30) gotoxy(61,19);
            if(i==31) gotoxy(81,19);
            printf("4)%s",g[i].paisg);

        }


        do
        {
            gotoxy(1,20);
            printf("\n\n\n");
            scanf("%d",&aux8);
        }while(aux8!=1);
    }

    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p4[v4[j]].pais4,g[i].paisg))
        {
            i++;

        }
        if(i>=8&&i<12)
        {
            if(i==8) gotoxy(21,8);
            if(i==9) gotoxy(41,8);
            if(i==10) gotoxy(61,8);
            if(i==11) gotoxy(81,8);

            printf("2)%s",g[i].paisg);

        }
        if(i>=12&&i<16)
        {
            if(i==12) gotoxy(21,17);
            if(i==13) gotoxy(41,17);
            if(i==14) gotoxy(61,17);
            if(i==15) gotoxy(81,17);
            printf("2)%s",g[i].paisg);

        }
        if(i>=16&&i<20)
        {
            if(i==16) gotoxy(21,9);
            if(i==17) gotoxy(41,9);
            if(i==18) gotoxy(61,9);
            if(i==19) gotoxy(81,9);
            printf("3)%s",g[i].paisg);

        }
        if(i>=20&&i<24)
        {
            if(i==20) gotoxy(21,18);
            if(i==21) gotoxy(41,18);
            if(i==22) gotoxy(61,18);
            if(i==23) gotoxy(81,18);
            printf("3)%s",g[i].paisg);

        }

        if(i>=24&&i<28)
        {
            if(i==24) gotoxy(21,10);
            if(i==25) gotoxy(41,10);
            if(i==26) gotoxy(61,10);
            if(i==27) gotoxy(81,10);
            printf("4)%s",g[i].paisg);

        }

        if(i>=28&&i<32)
        {
            if(i==28) gotoxy(21,19);
            if(i==29) gotoxy(41,19);
            if(i==30) gotoxy(61,19);
            if(i==31) gotoxy(81,19);
            printf("4)%s",g[i].paisg);

        }


        do
        {
            gotoxy(1,20);
            printf("\n\n\n");
            scanf("%d",&aux8);
        }while(aux8!=1);
    }



    printf("\n");
    printf("\n");
    printf("Digite '1' para retornar ao menu principal");
    printf("\n");
    do
    {
        scanf("%d",&y);
    }while(y!=1);
    main();


}

void logdosorteio()
{
    int i,j,x,y;
    for(i=0;i<32;i++)
    {
        if(g[i].confederacaog!=1&&g[i].confederacaog!=2&&g[i].confederacaog!=3&&g[i].confederacaog!=4&&g[i].confederacaog!=5)
        {
            system("cls");
            printf("\t\tPrimeiramente, realize o sorteio dos grupos\n\n");
            printf("Caso deseje voltar ao menu principal, digite '1'\n");
            printf("Caso deseje realizar o sorteio agora, digite '2'\n");
            do
            {
                scanf("%d",&x);
            }while(x!=1&&x!=2);
            if(x==1)
            {
                main();
            }
            if(x==2)
            {
                sorteio();
            }
        }
    }
    i=0;
    system("cls");
    printf("POTE 1\n");
    for(j=0;j<8;j++)
    {
        while(strcmp(p1[vls1[j]].pais1,g[i].paisg))
        {
            i++;
        }

        printf("%s",g[i].paisg);
        if(i==0||i==8||i==16||i==24)
        {
            printf(" -> Grupo A  1\n");
        }
        if(i==1||i==9||i==17||i==25)
        {
            printf(" -> Grupo B 1\n");
        }
        if(i==2||i==10||i==18||i==26)
        {
            printf(" -> Grupo C 1\n");
        }
        if(i==3||i==11||i==19||i==27)
        {
            printf(" -> Grupo D 1\n");
        }
        if(i==4||i==12||i==20||i==28)
        {
            printf(" -> Grupo E 1\n");
        }

        if(i==5||i==13||i==21||i==29)
        {
            printf(" -> Grupo F 1\n");
        }

        if(i==6||i==14||i==22||i==30)
        {
            printf(" -> Grupo G 1\n");
        }

        if(i==7||i==15||i==23||i==31)
        {
            printf(" -> Grupo H 1\n");
        }

    }
    printf("\n\n");
    printf("POTE 2\n");

    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p2[vls2[j]].pais2,g[i].paisg))
        {
            i++;
        }

        printf("%s",g[i].paisg);
        if(i==0||i==8||i==16||i==24)
        {
            printf(" -> Grupo A");
            if(i==8)
            {
                printf(" 2P\n");
            }
            if(i==16)
            {
                printf(" 3P\n");
            }
            if(i==24)
            {
                printf(" 4P\n");
            }
        }
        if(i==1||i==9||i==17||i==25)
        {
            printf(" -> Grupo B");
            if(i==9)
            {
                printf(" 2P\n");
            }
            if(i==17)
            {
                printf(" 3P\n");
            }
            if(i==25)
            {
                printf(" 4P\n");
            }
        }
        if(i==2||i==10||i==18||i==26)
        {
            printf(" -> Grupo C");
            if(i==10)
            {
                printf(" 2P\n");
            }
            if(i==18)
            {
                printf(" 3P\n");
            }
            if(i==26)
            {
                printf(" 4P\n");
            }
        }
        if(i==3||i==11||i==19||i==27)
        {
            printf(" -> Grupo D");
            if(i==11)
            {
                printf(" 2P\n");
            }
            if(i==19)
            {
                printf(" 3P\n");
            }
            if(i==27)
            {
                printf(" 4P\n");
            }
        }
        if(i==4||i==12||i==20||i==28)
        {
            printf(" -> Grupo E");
            if(i==12)
            {
                printf(" 2P\n");
            }
            if(i==20)
            {
                printf(" 3P\n");
            }
            if(i==28)
            {
                printf(" 4P\n");
            }
        }

        if(i==5||i==13||i==21||i==29)
        {
            printf(" -> Grupo F");
            if(i==13)
            {
                printf(" 2P\n");
            }
            if(i==21)
            {
                printf(" 3P\n");
            }
            if(i==29)
            {
                printf(" 4P\n");
            }
        }

        if(i==6||i==14||i==22||i==30)
        {
            printf(" -> Grupo G");
            if(i==14)
            {
                printf(" 2P\n");
            }
            if(i==22)
            {
                printf(" 3P\n");
            }
            if(i==30)
            {
                printf(" 4P\n");
            }
        }

        if(i==7||i==15||i==23||i==31)
        {
            printf(" -> Grupo H");
            if(i==15)
            {
                printf(" 2P\n");
            }
            if(i==23)
            {
                printf(" 3P\n");
            }
            if(i==31)
            {
                printf(" 4P\n");
            }
        }


    }
    printf("\n\n");
    printf("POTE 3\n");

    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p3[vls3[j]].pais3,g[i].paisg))
        {
            i++;
        }

        printf("%s",g[i].paisg);
        if(i==0||i==8||i==16||i==24)
        {
            printf(" -> Grupo A");
            if(i==8)
            {
                printf(" 2P\n");
            }
            if(i==16)
            {
                printf(" 3P\n");
            }
            if(i==24)
            {
                printf(" 4P\n");
            }
        }
        if(i==1||i==9||i==17||i==25)
        {
            printf(" -> Grupo B");
            if(i==9)
            {
                printf(" 2P\n");
            }
            if(i==17)
            {
                printf(" 3P\n");
            }
            if(i==25)
            {
                printf(" 4P\n");
            }
        }
        if(i==2||i==10||i==18||i==26)
        {
            printf(" -> Grupo C");
            if(i==10)
            {
                printf(" 2P\n");
            }
            if(i==18)
            {
                printf(" 3P\n");
            }
            if(i==26)
            {
                printf(" 4P\n");
            }
        }
        if(i==3||i==11||i==19||i==27)
        {
            printf(" -> Grupo D");
            if(i==11)
            {
                printf(" 2P\n");
            }
            if(i==19)
            {
                printf(" 3P\n");
            }
            if(i==27)
            {
                printf(" 4P\n");
            }
        }
        if(i==4||i==12||i==20||i==28)
        {
            printf(" -> Grupo E");
            if(i==12)
            {
                printf(" 2P\n");
            }
            if(i==20)
            {
                printf(" 3P\n");
            }
            if(i==28)
            {
                printf(" 4P\n");
            }
        }

        if(i==5||i==13||i==21||i==29)
        {
            printf(" -> Grupo F");
            if(i==13)
            {
                printf(" 2P\n");
            }
            if(i==21)
            {
                printf(" 3P\n");
            }
            if(i==29)
            {
                printf(" 4P\n");
            }
        }

        if(i==6||i==14||i==22||i==30)
        {
            printf(" -> Grupo G");
            if(i==14)
            {
                printf(" 2P\n");
            }
            if(i==22)
            {
                printf(" 3P\n");
            }
            if(i==30)
            {
                printf(" 4P\n");
            }
        }

        if(i==7||i==15||i==23||i==31)
        {
            printf(" -> Grupo H");
            if(i==15)
            {
                printf(" 2P\n");
            }
            if(i==23)
            {
                printf(" 3P\n");
            }
            if(i==31)
            {
                printf(" 4P\n");
            }
        }
    }

    printf("\n\n");
    printf("POTE 4\n");

    for(j=0;j<8;j++)
    {
        i=0;
        while(strcmp(p4[vls4[j]].pais4,g[i].paisg))
        {
            i++;
        }

        printf("%s",g[i].paisg);
        if(i==0||i==8||i==16||i==24)
        {
            printf(" -> Grupo A");
            if(i==8)
            {
                printf(" 2P\n");
            }
            if(i==16)
            {
                printf(" 3P\n");
            }
            if(i==24)
            {
                printf(" 4P\n");
            }
        }
        if(i==1||i==9||i==17||i==25)
        {
            printf(" -> Grupo B");
            if(i==9)
            {
                printf(" 2P\n");
            }
            if(i==17)
            {
                printf(" 3P\n");
            }
            if(i==25)
            {
                printf(" 4P\n");
            }
        }
        if(i==2||i==10||i==18||i==26)
        {
            printf(" -> Grupo C");
            if(i==10)
            {
                printf(" 2P\n");
            }
            if(i==18)
            {
                printf(" 3P\n");
            }
            if(i==26)
            {
                printf(" 4P\n");
            }
        }
        if(i==3||i==11||i==19||i==27)
        {
            printf(" -> Grupo D");
            if(i==11)
            {
                printf(" 2P\n");
            }
            if(i==19)
            {
                printf(" 3P\n");
            }
            if(i==27)
            {
                printf(" 4P\n");
            }
        }
        if(i==4||i==12||i==20||i==28)
        {
            printf(" -> Grupo E");
            if(i==12)
            {
                printf(" 2P\n");
            }
            if(i==20)
            {
                printf(" 3P\n");
            }
            if(i==28)
            {
                printf(" 4P\n");
            }
        }

        if(i==5||i==13||i==21||i==29)
        {
            printf(" -> Grupo F");
            if(i==13)
            {
                printf(" 2P\n");
            }
            if(i==21)
            {
                printf(" 3P\n");
            }
            if(i==29)
            {
                printf(" 4P\n");
            }
        }

        if(i==6||i==14||i==22||i==30)
        {
            printf(" -> Grupo G");
            if(i==14)
            {
                printf(" 2P\n");
            }
            if(i==22)
            {
                printf(" 3P\n");
            }
            if(i==30)
            {
                printf(" 4P\n");
            }
        }

        if(i==7||i==15||i==23||i==31)
        {
            printf(" -> Grupo H");
            if(i==15)
            {
                printf(" 2P\n");
            }
            if(i==23)
            {
                printf(" 3P\n");
            }
            if(i==31)
            {
                printf(" 4P\n");
            }
        }
    }
    printf("\n\n");
    printf("Digite '1' para retornar ao Menu\n");
    do
    {
        scanf("%d",&y);
    }while(y!=1);
    main();





}
