#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX 101
int obj, n, v[MAX];
int main(){
  freopen("in", "r", stdin);
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    scanf("%d", &obj);
    obj = v[obj-1];
    sort(v, v + n);
    printf("%d\n", lower_bound(v, v + n, obj) - v + 1);
  }
  return 0;
}
