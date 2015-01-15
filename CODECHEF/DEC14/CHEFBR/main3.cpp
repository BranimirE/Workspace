#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

int n, v[102];
int solve(int i, int j, vector<vector<int> > &sol) {
  if (j < i){//La cadena vacia
    return 1;
  }
  int ans = 0;
  for (int k = i + 2; k <= j-1; k++) {
    ans += solve(i, k - 1) * solve(k, j);
  }
  if (v[i] < 0 && v[i] == -v[j]) {
    
  }
  ans += solve(i + 1, j);
  ans += solve(i, j - 1);
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  cout << solve(0, n - 1) << endl;
  return 0;
}
