#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
char line[100];
int now = 0;
vector<pair<int, int> > mesa;
int tam;
int dp[100010];
bool cmp(pair<int, int> a, pair<int, int> b){return a.first < b.first;}
int main() {
  int t, ans;
  int a, b, p;
  int n, k;
  map<int, int> id;
  int m = 0;
  scanf("%d", &t);
  vector<vector<pair<int,int> > > elem;
  while(t--){
    scanf("%d %d", &n, &k);
    id.clear();
    elem.clear();
    m = 0; // numero de mesas
    while(n--){
      scanf("%d %d %d", &a, &b, &p);
      if(id.find(p) == id.end()){
        id[p] = m++;
        elem.push_back(vector<pair<int,int> >());
      }
      elem[id[p]].push_back(make_pair(a, b));
    }
    ans = 0;
    for(int i = 0; i < m; i++){
      mesa = elem[i];
      tam = mesa.size();
      sort(mesa.begin(), mesa.end());
      dp[tam] = 0;
      for(int i = tam - 1; i >= 0; i--){
        int sig = lower_bound(mesa.begin(), mesa.end(), make_pair(mesa[i].second, 0) , cmp) - mesa.begin();
        dp[i] = max(dp[i + 1], 1 + dp[sig]);
      }
      ans += dp[0];
    }
    printf("%d\n", ans);
  }
  return 0;
}
