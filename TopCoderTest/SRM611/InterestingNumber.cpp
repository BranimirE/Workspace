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


class InterestingNumber {
public:
	vector<bool> v;
	int finds(string &c, char car, int i){
		while(i < c.size()){
			if(c[i] == car){
				if(v[i])return -1;
				return i;
			}
			i++;
		}
		return -1;
	}
	string isInteresting(string x) {
		v = vector<bool>(x.size(), false);
		for(int i = 0; i < x.size(); i++)
			if(!v[i]){
				int b = finds(x, x[i], i+1);
				if(b == -1 || v[b] || b != i + (x[i] - '0' + 1)) return "Not interesting";
				v[i] = v[b] = true;
			}
		return "Interesting";
	}
};
