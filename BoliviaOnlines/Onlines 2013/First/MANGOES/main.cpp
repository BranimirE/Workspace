#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;
int fun(int n){
	int suma = 0;;
	for(int i = 1; i <= n-2; i++){
		if(__gcd(i,i+1)==1 && __gcd(i,i+2)==1 && __gcd(i+1,i+2)==1)
			suma += i;
	}
	return suma;
}
int solve(int n){
	int sol = 0;
	if(n%4 == 0){
		sol = 1;
	}else if(n%4 == 1){
		sol = 1 + ((n/4)*3);
	}else if(n%4 == 2){
		sol = 2 + ((n/4)*2);
	}else if(n%4 == 3){
		sol = 1 + (n/4);
	}
	return sol % n;
}
int main() {


//	for(int i = 1; i < 100; i++)
//		cout << i<<" = "<<i%4 <<" = "<< fun(i )%i<<" =  "<<solve(i)<<endl;
	int t;
	cin >> t;
	long long int n;
	while(t--){
		cin >> n;
		cout << solve(n)<<endl;
	}
	return 0;
}
