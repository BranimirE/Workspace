#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int Number;
Number v[123];
int main() {
  int t, n;
  scanf("%d", &t);
  
  while (t--) {
    Number sum = 0, maxi = 0;
    scanf("%d %lld", &n, &sum);
    forn (i, n) {
      scanf("%lld", &v[i]);
      sum += v[i];
      maxi = max(maxi, v[i]);
    }
    printf(((sum % n) == 0 && (sum / n) >= maxi)?"Yes\n":"No\n");
  }
  return 0;
}
