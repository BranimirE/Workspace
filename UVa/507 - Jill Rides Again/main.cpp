#include <cstdio>
#define MAX 20010
using namespace std;
int v[MAX];
int main()
{
    int t, n, num, sum, ans, a ,b, x, y;
    scanf("%d", &t);
    for(int ruta = 1; ruta <= t; ruta++){
        scanf("%d", &n);
        n--;
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        x = y = a = b = sum = 0;
        ans = -(1<<29);
        for(int i = 0, b = 0; i < n; i++){
            sum += v[i];
            if(sum > ans){
                ans = sum;
                x = a;
                y = b;
            }else if(sum == ans && (b - a) > (y - x))
                x = a, y = b;
            if(sum < 0){
                sum = 0;
                a = i + 1;
            }
            b++;
        }
        if(ans >= 0)
            printf("The nicest part of route %d is between stops %d and %d\n", ruta, x + 1, y + 2);
        else
            printf("Route %d has no nice parts\n", ruta);

    }
    return 0;
}
