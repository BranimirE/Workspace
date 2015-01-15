#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
vector<pair<int,int> > v;
int flip(int num, int i){
  int cant = n - i;
  int inv = 0;
  while(cant--){
    int dig = num % 10;
    inv = inv * 10 + dig;
    num /= 10;
  }
  cant = n - i;
  int p = pow(10, cant);
  num *= p;
  num += inv;
  return num;
}
int d[7][6543211];
void solve(){
  memset(d, -1, sizeof(d));
  for(n = 1; n <= 7; n++){
    int ini = 0;
    for(int a = 0; a < n; a++)
      ini = ini * 10 + a;
    queue<int> q;
    d[n - 1][ini] = 0;
    q.push(ini);
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int i = 0; i < (n - 1); i++){
        int v = flip(u, i);
        if(d[n - 1][v] == - 1){
          d[n - 1][v] = d[n - 1][u] + 1;
          q.push(v);
        }
      }
    }
  }
}
int main(){
  solve();
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d", &n);
    v.clear();
    for(int i = 0; i < n; i++){
      int tmp;
      scanf("%d", &tmp);
      v.push_back(make_pair(tmp, i));
    }
    sort(v.rbegin(), v.rend());
    vector<int> act(n);
    int obj = 0;
    for(int i = 0; i < n; i++)
      act[v[i].second] = i;
    for(int i = 0; i < n; i++)
      obj = obj * 10 + act[i];
    cout << d[n-1][obj] << endl;
  }  
  return 0;
}
