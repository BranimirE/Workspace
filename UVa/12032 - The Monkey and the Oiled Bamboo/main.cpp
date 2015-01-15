#include <iostream>

using namespace std;
#define MAX 100010
int v[MAX], n;
bool simula(int k) {
    //return true si hay que reducir   r = k
    //return false si hay que agrandar l = k + 1
    for(int i = 1; i <= n; i++) {
        int res = v[i] - v[i-1];
        if(res == k)
            k--;
        else if(k < res) return false;
    }
    return true;
}
int main() {
    int t, ms, cnt, res;
    cin >> t;
    v[0] = 0;
    for(int caso = 1; caso <= t; caso++){
        cin >> n;
        ms = 0;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            ms = max(ms, v[i] - v[i-1]);
        }
        int l = 1, r = ms + 1;
        while(l < r){
            int k = (l + r) / 2;
            if(simula(k))
                r = k;
            else
                l = k + 1;
        }
        cout << "Case " << caso << ": " << l << endl;
    }
    return 0;
}
