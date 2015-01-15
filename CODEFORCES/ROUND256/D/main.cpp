#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
long long f(long long x) {
  long long sum = 0;
  for(long long i = 1; i <= n; i++)
    sum += min(x / i, m);
  return sum;
}
int main(){
  while(cin >> n >> m >> k) {
    long long l = 1, r = n * m + 1, x;
    long long ans = 1;
    while (l < r) {
      x = (l + r) >> 1LL;
      if (f(x - 1) >= k)
	r = x;
      else
	l = x + 1;
    }
    cout << l - 1 << endl;
  }
  return 0;
}
