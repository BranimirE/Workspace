#include <iostream>
#include <vector>

using namespace std;

int v[10]={0};
int k, n;
int main(){
	cin >> k;
	cin >> n;
	for(int i  = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		v[tmp[0]-'0']++;
	}
	int ans = 2;
	for(int i = 1; i < 10; i++)
		if(i != 8){
			ans += (v[i] / k);
			if(v[i] % k != 0)
				ans++;
		}
	
	cout << ans << endl;
	return 0;
}
