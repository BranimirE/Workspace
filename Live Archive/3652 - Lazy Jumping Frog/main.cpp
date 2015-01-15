#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#define MAX (1005)
#define oo (1<<29)

using namespace std;
int rows, cols;
bool water[MAX][MAX];
int xf, yf, xt, yt;
int jump[3][3] = {{0, 2, 5},{2, 3, 6},{5, 6, 7}};
int dist[MAX][MAX];
set<pair<int, pair<int, int> > > q;
bool valid(int i, int j){
  return (i >= 1) && (i <= rows) && (j >= 1) && (j <= cols) && !(water[i][j]);
}
int main(){
  while((cin >> cols >> rows) && !(rows == 0 && cols == 0)){
    cin >> yf >> xf >> yt >> xt;
    memset(water, false, sizeof(water));
    int w;
    cin >> w;
    while(w--){
      int x1, y1, x2, y2;
      cin >> y1 >> x1 >> y2 >> x2;
      for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
          water[i][j] = true;
    }
    q.clear();
    for(int i = 1; i <= rows; i++)
      fill(dist[i] + 1, dist[i] + cols + 1, oo);
    q.insert(make_pair(0, make_pair(xf, yf)));
    dist[xf][yf] = 0;
    while(q.size()){
      int d = (q.begin())->first;
      int ux = (q.begin())->second.first;
      int uy = (q.begin())->second.second;
      q.erase(q.begin());
      for(int vx = ux - 2; vx <= ux + 2; vx++)
        for(int vy = uy - 2; vy <= uy + 2; vy++)
          if(valid(vx, vy)){
            int weight = jump[abs(ux - vx)][abs(uy - vy)];
            if(d + weight < dist[vx][vy]){
              dist[vx][vy] = d + weight;
              q.insert(make_pair(dist[vx][vy], make_pair(vx, vy)));
            }
          }
    }
    if(dist[xt][yt] != oo)
      cout << dist[xt][yt] << endl;
    else
      cout << "impossible" << endl;
  }
  return 0;
}
