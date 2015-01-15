#include <bits/stdc++.h>

using namespace std;
int rows, cols;
string v[55];
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};
bool isvalid(int i, int j){
  return i >= 0 && i < rows && j >= 0 && j < cols;
}
int dp[52][52][52][52];
int solve(int x1, int y1, int x2, int y2){

  if(!isvalid(x1, y1) || !isvalid(x2, y2)){
    return 0;
  }
  int &ans = dp[x1][y1][x2][y2];  
  if(ans != -1) return ans;
  //  cout << "entra " << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 
  if(x1 == x2 && y1 == y2){ 
    return ans = 1;
  }
  if(x1 > x2 || y1 > y2){ 
    return ans = 0;
  }
  ans = 0;
  if(v[x1][y1] == v[x2][y2]){//sol iguales adicionamos
      // movemos puntero 1 y 2
    for(int k = 0; k < 3; k++){
      for(int l = 0; l < 3; l++)
        ans = max(ans, 2 + solve(x1 + dx[k] , y1 + dy[k], x2 - dx[l], y2 - dy[l]));
    }
  }
  // movemos puntero 1
  for(int k = 0; k < 3; k++){
    ans = max(ans, solve(x1 + dx[k] , y1 + dy[k], x2, y2));
  }
  //movemos puntero 2
  for(int k = 0; k < 3; k++){
    ans = max(ans, solve(x1, y1, x2 - dx[k], y2 - dy[k]));
  }
  return ans;
}
int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d%d", &rows, &cols);
    for(int i = 0; i < rows; i++)
      cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, rows - 1, cols - 1) << endl;
  }
  return 0;
}
