#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int solve(int a, int b){
  vector<int> p;
  while(a){
    p.push_back(a);
    a >>= 1;
  }
  reverse(p.begin(), p.end());
  int ans = 0;
  while(!binary_search(p.begin(), p.end(), b)){
    b >>= 1;
    ans++;
  }
  return ans + p.size() - (lower_bound(p.begin(), p.end(), b)-p.begin()) - 1;
}
int main(){
  int t, a, b;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &a, &b);
    printf("%d\n", solve(a, b));
  }
  return 0;
}
