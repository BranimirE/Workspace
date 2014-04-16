#include <cstdio>
#include <set>

using namespace std;

int main(){
  int t, n, k, p, a, b;
  set<int> c;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d%d", &n, &k, &p);
    c.clear();
    while(k--){
      scanf("%d%d", &a, &b);
      c.insert(a - 1);
      c.insert(b);
    }
    bool ans = true;
    while(p--){
      scanf("%d%d", &a, &b);
      if(ans)
        ans = c.count(a-1) && c.count(b);
    }
    puts(ans?"Yes":"No");
  }
  return 0;
}
