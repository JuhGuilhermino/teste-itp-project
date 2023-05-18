#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    FILE * arq_original;
    arq_original = fopen("teste.ppm", "rt");
    
    //craindo um arq de saida
    FILE * arq_saida;
    arq_saida = fopen("saida.ppm", "wt");

    //lendo o cabeçalho
    char tipo1;
    int tipo2, coluna, linha, rgb_max;
    fscanf(arq_original, "%c%d\n%d %d\n%d\n", &tipo1, &tipo2, &coluna, &linha, &rgb_max);
    fprintf(arq_saida, "%c%d\n%d %d\n%d\n", tipo1, tipo2, coluna, linha, rgb_max);

    //declarando a matriz
    int img[256][256];

    //ler img e transformar em uma matriz
    for (int l = 0; l < linha; l++){
        for (int c = 0; c < coluna*3; c++){
            int pixel;
            fscanf(arq_original, "%d", &pixel);
            img[l][c] = pixel;
        }
    }

    //printf("%d %d %d", img[0][0], img[0][1], img[0][2]);

    //trasnformar em escala de cinza 
    int r, g, b;
    for (int l = 0; l < linha; l++){
        for (int c = 0; c < coluna*3; c+=3){
            int cinza;
            r = img[l][c];
            g = img[l][c+1];
            b = img[l][c+2];
            cinza =  (r+g+b)/3;
            fprintf(arq_saida, "%d %d %d ", cinza, cinza, cinza);
        }
        if (l<linha-1){
            fprintf(arq_saida, "\n");
        }
    }
    
    //imprimir img
    /*for (int l = 0; l < linha; l++){
        for (int c = 0; c < coluna*3; c++){
            fprintf(arq_saida, "%d ", img[l][c]);
        }
        if (l<linha-1){
            fprintf(arq_saida, "\n");
        }
    }*/
}