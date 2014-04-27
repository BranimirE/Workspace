#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
typedef long long int Number;
using namespace std;

int main(){
  int n, cup, maxi = 0, sum = 0;
  cin >> n >> cup;
  while(n--){
    int tmp;
    cin >> tmp;
    sum += tmp;
    maxi = max(maxi, tmp);
  }
  sum -= maxi;
  puts(sum<=cup?"YES":"NO");
  return 0;
}
