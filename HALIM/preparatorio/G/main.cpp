#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 1005

using namespace std;

int q[MAX];
int dq[MAX];
int n;
int dp[MAX][MAX];
bool solve(int i, int j){
  int obj = i + n - j - 1;
  if(i == j) return dq[i] == q[obj];
  if(dp[i][j] != -1) return dp[i][j];
  bool ans = false;
  if(dq[i] == q[obj])
    ans |= solve(i + 1, j);
  if(dq[j] == q[obj])
    ans |= solve(i, j - 1);
  return dp[i][j] = ans;
}
int main(){
  while(cin >> n){
    for(int i = 0; i < n; i++)
      cin >> dq[i];
    for(int i = 0; i < n; i++)
      cin >> q[i];
    memset(dp, -1, sizeof(dp));
    puts(solve(0, n - 1)?"1":"0");
  }
  return 0;
}
