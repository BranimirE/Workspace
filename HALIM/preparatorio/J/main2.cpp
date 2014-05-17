#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100000
int n;
int v[MAX + MAX + 10];
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n;
    int ans = 0;
    memset(v, -1,sizeof(v));
    int current = MAX;
    v[current] = 0;
    for(int i = 1; i <= n; i++){
      long long int tmp;
      cin >> tmp;
      if(tmp > 0) tmp = 1;
      else tmp = -1;
      current += tmp;
      if(v[current] != -1)
        ans = max(ans, i - v[current]);
      if(v[current] == -1)
        v[current] = i;
    }
    cout << ans << endl;
  }
  return 0;
}
