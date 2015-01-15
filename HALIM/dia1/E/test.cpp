#include <bits/stdc++.h>

using namespace std;

int main(){
  map<int, int> m;
  m[10] = 10;
  m[1] = 0;
  cout << m.count(10) << endl;
  cout << m.count(1) << endl;
  cout << m.count(11) << endl;
  
  return 0;
}
