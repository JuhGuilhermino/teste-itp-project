#include <iostream>
#include <stdio.h>
using namespace std;

void copiar(FILE * img_original){
    FILE * copia;
    copia = fopen("copia.ppm", "wt");

    char a;
    int c,coluna, linha, rgb_max;
    fscanf(img_original, "%c%d\n%d %d\n%d\n", &a, &c, &coluna, &linha, &rgb_max);
    fprintf(copia, "%c%d\n%d %d\n%d\n", a, c, coluna, linha, rgb_max);

    
    int r, g, b;
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            fscanf(img_original, "%d %d %d", &r, &g, &b);
            fprintf(copia,"%d %d %d\n", r, g, b);
        }
    }
}

void escala_cinza(FILE * img_original){
    FILE * img_cinza;
    img_cinza = fopen("galinhos_cinza.ppm", "wt");

    char a;
    int c,coluna, linha, rgb_max;
    fscanf(img_original, "%c%d\n%d %d\n%d\n", &a, &c, &coluna, &linha, &rgb_max);
    fprintf(img_cinza, "%c%d\n%d %d\n%d\n", a, c, coluna, linha, rgb_max);

    
    int r, g, b, cinza;
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            fscanf(img_original, "%d %d %d", &r, &g, &b);
            cinza = (r+g+b)/3;
            fprintf(img_cinza,"%d %d %d\n", cinza, cinza, cinza);
        }
    }
}

void reduzir(FILE * img_original){
    FILE * img_reduzida;
    img_reduzida = fopen("galinhos_reduzida.ppm", "wt");

    char a;
    int c,coluna, linha, rgb_max;
    fscanf(img_original, "%c%d\n%d %d\n%d\n", &a, &c, &coluna, &linha, &rgb_max);

    int coluna_nova, linha_nova;
    coluna_nova = coluna/2;
    linha_nova = linha/2;
    
    fprintf(img_reduzida, "%c%d\n%d %d\n%d", a, c, coluna_nova, linha_nova, rgb_max);

    
    int r1, g1, b1, r2, g2, b2, r3, g3, b3, r4, g4, b4, media_r, media_g, media_b;
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            fscanf(img_original, "%d %d %d %d %d %d %d %d %d %d %d %d", &r1, &g1, &b1, &r2, &g2, &b2, &r3, &g3, &b3, &r4, &g4, &b4);
            media_r = (r1+r2+r3+r4)/4;
            media_g = (g1+g2+g3+g4)/4;
            media_b = (b1+b2+b3+b4)/4;
            fprintf(img_reduzida,"%d %d %d\n", media_r, media_g, media_b);
        }
    }

}

int main(){
    FILE * img_original;
    img_original = fopen("galinhos.ppm", "rt");

    string op;
    cin >> op;
    if (op == "copiar"){
        copiar(img_original);
    } else if (op == "cinza") {
        escala_cinza(img_original);
    } else if (op == "reduzir"){
        reduzir(img_original);
    } else {
        cout << "erro" << endl;
    }
}