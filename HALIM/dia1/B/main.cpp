#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 200005
using namespace std;
struct UnionFind{
  int p[MAX], r[MAX], setSize[MAX];
  int n, numSets;
  UnionFind(int _N){
    reset(_N);
  }
  void reset(int N){
    n = N;
    numSets = n;
    for(int i = 0; i <= n; i++){
      p[i] = i;
      r[i] = 0;
      setSize[i] = 1;
    }
  }
  int Find(int i){return (p[i] == i)?i:(p[i] = Find(p[i]));}
  bool sameComponent(int i, int j){return Find(i) == Find(j);}
  void Union(int i, int j){
    if(!sameComponent(i, j)){
      numSets--;
      int x = Find(i), y = Find(j);
      if(r[x] > r[y]){
        p[y] = x;
        setSize[x] += setSize[y];
      } else                   {
        p[x] = y;
        setSize[y] += setSize[x];
        if (r[x] == r[y]) r[y]++;
      }
    }
  }
  int numDisjointSets(){
    return numSets;
  }
  int sizeOfSet(int i){
    return setSize[Find(i)];
  }
};
vector<int> g[MAX], g2[MAX];
bool mark[MAX];
vector<int> bomba;
int main(){
  int cases;
  scanf("%d", &cases);
  int n, m;
  while(cases--){
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++){
      g[i].clear();
    }
    while(m--){
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    scanf("%d", &m);
    bomba.clear();
    memset(mark, false, sizeof(mark));
    for(int i = 0; i < m; i++){
      int bmb;
      scanf("%d", &bmb);
      bomba.push_back(bmb);
      mark[bmb] = true;
    }
    UnionFind uf(n);
    for(int i = 0; i < n; i++)
      if(mark[i] == false)
        for(int j = 0; j < g[i].size(); j++)
          if(mark[g[i][j]] == false)
            uf.Union(i, g[i][j]);
    
    vector<int> ans;
    ans.push_back(uf.numDisjointSets() - m);
    
    for(int i = bomba.size() - 1; i >= 0; i--){
      int bmb = bomba[i];
      if(mark[bmb] == true){
        m--;
        mark[bmb] = false;
        for(int j = 0; j < g[bmb].size(); j++)
          if(mark[g[bmb][j]] == false)
            uf.Union(bmb, g[bmb][j]);
      }
      ans.push_back(uf.numDisjointSets() - m);
    }
    for(int i = ans.size() - 1; i >= 0; i--)
      printf("%d\n", ans[i]);
    if(cases)puts("");
  }
  return 0;
}
