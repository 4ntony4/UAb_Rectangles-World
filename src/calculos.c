#include "base.h"
#include "calculos.h"
#include <stdio.h>

void create(retangulo r, char ecran[X][Y])
{
  int i, j;

  //gravar canto inferior esquerdo
  ecran[r.iEsq.x-1][r.iEsq.y-1]='+';

  //calcular restantes cantos
  r.iDir.x=r.iEsq.x+r.l-1;
  r.iDir.y=r.iEsq.y;
  r.sEsq.x=r.iEsq.x;
  r.sEsq.y=r.iEsq.y+r.h-1;
  r.sDir.x=r.iEsq.x+r.l-1;
  r.sDir.y=r.iEsq.y+r.h-1;

  //gravar restantes cantos no vetor ecran
  ecran[r.iDir.x-1][r.iDir.y-1]='+';
  ecran[r.sEsq.x-1][r.sEsq.y-1]='+';
  ecran[r.sDir.x-1][r.sDir.y-1]='+';

  //gravar linhas horizontais
  for(i=r.iEsq.x+1;i<r.iDir.x;i++){
    if(ecran[i-1][r.iEsq.y-1]!='+'){
      ecran[i-1][r.iEsq.y-1]='-';
    }
    if(ecran[i-1][r.sEsq.y-1]!='+'){
      ecran[i-1][r.sEsq.y-1]='-';
    }
  }

  //gravar linhas verticais
  for(j=r.iEsq.y+1;j<r.sDir.y;j++){
    if(ecran[r.iEsq.x-1][j-1]!='+'){
      ecran[r.iEsq.x-1][j-1]='|';
    }
    if(ecran[r.iDir.x-1][j-1]!='+'){
      ecran[r.iDir.x-1][j-1]='|';
    }
  }
}

int checkSuspensao(retangulo r, char ecran[X][Y])
{
  int i;

  //se o canto inferior esquerdo ja estiver no chao
  if(r.iEsq.y==1){
    return 0; //nao esta suspenso
  }

  //se a linha horizontal imediatamente abaixo do retangulo esta vazia
  for(i=r.iEsq.x-1;i<=(r.iEsq.x+r.l-1);i++){
    if(ecran[i][r.iEsq.y-2]!=' '){
      return 0; //nao esta suspenso
    }
  }

  //se o canto inferior esquerdo tem algum caracter ah esquerda
  if(ecran[r.iEsq.x-2][r.iEsq.y-1]!=' '){
    return 0; //nao esta suspenso
  }

  //se o canto inferior direito tem algum caracter ah direita
  if(ecran[r.iEsq.x+r.l-1][r.iEsq.y-1]!=' '){
    return 0; //nao esta suspenso
  }

  return 1; //esta suspenso
}
