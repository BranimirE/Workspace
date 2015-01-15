#include <cstdio>
#include <vector>
#include <cstring>

#define MAX 105
using namespace std;
int n, ar, a ,b;
vector<vector<int> > g;
int color[MAX];
int ans;
vector<int> bck;
void solve(int nodo, int blacks) {
    if(nodo == n + 1) {
        if(blacks > ans) {
            ans = blacks;
            bck = vector<int>(color, color + n + 1);
        }
        return;
    }
    bool hn = false;
    for(int i = 0; i < g[nodo].size() && !hn; i++)
        hn = (color[g[nodo][i]] == 1);
    if(!hn) {
        color[nodo] = 1;
        solve(nodo + 1, blacks + 1);
        color[nodo] = -1;
    }
    color[nodo] = 0;
    solve(nodo + 1, blacks);
    color[nodo] = -1;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &ar);
        vector<vector<int> >(n + 1, vector<int>()).swap(g);
        while(ar--) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(color, -1 , sizeof(color));
        ans = 0;
        solve(1,0);
        printf("%d\n", ans);
        bool space = false;
        for(int i = 1; i <= n; i++)
            if(bck[i] == 1) {
                if(space)printf(" ");
                space = true;
                printf("%d", i);
            }
        puts("");
    }
    return 0;
}
