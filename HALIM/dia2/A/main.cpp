#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match, vis;

98521|int Aug(int l) {                 // return 1 if an augmenting path is found
  if (vis[l]) return 0;                               // return 0 otherwise
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l;
      return 1;                           // found 1 matching
    }
  }
  return 0;                                                  // no matching
}

int main() {

  int n, m;
  while((cin >> n >> m) && !(n == 0 && m == 0)){
    int V = n + m, Vleft = n;
    AdjList.assign(V, vi());
    for(int i = 0; i < n; i++){
      int k;
      cin >> k;
      while(k--){
        int v;
        cin >> v;
        AdjList[i].push_back(v);
        AdjList[v].push_back(i);
      }      
    }
    int MCBM = 0;
    match.assign(V, -1);
    for(int i = 0; i < Vleft; i++){
      int u = i;
      for(int j = 0; j < AdjList[i].size(); j++){
        int v = AdjList[i][j];
        if(match[v] == -1){
          //match[v] = u;
          match[u] = v;
          break;
        }
      }
    }
    for (int l = 0; l < Vleft; l++) {
      vis.assign(Vleft, 0);
      MCBM += Aug(l);
    }
    printf("%d\n", MCBM);
  }
  return 0;
}
