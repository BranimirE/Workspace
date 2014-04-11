#include <cstdio>
using namespace std;
typedef unsigned long long int Number;
Number l, d, s, c;
Number diaobj;
bool solve(){
  Number num = s;
  for(int dias = 2; dias <= d && num < l; dias++)
    num = num + c * num;
  return num >= l;
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%llu %llu %llu %llu", &l, &d, &s, &c);
    puts(solve()?"ALIVE AND KICKING":"DEAD AND ROTTING");
  }
  return 0;
}
