#include <iostream>

using namespace std;
string v[22];
int n;
int mejor(int i, int j, char opt){
  if(i < 0 || i > n || j < 0 || j > n) return 0;
  int sol = (v[i][j] == opt) + max(mejor(i+1, j, opt), mejor(i, j + 1, opt));
  return sol;
}
int solve(int i, int j, char turno){
  if(turno == 'a'){
    int der = mejor(i, j + 1, turno);
    int aba = mejor(i + 1, j, turno);
    if()
    turno =  'b';
  }
}
int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  return 0;
}
