/*
 ID: brani.e2
 PROG: job
 LANG: C++
*/
#include <bits/stdc++.h>
#define MAX 32
#define MAXN 1005
using namespace std;
int p[MAXN][MAX];
int dp[MAXN][MAX];
int solve(int tasks, int machine, int n, int *a){
  int &ans = dp[tasks][machine];
  if(ans != -1) return ans;
  if(machine == n - 1){
    p[tasks][machine] = tasks;
    return ans = (tasks * a[machine]);
  }
  ans = solve(tasks, machine + 1, n, a);
  p[tasks][machine] = tasks;
  for(int t = 0; t <= tasks; t++){
    int tmp = max((tasks - t) * a[machine], solve(t, machine + 1, n, a));
    if(tmp < ans){
      ans = tmp;
      p[tasks][machine] = tasks - t;
    }
  }
  return ans;
}
void calculate(int *a, int n, int ntasks, int *ini){
  sort(a, a + n);
  memset(dp, -1, sizeof(dp));
  solve(ntasks, 0, n, a);
  int t = ntasks;
  int pos = 0;
  for(int machine = 0; machine < n && t; machine++){
    int tmp = p[t][machine];
    for(int i = 1; i <= tmp; i++)
      ini[pos++] = a[machine] * i;
    t -= tmp;
  }
  sort(ini, ini + ntasks);
}
int a[MAX], b[MAX];
int timeA[MAXN], timeB[MAXN];
int main(){
  freopen("job.in", "r", stdin);
  freopen("job.out", "w", stdout);
  int ntasks, n, m;
  cin >> ntasks >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < m; i++)
    cin >> b[i];

  calculate(a, n, ntasks, timeA);
  calculate(b, m, ntasks, timeB);

  int A = 0, B = 0;
  for(int i = 0; i < ntasks; i++){
    A = max(A, timeA[i]);
    B = max(B, timeA[i] + timeB[ntasks - i - 1]);
  }
  cout << A << " " << B << endl;
  return 0;
}
