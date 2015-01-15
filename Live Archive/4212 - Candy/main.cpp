#include <iostream>

using namespace std;
int v[100000];
int main(){
  int rows, cols;
  
  while(cin >> rows >> cols && !(rows == 0 && cols == 0)){
    for(int i = 0; i < rows; i++){
      int a, b, c;
      if(cols == 1)
        cin >> v[i];
      else if(cols == 2){
        cin >> a >> b;
        v[i] = max(a, b);
      }
      else if(cols == 3){
        cin >> a >> b >> c;
        v[i] = max(b, a + c);
      }else{
        cin >> a >> b >> c;
        c += a;
        for(int j = 3; j < cols; j++){
          int tmp;
          cin >> tmp;
          tmp += max(a, b);
          a = b;
          b = c;
          c = tmp;
        }
        v[i] = max(b, c);
      }
    }
    if(rows == 1)
      cout << v[0] << endl;
    else if(rows == 2)
      cout << max(v[0], v[1]) << endl;
    else if(rows == 3)
      cout << max(v[0] + v[2], v[1]) << endl;
    else{
      v[2] += v[0];
      for(int j = 3; j < rows; j++)
        v[j] += max(v[j - 2], v[j - 3]);
      cout << max(v[rows - 1], v[rows - 2]) << endl;
    }
  }
  return 0;
}
