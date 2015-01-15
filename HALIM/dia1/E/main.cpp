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
/*
int solve(int current, int target){
  //  cout << "cur = " << current << endl;
  //  cout << "tar = " << target << endl;
  if(current == target) return 0;
  map<Number, int> dist;
  queue<pair<Number, int> > q;
  q.push(make_pair(current, -1));
  q.push(make_pair(target, -1));
  dist[current] = 0;
  dist[target] = 0;
  bool found = false;
  //cout << "visita:" << endl;
  while(!q.empty() && !found){
    Number u = q.front().first;
    int parent = q.front().second;
    q.pop();
    for(int i = 0; i < n - 1 && !found; i++){
      if(i == parent) continue;
      Number v = flip(u, i); 
      if(v != current && v != target && dist[v] == 0){
        dist[v] = dist[u] + 1;
        q.push(make_pair(v, i));
        //        cout << v << endl;
      }else{
        cout << "l2" << endl;        
        return dist[u] + 1 + dist[v];
      }
    }
  }
  cout << "l3" << endl;
  return dist[target];
}
*/
int solve(int current, int target){
  set<Number> visited;
  map<Number, int> dist;
  queue<Number> q;
  visited.insert(current);
  q.push(current);
  dist[current] = 0;
  bool found = false;
  int maxi = 0;
  while(!q.empty() && !found){
    Number u = q.front(); q.pop();
    for(int i = 0; i < n - 1 && !found; i++){
      Number v = flip(u, i);
      if(!visited.count(v)){
        dist[v] = dist[u] + 1;
        if(v == target)
          found = true;
        //        maxi = max(maxi, dist[v]);
        visited.insert(v);
        q.push(v);
      }
    }
  }
  //  cout << "maxima dist = " << maxi << endl;
  return dist[target];
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
    //sort(cp.begin(), cp.end());
    
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(v[i] == cp[j]){
          current = current * 10 + j;
          break;
        }
    
    /*
    int maxi = 0;
    do{
      current = 0;
      for(int i = 0; i < n; i++)
        current = current * 10 + cp[i];
      cout << "cur = " << current << " tar = " << target << endl;
      int a = solve(current, target);
      int b = solve2(current , target);
      printf("%d %d\n", a, b);
      if(a != b){ 
        cout << "falla" << endl;
        break;
      }
    }while(next_permutation(cp.begin(), cp.end()));
    */
    //printf("%d %d\n", solve(current, target), solve2(current, target));
    printf("%d\n", solve(current, target));
  }

  return 0;
}
