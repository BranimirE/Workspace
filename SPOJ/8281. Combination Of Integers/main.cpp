#include <iostream>
#include <cstring>

#define MAXN  1000000
using namespace std;
int n, men;
int v[35];
bool dp[MAXN];
int solve() {
    memset(dp, false, sizeof(dp));
    int grup = 0;
    int cant = men - 1;
    dp[0] = true;
    for(int i = men; i < MAXN; i++) {
        for(int j = 0; j < n; j++)
            if(i>= v[j] && dp[i-v[j]]) {
                dp[i] = true;
                grup++;
                if(grup == men)// hay un grupo de numeros que se pueden hacer que es igual al menor numero,
                    // entonces todos en adelante se pueden hacer sumandole el menor a cada uno de ese grupo
                    return cant;// los numeros hacia atras no se pueden hacer
                break;
            }
        if(dp[i]==false) {
            //cout << i << " no se puede sumar" << endl;
            cant++;// numero no se puede hacer
            grup = 0;
        }
    }
    return -1;
}
int main() {
    int casos;
    cin >> casos;
    while(casos--) {
        cin >> n;
        men = MAXN;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            men = min(men, v[i]);
        }
        int ans = solve();
        if(ans != -1)
            cout << ans << endl;
        else
            cout << "Infinite" << endl;
    }
    return 0;
}
