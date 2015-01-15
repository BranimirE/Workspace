#include <iostream>

using namespace std;
string v[302];
int n;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  char a = v[0][0], b = v[0][1];
  if(a == b){
    cout << "NO" << endl;
    return 0;
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(i == j || i == (n - j - 1)){
        if(v[i][j] != a){
          cout << "NO" << endl;
          return 0;
        }
      }else{
        if(v[i][j] != b){
          cout << "NO" << endl;
          return 0;
        } 
      }
  cout << "YES" << endl;
  return 0;
}









