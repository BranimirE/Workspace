#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef long long int Number;
vector<int> digits(Number nn) {
  vector<int> ans;
  ans.pb(0);
  if (nn == 0)
    ans.pb(0);
  else
    while (nn) {
      ans.pb(nn % 10);
      nn /= 10;
    }
  return ans;
}

vector<int> num;
Number dp[20][200][2];

Number solve(int pos, Number sum, bool igual) {
  if (pos == 0)
    return (sum == 0);
  if (sum < 0) return 0;
  assert(pos > 0);
  assert(sum < 200 );
  Number &ans = dp[pos][sum][igual];
  if (ans != -1LL) return ans;
  ans = 0;
  int lim = igual?num[pos]:9;
  for (int dig = 0; dig <= lim; dig++)
    if (igual) ans += solve(pos - 1, sum - dig, dig == num[pos]);
    else       ans += solve(pos - 1, sum - dig, false);
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  Number A, B, X, ans, countA, countB, countTotal, a, b, tmp;
  vector<int> numA, numB;
  while (t--) {
    scanf("%lld %lld %lld", &A, &B, &X);
    if (A > B) swap(A, B);
    numA = digits(A - 1), a = numA.size() - 1;
    numB = digits(B)    , b = numB.size() - 1;
    ans = 0;
    Number sumdig = 1;
    Number maxsum = max(a, b) * 9LL;
    while (X >= sumdig && sumdig <= maxsum) {
      num.swap(numA);
      countA = 0;
      memset(dp, -1, sizeof(dp));
      for (int dig = 0; dig <= num[a]; dig++)
	countA += solve(a - 1, sumdig - dig, dig == num[a]);
      num.swap(numA);

      num.swap(numB);
      countB = 0;
      memset(dp, -1, sizeof(dp));
      for (int dig = 0; dig <= num[b]; dig++)
	countB += solve(b - 1, sumdig - dig, dig == num[b]);
      num.swap(numB);

      countTotal = countB - countA;
      tmp = min(countTotal, X / sumdig);

      ans += tmp;
      X -= (sumdig * tmp);

      sumdig++;
    }
    cout << ans << endl;
  }
  return 0;
}
