#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

long long int m[3][3];
int f(char c){
    if(c == 'B')
        return 0;
    else if ( c == 'G')
        return 1;
    return 2;
}
void solve(){
    string t = "BCG", ans;
    long long int costo = 1LL<<50;
    int cant = 6;
    sort(t.begin(), t.end());
    while(cant--){
        long long int tmp = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(j != f(t[i]))
                    tmp += m[i][j];

        if(tmp < costo){
            costo = tmp;
            ans = t;
        }
        next_permutation(t.begin(), t.end());
    }
    printf("%s %lld\n", ans.c_str(), costo);
}
int main()
{
    while(true){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(scanf("%lld", &m[i][j]) == EOF)return 0;
        solve();
    }
    return 0;
}
