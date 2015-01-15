#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  int t, n;
  cin >> t;
  for(int c = 1; c <= t; c++){
    cin >> n;
    printf("Case %d: %d\n", c, (n << 1));
  }
  return 0;
}
