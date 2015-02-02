/*
ID: brani.e2
PROG: theme
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
//struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
vector<int> v;
int n;
bool check(int len) {
  for(int i = 0; (i + len) <= n; i++)
    for (int j = i + len + 1; (j + len) <= n; j++) {
      bool found = true;
      for (int k = 0; k < len && found; k++)
	if (v[i + k] != v[j + k])
	  found = false;
      if (found) return true;
    }
  return false;      
}
int main() {
  freopen("theme.in", "r", stdin);
  freopen("theme.out","w", stdout);
  scanf("%d", &n);
  int prev, temp;
  scanf("%d", &prev);
  for (int i = 1; i < n; i++) {
    scanf("%d", &temp);
    v.push_back(temp - prev);
    prev = temp;
  }
  n--;
  bool sw = false;
  for (int i = 0; i < n && !sw; i++)
    for (int j = i + 2; j < n && !sw; j++)
      if (v[i] == v[j])
	sw = true;
  if (!sw) {
    printf("0\n");
    return 0;
  }
  int left = 1, right = n - 1;
  while ((right - left) > 1) {
    int mid = (left + right) / 2;
    if (check(mid))
      left = mid;
    else
      right = mid;
  }
  int ans = left + 1;
  if (ans < 5) ans = 0;
  printf("%d\n", ans);
  return 0;
}
