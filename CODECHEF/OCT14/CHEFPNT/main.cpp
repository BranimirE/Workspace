#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

vector<pair<int,int> > solve(const vector<vector<bool> > &t, int n, int m) {
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (t[i][j]) {
	ans.pb(mp(i, j));
	while (j <= m && t[i][j]) j++;
      }
  return ans;
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<vector<bool> > t(n + 1, vector<bool>(m + 1, true)), t2(m + 1, vector<bool>(n + 1, true));
  for (int _ = 0; _ < k; _++) {
    int i, j;
    scanf("%d %d", &i, &j);
    t[i][j] = false;
    t2[j][i] = false;
  }
  vector<pair<int,int> > A = solve(t, n, m), B = solve(t2, m, n);
  if (A.size() < B.size()) {
    printf("%d\n", sz(A));
    for (int i = 0; i < A.size(); i++)
      printf("%d %d 0\n", A[i].first, A[i].second);
  } else {
    printf("%d\n", sz(B));
    for (int i = 0; i < B.size(); i++)
      printf("%d %d 1\n", B[i].second, B[i].first);
  }
  return 0;
}
