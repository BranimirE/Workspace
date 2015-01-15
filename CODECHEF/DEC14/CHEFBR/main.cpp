#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

int n, v[102];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int ans = 0;
  for (int mask = 0, lim = (1<<n); mask < lim; mask++) {
    stack<int> q;
    bool balanceado = true;

    for (int i = 0; i < n && balanceado; i++) {
      if (mask & (1 << i)) {
	int e = v[i];
	if (e < 0) {//Abrir
	  q.push(-e);
	} else {//Cerrar
	  if (!q.empty() && q.top() == e) {
	    q.pop();
	  } else {
	    balanceado = false;
	  }
	}
      }
    }
    balanceado = balanceado && q.empty();
    if (balanceado) {
      cout << "{";
      for (int i = 0; i < n; i++) {
	if (i) cout << ", ";
	if (mask & (1 << i))
	  printf("%2d", v[i]);
	else
	  printf("  ");
      }
      cout << "}" << endl;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
