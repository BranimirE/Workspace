#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
#define MAXN 500005
#define MAXT 1000001
char line[4000003];
int now = 0;
inline int getInt(){
  int n;
  while(true)
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
int v[MAXN];
int n, k;
vector<int> p[MAXT];
int fast(int i){
  return min(i + 1, n - i);
}
int main(){
  n = getInt();
  k = getInt();
  for(int i = 0; i < n; i++){
    v[i] = getInt();
    p[v[i]].push_back(i);
  }
  int ans = INT_MAX;
  for(int i = 0; i < n; i++)
    if(v[i] < k && k - v[i] != v[i]){
      int dog1 = fast(i), dog2 = 0;
      int rem = k - v[i];
      if(!p[rem].empty())
        dog2 = min(fast(p[rem][0]), fast(p[rem][p[rem].size()-1]));
      if(dog2)
        ans = min(ans, max(dog1, dog2));
    }
  if(ans != INT_MAX)printf("%d\n", ans);
  else puts("-1");
  return 0;
}
