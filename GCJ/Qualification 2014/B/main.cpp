#include <iostream>
#include <cstdio>
using namespace std;
double c, f, x;

int main(){
  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    cin >> c >> f >> x;
    double sum = 0, vel = 2, ans = x / vel;
    while(sum <= ans){
      ans = min(ans, sum + (x / vel));
      sum += (c / vel);
      vel += f;
    }
    printf("Case #%d: %.7f\n", caso, ans);
  }
  return 0;
}
