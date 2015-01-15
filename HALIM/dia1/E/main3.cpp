#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
int n;
Number flip(Number a, int i){
  int size = n - i, tmp = size;
  Number rev = 0;
  while(tmp--){
    rev = rev * 10LL + (a % 10);
    a /= 10LL;
  }
  a = a * pow(10, size) + rev;
  return a;
}
int solve(int current, int target){
  if(current == target) return 0;
  map<Number, int> dist1, dist2;
  queue<pair<Number, int> > q;
  q.push(make_pair(current, 1));
  q.push(make_pair(target, 2));
  dist1[current] = 0;
  dist2[target] = 0;
  while(!q.empty()){
    Number u = q.front().first;
    int type = q.front().second;
    q.pop();
    for(int i = 0; i < n - 1; i++){
      Number v = flip(u, i); 
      if(type == 1){
        if(dist2.count(v))
          return dist2[v] + 1 + dist1[u];
        if(!dist1.count(v)){
          int tmp = dist1[u] + 1;
          dist1[v] = tmp;
          if(tmp < 5) 
            q.push(make_pair(v, 1));
        }
      }else{
        if(dist1.count(v))
          return dist1[v] + 1 + dist2[u];
        if(!dist2.count(v)){
          int tmp = dist2[u] + 1;
          dist2[v] = tmp;
          if(tmp < 5)
            q.push(make_pair(v, 2));
        }
      }
    }
  }
  return 11;
}
int main(){
  int tc;
  Number target, current;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &n);
    target = 0;
    vector<Number> v(n), cp(n);
    for(int i = 0; i < n; i++){
      target = target * 10 + Number(i);
      scanf("%lld", &v[i]);
      cp[i] = v[i];
    }
    sort(cp.rbegin(), cp.rend());
    current = 0;
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(v[i] == cp[j]){
          current = current * 10 + j;
          break;
        }
    
    printf("%d\n", solve(current, target));
  }
  return 0;
}
