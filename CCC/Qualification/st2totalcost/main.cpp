#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int Number;
int main(){
  int t;
  cin >> t;
  while(t--){
    Number totalcost, services;
    cin >> totalcost >> services;
    while(services--){
      Number cost; string state;
      cin >> cost >> state;
      if(state[0] == 'u')
        totalcost -= cost;
    }
    printf("%lld\n",(totalcost < 0? -1LL: totalcost));
  }
  return 0;
}
