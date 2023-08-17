#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void Intrucoes();

void CadastrarClassificados();

void probabilidadesorteio();

void Sair();

void potes();

void sorteio();

void aleatorio(int *v);

void aleatorio1(int *v);

void aleatoriog(int *v);

void logdosorteio();

void gotoxy(int x, int y);

typedef struct{
    char pais[20];
    int confederacao;
    int ranking;
}classificados;


typedef struct{
    char pais1[20];
    int confederacao1;
    int ranking1;
}pote1;

typedef struct{
    char pais2[20];
    int confederacao2;
    int ranking2;
}pote2;

typedef struct{
    char pais3[20];
    int confederacao3;
    int ranking3;
}pote3;

typedef struct{
    char pais4[20];
    int confederacao4;
    int ranking4;
}pote4;


typedef struct{
    char paisg[20];
    int confederacaog;
    int rankingg;
}grupos;

typedef struct{
    char paisp[20];
    int rankingp;
}prob;


#endif // FUNCOES_H_INCLUDED
