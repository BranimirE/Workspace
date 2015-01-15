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
int n, c;
Number t;
vector<int> pos;
int main(){
  cin >> n >> t >> c;
  pos.push_back(0);
  for(int i = 1; i <= n; i++){
    Number tmp;
    cin >> tmp;
    if(tmp > t)
      pos.push_back(i);
  }
  pos.push_back(n + 1);
  int ans = 0;
  for(int i = 1; i < pos.size(); i++){
    int size = pos[i] - pos[i - 1] - 1;
    if(size >= c)
      ans += (size - c) + 1;
  }
  cout << ans << endl;
  return 0;
}
