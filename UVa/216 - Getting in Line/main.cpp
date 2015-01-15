#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

#define MAX 10
using namespace std;
int n;
double dist[MAX][MAX];
pair<int, int> v[MAX];
int p[MAX];
int main() {
  freopen("in", "r", stdin);
  int red = 1;
  while(scanf("%d", &n), n) {
    printf("**********************************************************\nNetwork #%d\n", red++);
    for(int i = 0; i < n; i++)
      scanf("%d%d", &v[i].first, &v[i].second);

    for(int i = 0; i < n; i++) {
      p[i] = i;
      dist[i][i] = 0;
      for(int j = i + 1; j < n; j++)
        dist[i][j] = dist[j][i] = hypot(v[i].first-v[j].first, v[i].second-v[j].second) + 16.0;
    }
    vector<int> ans(p, p+n);
    double sol = 1<<30;
    do {
      double tmp = 0;
      for(int i = 1; i < n; i++)
        tmp += dist[p[i-1]][p[i]];
      if(tmp < sol){
        sol = tmp;
        ans = vector<int>(p, p+n);
      }
    } while(next_permutation(p, p+n));
    for(int i = 1; i < n; i++)
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", v[ans[i-1]].first, v[ans[i-1]].second, v[ans[i]].first, v[ans[i]].second, dist[ans[i-1]][ans[i]]);
    printf("Number of feet of cable required is %.2lf.\n", sol);
  }
  return 0;
}
