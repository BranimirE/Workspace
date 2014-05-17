#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF (1<<29)
#define MAX 1005
using namespace std;

bool muddy[MAX][MAX];
int dist[MAX][MAX];
bool in_queue[MAX][MAX];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main(){
  int cases;
  cin >> cases;
  int n, k;
  while(cases--){
    cin >> n >> k;
    memset(muddy, false, sizeof(muddy));
    while(k--){
      int i, j;
      cin >> i >> j;
      muddy[i][j] = true;
    }
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dist[i][j] = INF;
    dist[1][1] = muddy[1][1];
    queue<pair<int,int> > q;
    pair<int, int> ini(1, 1);
    q.push(ini);
    memset(in_queue, false, sizeof(in_queue));
    in_queue[1][1] = true;
    
    while(!q.empty()){
      pair<int,int> u = q.front(); q.pop(); in_queue[u.first][u.second] = false;
      for(int i = 0; i < 4; i++){
        int x = u.first + dx[i], y = u.second + dy[i];
        if(x >= 1 && x <= n && y >= 1 && y <= n){
          int weight = muddy[x][y];
          if(dist[u.first][u.second] + weight < dist[x][y]){
            dist[x][y] = dist[u.first][u.second] + weight;
            if(!in_queue[x][y]){
              q.push(make_pair(x, y));
              in_queue[x][y] = true;
            }
          }
        }
      }
    }
    cout << dist[n][n] << endl;
  }
  return 0;
}
