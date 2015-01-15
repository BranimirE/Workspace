#include <bits/stdc++.h>
#define MAX 123456
using namespace std;
int n, maxdist;
pair<int,  int> v[MAX];
int mark[MAX];
int main(){
  int p;
  scanf("%d%d%d", &n, &maxdist, &p);
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i].first);
    v[i].second = i + 1;
  }
  sort(v, v + n);
  int group = 0;
  memset(mark, -1, sizeof(mark));
  mark[v[0].second] = group;
  for(int i = 1; i < n; i++){
    int dist = v[i].first - v[i - 1].first;
    if(dist > maxdist)
      group++;
    mark[v[i].second] = group;
  }
  while(p--){
    int u, v;
    scanf("%d%d", &u, &v);
    printf(mark[u] == mark[v]?"Yes\n":"No\n");
  }
  return 0;
}
