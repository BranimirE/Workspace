#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
double raiz(int i, Number num){
  return pow(double(num), double(1.0) / double(i));
}
Number powf(Number b, int e){
  if(e == 0)
    return 1LL;
  Number ans = powf(b, e >> 1);
  ans = ans * ans;
  if(e & 1)
    ans *= b;
  return ans;
}
Number root(int i, Number num){
  Number ans = Number(floor(pow(double(num), double(1.0) / double(i))));
  if(powf(ans, i) == num) 
    return ans;

  while(powf(ans + 1, i) <= num)
    ans++;
  while((ans - 1) >= 1 && powf(ans - 1, i) > num)
    ans--;
  return ans;
}
int main(){
  cout << root(3, 801765089LL) << endl;
  cout << ceil(raiz(3, 801765089LL)) << endl;
  return 0;
}
