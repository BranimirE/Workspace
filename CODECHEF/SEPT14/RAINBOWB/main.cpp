#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define MAXN 1000010
#define MAXC 500000

int C[MAXC][6];
int main() {
  int n;
  scanf("%d", &n);
  int lim = n >> 1;
  for(int N = 0; N < lim; N++) {
    int right = min(N, 5);
    for (int K = 0; K <= right; K++) {
      if (K == 0 || N == K) {C[N][K] = 1; continue;}
      C[N][K] = C[N - 1][K - 1] + C[N - 1][K];
      if (C[N][K] >= MOD) C[N][K] -= MOD;
    }
  }
  int ans = 0;
  for(int a7 = 1; (n - a7) >= 12; a7++) {
    int rem = n - a7;
    if (!(rem & 1)) {
      rem >>= 1;
      ans += C[rem - 1][5];
      if (ans >= MOD)
	ans -= MOD;
    }
  }
  printf("%d\n", ans);
  return 0;
}
