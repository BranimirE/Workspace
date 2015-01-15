#include <iostream>
#include <cstring>
using namespace std;
string c[4];
int a, b;
bool isvalid(int i, int j){
  return i >= 0 && i < 4 && (j==a || j == b);
}
bool v[4][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};
bool dfs(int i, int j){
  if(c[i][j] != '*') return false;
  if(i == 3) return true;
  v[i][j] = true;
  bool ans = false;
  for(int k = 0; k < 4; k++){
    int ii = i + dx[k];
    int jj = j + dy[k];
    if(isvalid(ii, jj) && v[ii][jj] == false)
      ans |= dfs(ii, jj);
  }
  return ans;
}
string ans[6] = {"", "NOT PREGNANT", "PREGNANT", "INVALID", "OUTDATED", "WAIT"};
int main(){
  int m;
  while(cin >> m, m){
    for(int i = 0; i < 4; i++)
      cin >> c[i];
    a = 1, b = 2;
    memset(v, false, sizeof(v));
    bool C = dfs(0, 1);
    memset(v, false, sizeof(v));
    C |= dfs(0, 2);
    a = 5, b = 6;
    memset(v, false, sizeof(v));
    bool T = dfs(0, 5);
    memset(v, false, sizeof(v));
    T |= dfs(0, 6);    
    int sol = 0;
    if(C && !T){
      sol = 1;
    } else if(C && T){
      sol = 2;
    }else if(C == false){
      sol = 3;
    }
    if(m > 10){
      if(sol == 1 || sol == 2)
        sol = 4;
    }
    if(m < 5)
      if(sol == 1)
        sol = 5;
    cout << ans[sol] << endl;
  }
}
