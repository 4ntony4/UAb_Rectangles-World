#ifndef BASE_H
#define BASE_H

#define X 80
#define Y 25

typedef struct coordenadas
{
    int x;
    int y;
} coordenadas;

typedef struct retangulo
{
    int l;
    int h;
    coordenadas iEsq, iDir, sEsq, sDir;
} retangulo;

void inicializaEcran(char ecran[X][Y]);
void imprimeEcran(char ecran[X][Y]);

#endif //BASE_H
