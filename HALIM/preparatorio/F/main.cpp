#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int Number;

Number bar[35];
vector<Number> subsets(const vector<Number> &v){
  int n = v.size();
  vector<Number> ans;
  for(int mask = 0; mask < (1<<n); mask++){
    Number sum = 0;
    for(int i = 0; i < n; i++)
      if(mask & (1<<i))
        sum += v[i];
    ans.push_back(sum);
  }
  sort(ans.begin(), ans.end());
  return ans;
}
bool solve(Number obj, int n){
  vector<Number> A(bar, bar + (n / 2));
  vector<Number> B(bar + (n / 2), bar + n);
  A = subsets(A);
  B = subsets(B);
  for(int i = 0; i < A.size(); i++){
    if(A[i] > obj)break;
    if(binary_search(B.begin(), B.end(), obj - A[i]))
       return true;
  }
  return false;
}
int main(){
  int cases;
  Number obj; int bars;
  cin >> cases;
  while(cases--){
    cin >> obj >> bars;
    for(int i = 0; i < bars; i++)
      cin >> bar[i];
    puts(solve(obj, bars)?"YES":"NO");
  }
  return 0;
}
