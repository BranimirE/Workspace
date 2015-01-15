#include <iostream>

using namespace std;

int main() {
  int n, cero = 0, cinco = 0, tmp;
  cin >> n;
  while(n--){
    cin >> tmp;
    if(tmp)
      cinco++;
    else
      cero++;
  }
  if(cero){
    while(cinco, (cinco*5)%9)
      cinco--;
    if(cinco)
      cout << string(cinco, '5')<< string(cero, '0') << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
