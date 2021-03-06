#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[10005], b[10005], n;
vector<pair<int,int> > ans;
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b, b + n);
  for(int i = 0; i < n; i++){
    if(a[i] == b[i]) continue;
    vector<int> tmp;
    for(int j = i; j < n; j++)
      if(a[j] == b[i])
        tmp.push_back(j);
    int mid = (i + tmp[tmp.size() - 1]) / 2;
    int pos = lower_bound(tmp.begin(), tmp.end(), mid) - tmp.begin();
    int l, r;
    if(pos >= tmp.size()/2)
      r = tmp[tmp.size() - 1];
    else
      r = tmp[0];
    l = i;
    if(l != r)	ans.push_back(make_pair(l + 1, r + 1));
    while(l < r){
      swap(a[l], a[r]);
      l++;
      r--;
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
