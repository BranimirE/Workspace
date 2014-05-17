#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX 105

struct island{
  double x, y, r;
  island(double _x = 0, double _y = 0, double _r = 0){
    x = _x;
    y = _y;
    r = _r;
  }
};
island v[MAX];
int n, querys;
double dist[MAX][MAX];
double distan(int i, int j){
  double ans = hypot(v[i].x - v[j].x, v[i].y - v[j].y);
  if(ans > (v[i].r + v[j].r))
    ans -= (v[i].r + v[j].r);
  else
    ans = 0;
  return ans;
}
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> v[i].x >> v[i].y >> v[i].r;
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        dist[i][j] = dist[j][i] = distan(i, j);
    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    cin >> querys;
    while(querys--){ 
      int i, j;
      cin >> i >> j;
      printf("%.4lf\n", dist[i][j]);
    }
    if(cases)puts("");
  }
  return 0;
}
