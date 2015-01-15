#include <cstdio>
#include <fstream>
#include <vector>
#include <stack>
#include <cstring>

#define MAX 102
using namespace std;
vector<int> g[MAX];
bool v[MAX];
int n, m;
vector<int> tp;
void dfs(int i) {
  v[i] = true;
  for(int j = 0; j < g[i].size(); j++)
    if(!v[g[i][j]])
      dfs(g[i][j]);
  tp.push_back(i);
}
int main() {
  freopen("in", "r", stdin);
  while(scanf("%d%d", &n, &m) and !(!n and !m)) {
    for(int i = 1; i <= n; i++)g[i].clear();
    int a, b;
    memset(v, 0, sizeof(v));
    while(m--) {
      scanf("%d%d", &a,&b);
      g[a].push_back(b);
    }

    tp.clear();
    memset(v, 0, sizeof(v));

    for(int i = 1; i <= n; i++)
      if(!v[i])
        dfs(i);

    for(int i = tp.size()-1; i >= 0 ; i--) {
      printf("%d", tp[i]);
      if(i)printf(" ");
    }
    puts("");
  }
  return 0;
}
