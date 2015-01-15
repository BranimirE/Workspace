#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
long long int ans, acu, tmp;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = acu = 0;
    while (n--) {
      scanf("%lld", &tmp);
      acu += tmp;
      ans += abs(acu);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
