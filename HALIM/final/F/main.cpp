#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll> S;

bool pascalito(ll a, ll b) {
  if(S.count(a) == 0 || a == 0 || a == b) {
    return true;
  } else {
    if(pascalito(a-1, b-1) == pascalito(a-1, b))
      return true;
    else
      return false;
  }
}

int main() {
  for(ll i=0; i<=63; i++) {
    S.insert(pow(2, i) - 1);
  }

  ll n, m;
  while(scanf("%lld %lld", &n, &m) != EOF) {
    if(pascalito(n, m))
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
