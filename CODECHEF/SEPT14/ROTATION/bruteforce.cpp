#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int vec[100001];
int cp[100001];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> vec[i];
  while (m --) {
    char op; int num;
    cin >> op >> num;
    if (op == 'R')
      cout << vec[num] << endl;
    else {
      if (op == 'A')
	num = n - num;
      int pos = 1;
      for (int i = num + 1; i <= n; i++)
	cp[pos++] = vec[i];
      for (int i = 1; i <= num; i++)
	cp[pos++] = vec[i];
      for (int i = 1; i <= n; i++)
	vec[i] = cp[i];
    }
  }
  return 0;
}
