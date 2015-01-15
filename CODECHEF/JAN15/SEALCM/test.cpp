#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

int main() {
    //    forn (casos, 10)
        forn (j, 1000)//Rango L - R
            for (int fila = 1; fila <= 5000000; fila++) {// Recorro N
            	for (int col = 1; col <= (1<<4); col++) {//Todas las mascaras
            	    int a = fila % col;
            	}
            }
    cout << "termino algo" << endl;
    return 0;
}
