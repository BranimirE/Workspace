#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int Number;
#define MOD 1000000LL
Number n, a, b, c, d, s, sign, ans;
char line[40];
int now = 0;
int map[MOD], size;
inline int getInt(){
  int n;
  while(1)
    if(line[now]!=0){
      if(line[now]<'0' || line[now]>'9'){
        now++;
        continue;
      }
      n = 0;
      while(line[now]>='0' && line[now]<='9') {
        n = n*10 + line[now] - '0';
        now++;
      }
      return n;
    }
    else{
      gets(line);
      now = 0;
    }
  return n;
}
int main(){
  int t;
  t = getInt();
  while(t--){
    n = getInt();
    a = getInt();
    b = getInt();
    c = getInt();
    d = getInt();
    s = d;
    memset(map, 0, sizeof(map));
    map[s]++;
    size = s;
    for(int i = 1; i < n; i++){
      s = (a*s*s + b*s + c);
      if(s >= MOD)s %= MOD;
      map[s]++;
      if(s > size) size = s;
    }
    sign = 1, ans = 0;
    for(int i = size; i >= 0; i--)
      if(map[i] & 1){
        ans += (sign * (i));
        sign *= (-1);
      }
    printf("%lld\n", ans<0?-ans:ans);
  }
  return 0;
}
