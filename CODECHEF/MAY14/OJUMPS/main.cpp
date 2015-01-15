#include <cstdio>
using namespace std;
int main(){
  long long int n;
  while(scanf("%lld", &n) != EOF){
    n %= 6LL;
    puts((n == 0 || n==1 || n==3)?"yes":"no");
  }
  return 0;
}
