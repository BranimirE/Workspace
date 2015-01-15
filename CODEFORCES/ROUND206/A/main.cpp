#include <iostream>

using namespace std;

int main() {
  int k, d;
  cin >> k >> d;
  if(d==0 && k > 1)
    cout << "No solution" << endl;
  else
    cout << d << string(k-1, '0') << endl;
  return 0;
}
