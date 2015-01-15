#include <cstdio>
#include <iostream>
#include <vector>

#define MAXN 100010
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long int Number;
Number  n, k, maxdist;
vector<Number> v[MAXN];
vector<pair<Number,Number> > ans;
bool solve(){
  if(v[0].size() != 1)
    return false;
  for(Number i = 0; i < maxdist; i++){
    if(v[i + 1].size() > v[i].size() * k)
      return false;
    for(Number j = 0; j < v[i].size(); j++){
      for(Number c = j * k; c < min(v[i + 1].size(), j * k + k); c++)
        ans.push_back(make_pair(v[i][j], v[i + 1][c]));
    }
    if(i == 0) k--;
  }
  return true;
}
int main(){
  cin >> n >> k;
  maxdist = 0;
  for(int i = 1; i <= n; i++){
    Number tmp;
    cin >> tmp;
    v[tmp].push_back(i);
    maxdist = max(maxdist, tmp);
  }
  if(solve()){
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }else
    puts("-1");
    
  return 0;
}
