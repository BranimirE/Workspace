#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long int Number;

int n, m, p;
vector<int> a[100001];
int main(){
  scanf("%d%d%d", &n, &m, &p);
  while(p--){
    int i, j;
    scanf("%d%d", &i, &j);
    a[i].push_back(j);
  }
  for(int i = 1; i <= n; i++){
    sort(a[i].begin(), a[i].end());
    vector<pair<int, int> > tmp;
    int j = 0;
    while(j < a[i].size()){
      int k = j + 1;
      while(k < a[i].size() && a[i][k] == a[i][j])
        k++;
      tmp.push_back(make_pair(a[i][j], a[i][j] + k - j));
      j = k;
    }
    Number ans = m - 1;
    if(tmp.size()){
      if(tmp[0].first > 1){
        ans--;
        int x = tmp[0].first - 1, y = tmp[0].second;
        ans += Number(y - x);
      }
      for(int j = 1; j < tmp.size(); j++){
        if(tmp[j].first - 1 == tmp[j - 1].first){
          int x = tmp[j - 1].second, y = tmp[j].second;
          if(x <= y){
            ans--;
            ans += Number(y - x);
          }
          else{
            ans = -1LL;
            break;
          }
        }else{
          int x = tmp[j - 1].second, y = tmp[j - 1].first + 1;
          if(x <= y){
            ans--;
            ans += Number(y - x);
          }
          else{
            ans = -1LL;
            break;
          }
          x = tmp[j].first - 1, y = tmp[j].second;
          if(x <= y){
            ans--;
            ans += Number(y - x);
          }
          else{
            ans = -1LL;
            break;
          }
        }
      }

      if(ans != -1 && tmp[tmp.size() - 1].first < m){
        int x = tmp[tmp.size() - 1].second, y = tmp[tmp.size() - 1].first + 1;
        if(x <= y){
          ans--;
          ans += Number(y - x);
        }
        else{
          ans = -1LL;
        }
      }
      
    }
    printf("%lld\n", ans);
  }
  return 0;
}
