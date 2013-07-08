#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;
long long int fact(int n){
	long long int res = 1;
	for(long long int i = 1; i <=n; i++)
		res *= i;
	return res;
}
int main() {
	int T,n,tmp;
	long long int imp;
	cin >> T;
	while(T--){
		cin >> n;
		imp = 0;
		int vec[10];
		memset(vec,0,sizeof vec);
		for(int i = 0; i < n; i++){
			cin >> tmp;
			vec[tmp]++;
			if(tmp % 2 == 1)
				imp++;
		}
		if(vec[0] == 0){
			cout << fact(n-1)*imp << endl;//suponemos que ningun numero se repite
		}else{
			long long int res = fact(n-2)*imp;//1
			cout << ((fact(n-1)*imp)-res )<<endl;//
		}
	}
	return 0;
}
/*
3
5 6 3 2 0 9
5 1 2 3 4 5
5 1 3 5 7 9


 */

