#include <cstdio>
#include <bitset>
#include <iostream>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	char s[5];
	int a, b, ans;
	while(t--){
		scanf("%x %s %x", &a, &s, &b);
		bitset<13> A(a), B(b);
		if(s[0] == '-')
			ans = a - b;
		else
			ans = a + b;
		cout << A << " " << s  << " " << B << " = " << ans << endl;
	}
	return 0;
}
