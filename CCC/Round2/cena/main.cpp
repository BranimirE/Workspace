#include <bits/stdc++.h>
using namespace std;
int n, m;
bool conoce[11][11];
bool isValid(string p){
  for(int i = 0; i < n; i++){
    int a = p[((i - 1) + n) % n ] - '0';
    int b = p[i] - '0';
    int c = p[(i + 1) % n] - '0';
    if(conoce[a][b] == false || conoce[b][c] == false)
      return false;
  }
  return true;
}
int solve(string cad){
  int ans = INT_MAX;
  queue<string> q;
  map<string, int> dist;
  dist[cad] = 0;
  q.push(cad);
  while(!q.empty()){
    string u = q.front();
    q.pop();
    int distu = dist[u];
    if(isValid(u))
      return distu;

    for(int i = 0; i < n; i++){
      string v = u;
      swap(v[i], v[(i - 1 + n) % n]);
      if(!dist.count(v)){
        dist[v] = distu + 1;
        q.push(v);
      }
      v = u;
      swap(v[i], v[(i + 1 + n) % n]);
      if(!dist.count(v)){
        dist[v] = distu + 1;
        q.push(v);
      }
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    cin >> n >> m;
    memset(conoce, false, sizeof(conoce));
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      u--, v--;
      conoce[u][v] = conoce[v][u] = true;
    }
    if(n == 1){
      printf("Caso #%d: 0\n", caso);
      continue;
    }
    string act = "";
    for(int i = 0; i < n; i++)
      act.push_back('0' + i);
    int ans = solve(act);

    if(ans != INT_MAX)
      printf("Caso #%d: %d\n", caso, ans);
    else
      printf("Caso #%d: Imposible\n", caso);
    cerr << "Case : " << caso << " -> ended!" << endl;
  }
  return 0;
}
