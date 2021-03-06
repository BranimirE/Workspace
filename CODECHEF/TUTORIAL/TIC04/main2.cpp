#include <stdio.h>
int b[8][8];
int n;
 
bool safe(int x, int y) {
    int i = x, j = y;
    while(--i >= 0)
        if(b[y][i]) return false;
    i = y;
    while(--i >= 0)
        if(b[i][x]) return false;
    i = x;
    while(--i >= 0 && --j >= 0)
        if(b[j][i]) return false;
    i = x;
    j = y;
    while(++i < n && --j >= 0)
        if(b[j][i]) return false;
    return true;
}
 
int find_solution(int x, int y) {
    if(safe(x,y)) {
        b[y][x] = 1;
        if(y < n-1)
            for(int i = 0; i < n; ++i)
                find_solution(i, y + 1);
        else
            for(int j = 0; j < n; printf(j == n-1 ? "\n\n" : "\n"), ++j)
                for(int i = 0; i < n; printf(b[j][i] ? "Q\t" : "-\t"), ++i);
        b[y][x] = 0;
    }
}
 
int main() {
    while(scanf("%d", &n) > 0)
        if(n < 4)
            if(n == 1)
                printf("Q\n\n");
            else
                printf("Not Possible\n");
        else
            for(int x = 0; x < n; ++x)
                find_solution(x, 0);
    return 0;
}
