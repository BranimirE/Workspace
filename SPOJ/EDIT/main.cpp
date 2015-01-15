#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
char c[1234];
int n;
int solve(int ant) {
  int ans = 0;
  forn (i, n) {
    if (ant == 0) {
      if (!isupper(c[i]))
	  ans++;
	  
    } else {
	if (!islower(c[i])) 
	  ans++;
    }
    ant = 1 - ant;
  }
  return ans;
}
int main() {
  while (scanf("%s", c) != EOF) {
    n = strlen(c);
    printf("%d\n", min(solve(0), solve(1)));
  }
  return 0;
}
