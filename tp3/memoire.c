#include <stdio.h>
#include <time.h>
#include <stdlib.h>


float moyenne_v1(int **mat, int n) {
    int i, j, total = 0;
    clock_t debut = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += mat[i][j];
        }
    }
    clock_t fin = clock();
    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("%lf \n", temps);
    return (float) total / (n * n);
}

float moyenne_v2(int **mat, int n) {
    int i, j, total = 0;
    clock_t debut = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += mat[j][i];
        }
    }
    clock_t fin = clock();
    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("%lf \n", temps);   
    return (float) total / (n * n);
}


int main(){
    int tab[2][2];

    clock_t debut = clock();
    printf("# tab V1\n\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%p\n",&tab[i][j]);
    }

    clock_t fin = clock();
    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("%lf \n", temps);

    int **tab2 = malloc(sizeof(int *)*2);
    for(int i=0;i<2;i++){
        tab2[i] = malloc(sizeof(int)*2);
    }

    clock_t debut2 = clock();
    printf("\n# tab V2\n\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%p\n",&tab2[i][j]);
    }

    clock_t fin2 = clock();
    double temps2 = (double)(fin2 - debut2) / CLOCKS_PER_SEC;
    printf("%lf \n", temps2);
    printf("\n");
    moyenne_v1(tab2, 2);
    moyenne_v2(tab2, 2);

    return 0;
}