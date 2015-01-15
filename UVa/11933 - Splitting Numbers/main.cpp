#include <cstdio>

using namespace std;
long long int n,a,b;
bool turno;
int main()
{
    while(scanf("%lld", &n)==1, n){
        a = b = 0;
        turno = true;
        for(int i = 0; i <= 32; i++)
            if(n&(1LL<<i)){
                    if(turno)
                        a |= (1LL<<i);
                    else
                        b |= (1LL<<i);
                    turno = !turno;
            }

        printf("%lld %lld\n",a,b);
    }
    return 0;
}
