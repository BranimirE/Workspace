#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> matches[300001];
int f(char car){
  if(car == 'A') return 0;
  if(car == 'G') return 1;
  if(car == 'C') return 2;
  if(car == 'T') return 3;
  return -1;
}
int hash(string c){
  int n = c.size();
  int ans = 0;
  for(int i = n - 1, p = 0; i >= 0; i--, p++){
    int tmp = f(c[i]);
    if(tmp == -1) return 300000;
    ans += (tmp * pow(4, p));
  } 
  return ans;
}
int main(){
  int cases;
  cin >> cases;
  string s, k;
  int q;
  while(cases--){
    cin >> s;
    for(int i = 0; i <= 262144; i++)
      matches[i].clear();
    for(int i = 0; i + 9 <= s.size(); i++){
      string insert = string(s.begin() + i, s.begin() + i + 9);
      matches[hash(insert)].push_back(i);
    }
   
    cin >> q;
    while(q--){
      cin >> k;
      vector<int> &ans = matches[hash(k)];
      if(ans.size()){
        for(int i = 0; i < ans.size(); i++){
          if(i) cout << " ";
          cout << ans[i];
        }
        cout << endl;
      }else
        cout << "No occurrences found." << endl;
    }
    if(cases) cout << endl;
  }
  return 0;
}
