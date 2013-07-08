#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;
string toString(long long int num,int k) {
	stringstream ss;
	ss << num;
	string s = ss.str();
	if(s.size() < k)
		return s;
	else
		return s.substr(s.size()-k,k);
}
int main(){

	int n , k;
	while(cin >> n >> k){
		long long int fact = 1;
		for(long long int i = 1; i <= n; ++i)
			fact *= i;
		while((fact%10) == 0)
			fact /= 10;
		cout << toString(fact,k) << endl;
	}
	return 0;
}
