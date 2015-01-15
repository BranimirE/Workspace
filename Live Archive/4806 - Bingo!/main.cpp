#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 95
using namespace std;
int n, b;
bool m[MAX];
int v[MAX];
int main(){
  while(scanf("%d%d", &n, &b), !(n==0 && b==0)){
    memset(m, false, sizeof m);
    for(int i = 0; i < b; i++){
      scanf("%d", &v[i]);
      for(int j = i; j >= 0; j--)
        m[abs(v[i]-v[j])] = true;
    }
    bool sol = true;
    for(int i = 0; i <= n && sol; i++)
      sol = m[i];
    puts(sol?"Y":"N");
  }
  return 0;
}
/*
6 7
2 1 3 4 0 6 5
5 4
5 3 0 1
5 3
1 5 0
0 0

*/
