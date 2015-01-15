#include <cstdio>
#include <iostream>
#define MAXN 1005
using namespace std;
int v[MAXN][MAXN];
int n, q;
bool row[MAXN]= {false}, col[MAXN] = {false};
int c[MAXN][2][2] = {0};
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n;i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &v[i][j]);
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c[i][0][0] += (v[i][j] * v[j][i]);
      c[i][1][0] += ((1 - v[i][j]) * v[j][i]);
      c[i][0][1] += (v[i][j] * (1 - v[j][i]));
      c[i][1][1] += ((1 - v[i][j]) * (1 - v[j][i]));
    }
    cout << c[i][0][0] << " ";
    ans += c[i][0][0];
  }
  cout << endl;
  scanf("%d", &q);
  int op, i;
  bool sw = false;
  string sol = "";
  while(q--){
    scanf("%d", &op);
    if(op == 1){//row flip
      scanf("%d", &i);
      ans -= c[i][row[i]][col[i]];
      row[i] = 1 - row[i];
      ans += c[i][row[i]][col[i]];
    }
    if(op == 2){
      scanf("%d", &i);
      ans -= c[i][row[i]][col[i]];
      col[i] = 1 - col[i];
      ans += c[i][row[i]][col[i]];
    }
    if(op == 3){
      //printf("%d", 1 & ans);
      if(1 & ans)
        sol += '1';
      else
        sol += '0';
      sw = true;
    }
  }
  cout << sol << endl;
  if(sw)
    puts("");
  return 0;
}
