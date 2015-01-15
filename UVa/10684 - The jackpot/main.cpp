#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
long long int maxrangesum(vector<int> &v) {
  int n = v.size();
  long long int sum = 0, ans = -(1LL<<60);//la maxima suma podria ser negativa
  for(int i = 0; i < n; i++) {
    sum += v[i];
    ans = max(ans, sum);
    if(sum < 0) sum = 0;
  }
  return ans;
}
int main() {
  int n, sum , ans, num;
  while(scanf("%d", &n), n) {
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    ans = maxrangesum(v);
    if(ans > 0)
      printf("The maximum winning streak is %d.\n", ans);
    else
      printf("Losing streak.\n");
  }
  return 0;
}
