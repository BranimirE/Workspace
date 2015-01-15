#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long int Number;
int main(){
  int n, availables = 0, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    if(tmp  == -1){
      if(availables)
        availables--;
      else
        ans++;
    }
    else
      availables += tmp;
  }
  cout << ans << endl;
  return 0;
}

