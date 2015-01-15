#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
vector<char> g[257];
bool vis[256];
void dfs(char u){
  if(vis[u])return;
  vis[u] = true;
  for(int i = 0; i < g[u].size(); i++)
    dfs(g[u][i]);
}
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    string tmp;
    cin >> tmp;
    char maxi = tmp[0];
    string cad;
    for(char i = 'A'; i <= 'Z'; i++)
      g[i].clear();
    getchar();
    while(getline(cin, cad) && cad.size()){
      char a = cad[0], b = cad[1];
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int ans = 0;
    memset(vis, false, sizeof(vis));
    for(char i = 'A'; i <= maxi; i++)
      if(vis[i] == false){
        dfs(i);
        ans++;
      }
    cout << ans << endl;
    if(cases)
      cout << endl;
  }
  return 0;
}
