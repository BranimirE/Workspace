#include <iostream>

using namespace std;
typedef unsigned long long int Number;
int main(){
  int tc;
  Number n, v;
  cin >> tc;
  while(tc--){
    cin >> n >> v;
    if(n >= v)
      cout << 0 << endl;
    else{
      Number ans = 1;
      for(Number i = 2; i <= n; i++){
        ans = ans * i;
        if(ans >= v) ans %= v;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
