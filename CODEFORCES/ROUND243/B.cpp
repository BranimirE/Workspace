#include <iostream>

using namespace std;
int rows, cols;
int m[101][101];
bool isMirroring(int r){
  for(int i = 0; i < r; i++)
    for(int j = 0; j < cols; j++)
      if(m[i][j] != m[2 * r - i - 1][j])
        return false;
  return true;
}
int main(){
  cin >> rows >> cols;
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
      cin >> m[i][j];
  int ans = rows;
  while(ans % 2 == 0 && isMirroring(ans / 2))
    ans /= 2;
  cout << ans << endl;
  return 0;
}
