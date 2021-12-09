#include "base.h"
#include "calculos.h"
#include <stdio.h>

int main()
{
  char ecran[X][Y];
  retangulo r;
  FILE *f;
  int aux;

  inicializaEcran(ecran);

  f=fopen("in/input.dat","r");
  if(f==NULL){
    printf("Erro ao ler o ficheiro.\n");
    return 0;
  }
  while(!feof(f)){
    fscanf(f,"%d;%d;%d;%d\n",&r.iEsq.x,&r.iEsq.y,&r.l,&r.h);
    create(r,ecran);
    aux=checkSuspensao(r,ecran);
    if(aux==1){ //o mundo estah inconsistente
      break;
    }
  }
  fclose(f);

  imprimeEcran(ecran);

  if(aux==1){
    printf("Inconsistente.\n");
  }else{
    printf("Consistente.\n");
  }
  
  return 0;
}
