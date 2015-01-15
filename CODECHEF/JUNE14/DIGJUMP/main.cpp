#include <bits/stdc++.h>

using namespace std;
vector<int> pos[10];
int n;
char cad[100010];
int dist[100010];
bool allinqueue[10];
int main(){
  scanf("%s", cad);
  n = strlen(cad);
  for(int i = 0; i < n; i++)
    pos[cad[i] - '0'].push_back(i);
  queue<int> q;
  memset(dist, -1, sizeof(dist));
  memset(allinqueue, false, sizeof(allinqueue));
  q.push(0);
  dist[0] = 0;
  bool found = false;
  while(!q.empty() && !found){
    int u = q.front(); 
    q.pop();
    int current = cad[u] - '0';
    if(allinqueue[current] == false){
      vector<int> &ady = pos[current];
      for(int i = 0; i < ady.size(); i++){
        int v = ady[i];
        if(dist[v] == -1){
          dist[v] = dist[u] + 1;
          if(v == (n - 1)){
            found = true;
            break;
          }
          q.push(v);
        }
      }
      allinqueue[current] = true;
    }
    if((u - 1) >= 0 && dist[u - 1] == -1){
      dist[u - 1] = dist[u] + 1;
      q.push(u - 1);
    }
    if((u + 1) < n && dist[u + 1] == -1){
      dist[u + 1] = dist[u] + 1;
      if((u + 1) == (n - 1))
        found = true;
      q.push(u + 1);
    }
  }
  cout << dist[n - 1] << endl;
  return 0;
}
