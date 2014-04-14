#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class MiddleCode {
public:
  string encode(string s) {
    string t = "";
    int n =  s.size(), a, b;
    int m = n / 2;
    if(n % 2 == 1){
      t = t + s[m];
      a = m - 1;
      b = m + 1;
    }else{
      a = m - 1;
      b = m;
    }
    while(a >= 0){
      t = t + min(s[a],s[b]);
      t = t + max(s[a],s[b]);
      a--;
      b++;
    }
    return t;
  }
};
