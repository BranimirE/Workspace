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
#define MAXPRIME 32000

class LCMSetEasy {
public:
	bitset<MAXPRIME> criba;
	vector<long long int> primos;
	void fillc(){
		criba.set();
		for (int i = 2; i < MAXPRIME; i++)
			if (criba.test( i )){
				primos.push_back( i );
				for (int j= i + i; j < MAXPRIME; j += i)
					criba.reset( j );
			}
	}
	map<long long int, int> fact(long long n){
		map<long long , int> ans;
		int pos = 0;
		while(primos[pos] * primos[pos] <= n){
			while(n % primos[pos] == 0){
				ans[primos[pos]]++;
				n /= primos[pos];
			}
			pos++;
		}
		if(n > 1)
			ans[n]++;
		return ans;
	}
	int calc(int a, int b){
		int n = 2;
		int result = 1;

		while(a != 1 || b != 1){
			while( a % n != 0 && b % n != 0)
				n++;
			if(a % n == 0)
				a /= n;
			if(b%n == 0)
				b/=n;
			result *= n;
		}
		return result;
	}
	string include(vector <int> S, int x) {
		fillc();
		map<long long int, int> f = fact((long long) x);
		map<long long int, bool> ans;
		map<long long int, int>::iterator it;
		for(it = f.begin(); it != f.end(); it++)
			ans[it->first] = false;
		for(int i = 0; i < S.size(); i++){
			map<long long int, int> f2 = fact((long long) S[i]);
			bool sw = true;
			for(it = f2.begin(); it!= f2.end(); it++)
				if((it->second) > f[it->first]) sw = false;
			if(sw)
				for(it = f2.begin(); it!= f2.end(); it++)
					if((it-> second) && (it->second) == f[it->first]) ans[it->first] = true;
		}
		for(map<long long, bool>::iterator it2 = ans.begin(); it2 != ans.end(); it2++)
			if(it2->second == false)
				return "Impossible";

		return "Possible";
	}

};
