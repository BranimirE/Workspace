#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--){
    string cad;
    cin >> cad;
    int a, c, h, u;
    a = c = h = u = 0;
    for(int i = 0; i < cad.size(); i++){
      if(cad[i] == 'a')a++;
      if(cad[i] == 'c')c++;
      if(cad[i] == 'h')h++;
      if(cad[i] == 'u')u++;
    }
    if((a + c + h + u) == cad.size() && c == (3*a) && h == (2*a) && u == (2 * a))
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
