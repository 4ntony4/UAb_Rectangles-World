#include "base.h"
#include "calculos.h"
#include <stdio.h>

void inicializaEcran(char ecran[X][Y])
{
  int i, j;

  //inicializa vector ecran
  for(j=0;j<Y;j++){
    for(i=0;i<X;i++){
      ecran[i][j]=' ';
    }
  }
}

void imprimeEcran(char ecran[X][Y])
{
  int i, j;

  for(j=Y-1;j>=0;j--){
    for(i=0;i<X;i++){
      printf("%c",ecran[i][j]);
    }
    printf("\n");
  }
}
