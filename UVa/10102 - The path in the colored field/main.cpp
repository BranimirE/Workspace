#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string g;
vector<pair<int,int> > unos, tres;
int n;
int main()
{
    while(scanf("%d", &n) == 1){
        unos.clear();
        tres.clear();
        for(int i = 0; i < n; i++){
            cin >> g;
            for(int j = 0; j < n; j++){
                if(g[j] == '1')
                    unos.push_back(make_pair(i, j));
                if(g[j] == '3')
                    tres.push_back(make_pair(i, j));
            }
        }
        int ans = 1;
        for(int i = 0; i < unos.size(); i++){
            int tmp = 2 * n - 1;
            for(int j = 0; j < tres.size(); j++)
                tmp = min(tmp ,abs(unos[i].first - tres[j].first) + abs(unos[i].second - tres[j].second));
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
