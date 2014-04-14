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
#include <climits>

using namespace std;

typedef long long int Number;
class SplitIntoPairs {
public:
  int makepairs(vector <int> A, int X) {
    int neg = 0;
    Number mneg = -1000000001, mpos = 1000000001;
    for(int i = 0; i < A.size(); i++)
      if(A[i] < 0){
        neg++;
        mneg = max(mneg, (Number)A[i]);
      }else
        mpos = min(mpos, (Number)A[i]);
    int ans = A.size()/2;
    if(neg % 2 == 0)
      return ans;
    return ans - 1 + (mneg*mpos >= (Number)X);
  }
};
