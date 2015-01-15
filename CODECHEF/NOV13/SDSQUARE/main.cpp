#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
vector<long long int> v;
bool isValid(long long int num){
  long long int d;
  while(num){
      d = num%10LL;
      if(d == 0 || d == 1 || d == 4 || d == 9)
        num /= 10LL;
      else
        return false;
  }
  return true;
}
void solve(){
  for(long long int i = 1; i <= 100100LL; i++){
    long long int tmp = i * i;
    if(isValid(tmp))
      v.push_back(tmp);
  }
}
int main(){
  //freopen("in", "r", stdin);
  solve();
  printf("%d\n", v.size());
  int t;
  long long int a, b;
  scanf("%d", &t);
  while(t--){
    scanf("%lld %lld", &a, &b);
    a = lower_bound(v.begin(), v.end(), a) - v.begin();
    b = upper_bound(v.begin(), v.end(), b) - v.begin();
    printf("%d\n", b-a);
  }
  return 0;
}
