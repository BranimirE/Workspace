#include <cstdio>

using namespace std;

int main()
{
    int t, x, y, z, a, b, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &a, &b, &c);
        bool enc = false;
        for(x = -22; x <= 22 && !enc ; x++)if(x*x <= c)
            for( y = -100; y <= 100 && !enc; y++)if(y != x && x*x+y*y<=c)
                for( z = -100; z <= 100 && !enc; z++)
                    if(z != y && z != x && x+y+z==a && x*y*z == b && x*x+y*y+z*z==c)
                        printf("%d %d %d\n", x, y, z), enc = true;
        if(!enc)
            puts("No solution.");
    }
    return 0;
}
