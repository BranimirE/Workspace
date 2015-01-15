#include <iostream>
#include <vector>

using namespace std;
typedef long long int Number;
int n;
Number a[100005];
Number maximo(int suma){
	Number x = suma / 2, y = suma - x;
	return x * y;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	Number ans = 0;
	for(int i = 0; i < n; i++){
		Number b;
		cin >> b;
		if(2LL * a[i] >= b && b > 1)ans += maximo(b);
		else ans -= 1;
	}
	cout << ans << endl;
	return 0;
}
