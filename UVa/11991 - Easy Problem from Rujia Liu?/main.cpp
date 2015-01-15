#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m,tmp,k;
    while(cin >> n >> m) {
        vector<vector<int> > g(1000002, vector<int>());
        for(int i = 1; i <= n; i++) {
            cin >> tmp;
            g[tmp].push_back(i);
        }
        while(m--) {
            cin >> k >> n;
            if(!g[n].empty() &&  g[n].size() >= k)
                cout << g[n][k-1] << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
/*
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2

*/
