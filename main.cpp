#include <iostream>
#include <stdio.h>

int main(){

    FILE * arq_in;
    FILE * arq_out;

    arq_in = fopen("galinhos.ppm", "rt");
    if (arq_in ==  NULL){
        printf("erro");
        return 1;
    }
    
    arq_out = fopen("galinhos2.txt", "wt");
    if (arq_in ==  NULL){
        printf("erro");
        return 1;
    }

    //char line[1847];
    //fscanf(arq_in, "%[^\n]\n", line);

    char a;
    int c,coluna, linha, rgb_max;
    fscanf(arq_in, "%c%d\n%d %d\n%d\n", &a, &c, &coluna, &linha, &rgb_max);
    fprintf(arq_out, "%c%d\n%d %d\n%d\n", a, c, coluna, linha, rgb_max);
    
    int imagem[linha][coluna];
    int r, g, b;
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            fscanf(arq_in,"%d %d %d", &r, &g, &b);
            fprintf(arq_out,"%d %d %d\n", r, g, b);
        }
    }
    
}