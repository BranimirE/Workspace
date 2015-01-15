#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
#define MAX 25
#define oo (1<<28)
vector<int> g[100];
int dist[21];
int main(){
  int v;
  int testset = 1;
  while(cin >> v){

    for(int pos = 1; pos <= 19; pos++){
      if(pos != 1) cin >> v;
      while(v--){
        int ady;
        cin >> ady;
        g[pos].push_back(ady);
        g[ady].push_back(pos);
      } 
    }
    int querys;
    cin >> querys;
    printf("Test Set #%d\n", testset);
    testset++;
    while(querys--){
      int a, b;
      cin >> a >> b;
      queue<int> q;
      for(int i = 1; i <= 20; i++)
        dist[i] = oo;
      q.push(a);
      dist[a] = 0;
      while(q.size()){
        int act = q.front();
        if(act == b) break;
        q.pop();
        for(int i = 0; i < g[act].size(); i++){
          int ady = g[act][i];
          if(dist[ady] == oo){
            dist[ady] = dist[act] + 1;
            q.push(ady);
          }
        }
      }
      printf("%2d to %2d:%2d\n", a, b, dist[b]);
    }
    puts("");
    for(int i = 1; i <= 20; i++)
      g[i].clear();
  }
  return 0;
}
