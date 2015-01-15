#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;
typedef long long int Number;
int n;
vector<pair<int,int> > v;
string flip(string cad, int i){
  string ans = cad.substr(0, i);
  string tmp = cad.substr(i, n - i);
  ans += string(tmp.rbegin(), tmp.rend());
  return ans;
}

int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d", &n);
    v.clear();
    string actual = "";
    for(int i = 0; i < n; i++){
      int tmp;
      scanf("%d", &tmp);
      v.push_back(make_pair(tmp, i));
      actual.push_back('0' + i);
    }

    sort(v.rbegin(), v.rend());
    string obj = "";
    for(int i = 0; i < n; i++)
      obj.push_back('0' + v[i].second);

    queue<string> q;
    map<string,int> d;
    map<string, int>::iterator it;
    set<string> visitado;
    d[actual] = 0;
    q.push(actual);
    if(actual != obj){
      bool found = false;
      visitado.insert(actual);
      while(!q.empty() && !found){
        string u = q.front();
        q.pop();
        int dist = d[u];
        for(int i = 0; i < (n-1) && !found; i++){
          string v = flip(u, i);
          if(visitado.count(v) == 0){
            visitado.insert(v);
            d[v] = dist + 1;
            q.push(v);
            if(v == obj)
              found = true;
          }
        }
      }
    }
    cout << d[obj] << endl;
  }
  return 0;
}
