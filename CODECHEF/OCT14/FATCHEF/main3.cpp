#include <bits/stdc++.h>
#define MOD 1000000009LL
using namespace std;
vector<pair<int, char> > v;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    v.clear();
    while (m--) {
      char car;
      int pos;
      cin >> car >> pos;
      v.push_back(make_pair(pos, car)); 
    }
    sort(v.begin(), v.end());
    long long int ans = 1;
    char cur = v[0].second;
    for (int i = 1; i < v.size(); i++) {
      if (v[i].second != cur) {
	long long int dif = v[i].first - v[i - 1].first;
	ans = (ans * dif);
	if (ans >= MOD) ans %= MOD;
	cur = v[i].second;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
