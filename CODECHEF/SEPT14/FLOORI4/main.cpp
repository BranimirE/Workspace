#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int Number;
Number bruteforce(Number n) {
  Number ans = 0;
  for (Number i = 1; i <= n; i++)
    ans += (i * i * i * i * (n / i));
  return ans;
}
vector<Number> divisores(Number n) {
  vector<Number> ans;
  for(Number i = 1; i <= n; i++)
    if (n % i == 0)
      ans.pb(i);
  return ans;
}
Number solve(Number n) {
  Number ans = 0;
  for (Number i = 1; i <= n; i++)
    ans += (n * i * i * i);
  for (Number i = 1; i <= n; i++)
    ans += (i * i * i * i);
  vector<Number> d  = divisores(n);
  forn (i, sz(d)) {
    Number div = d[i];
    ans -= (div * div * div * div);
  }
  return ans;
}
Number sigma4(Number n) {
  vector<Number> d = divisores(n);
  Number ans = 0;
  for (int i = 0; i < sz(d); i++) {
    Number dd = d[i];
    ans += (dd * dd *dd *dd);
  }
  return ans;
}
Number solvewithsigmas(Number n) {
  Number ans = 0;
  for(int i = 1; i <= n; i++)
    ans += sigma4(i);
  return ans;
}
Number withoutfloor(Number n) {
  Number ans = 0;
  for(Number i = 1; i <= n; i++)
    ans += (n * i * i * i);
  return ans;
}
int main() {
  /*  Number n ;
  char a[100] = "bruteforce";
  char b[100] = "solve";
  while(cin >> n) {
    printf("%12s %12s\n", a, b);
    printf("%12lld %12lld\n", bruteforce(n), solve(n));
  }
  */
  for (int i = 3;; i++) {
    cout << bruteforce(i) % 30 << endl;
    if (bruteforce(i-1) == 1 && bruteforce(i) == 18)
      break;
  }
    
  return 0;
}
