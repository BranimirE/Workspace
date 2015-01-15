#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
//int lim[5] = {0, 9, 99, 32, 3};
/*
vector<int> ans[5];
void generar(int tam) {
    tam /= 2;
    int sup = pow(10, tam);
    for(int a = 0; a < sup; a++)
        for(int b = 0; b < sup; b++)
            if(a*sup+b == pow(a+b,2))
                ans[tam].push_back(a*sup+b);
}
    generar(2), generar(4), generar(6), generar(8);
    puts("termino de generar");
    printf("{");
    for(int i = 0; i <= 8; i++) {
        if(i)
            printf(",");

        printf("{");
        if(i%2 == 0)
            for(int j = 0; j < ans[i/2].size(); j++) {
                if(j)printf(",");
                printf("%d", ans[i/2][j]);
            }
        printf("}");
    }
    printf("}\n{");

    for(int i = 0; i <= 8; i++){
        if(i)
            printf(",");
        if(i%2 == 0)
            printf("%d", ans[i/2].size());
        else
            printf("0");
    }
    printf("}");
*/
int ans[10][10] = {{},{},{0,1,81},{},{0,1,2025,3025,9801},{},{0,1,88209,494209,998001},{},{0,1,4941729,7441984,24502500,25502500,52881984,60481729,99980001}};
int siz[10] = {0,0,3,0,5,0,5,0,9};
int main() {
    int n, l;
    while(scanf("%d", &n) == 1)
        for(int i = 0; i < siz[n]; i++)
            printf("%0*d\n",n, ans[n][i]);

    return 0;
}
