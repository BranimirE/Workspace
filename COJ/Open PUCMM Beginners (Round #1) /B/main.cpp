#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 1002
int n;
long long int k;
long long int vec[MAXN];
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec,vec+n);
	vec[n] = 0;
	for(int i = n-1; i >= 0; i--){
		vec[i] += vec[i+1];
		if(vec[i]>=k){
			cout << n-i << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
