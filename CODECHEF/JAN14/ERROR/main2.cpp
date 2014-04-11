#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  string c;
  cin >> t;
  while(t--){
    cin >> c;
    if(c.find("101") != string::npos || c.find("010") != string::npos)
      cout << "Good" << endl;
    else
      cout << "Bad" << endl;
  }
  return 0;
}

