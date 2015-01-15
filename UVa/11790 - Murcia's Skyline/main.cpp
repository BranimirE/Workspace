#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> v;
vector<long long int> ancho;
vector<long long int> dp;
int t, n;
long long int lis(int i) {
  if(i == 0)return ancho[0];
  long long int ans = dp[i];
  if(ans != -1LL) return ans;
  ans = ancho[i];
  for(int j = 0; j < i; j++)
    if(v[j] < v[i])
      ans = max(ans, ancho[i] + lis(j));
  return dp[i] = ans;
}
int solve() {
  long long int ans = 0;
  for(int i = n-1; i >= 0; i--)
    ans = max(ans, lis(i));
  return ans;
}
void impr(vector<long long int> _v) {
  for(int i = 0; i < _v.size(); i++) {
    if(i)printf(" ");
    printf("%lld", _v[i]);
  }
  puts("");
}
int main() {
  scanf("%d", &t);
  for(int caso = 1; caso <= t; caso++) {
    scanf("%d", &n);
    (vector<long long int>(n)).swap(v);
    (vector<long long int>(n)).swap(ancho);
    (vector<long long int>(n, -1LL)).swap(dp);
    for(int i = 0; i < n; i++)
      scanf("%lld", &v[i]);
    for(int i = 0; i < n; i++)
      scanf("%lld", &ancho[i]);
    long long int x = solve();
    reverse(v.begin(), v.end());
    reverse(ancho.begin(), ancho.end());
    (vector<long long int>(n, -1LL)).swap(dp);
    long long int y = solve();
    if(x >= y)
      printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",caso, x, y);
    else
      printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",caso, y, x);
  }
  return 0;
}
