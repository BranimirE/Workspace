#include <iostream>
#include <fstream>


using namespace std;
struct BigNumber{
	int d[3000];
	void print(int i){
		if(d[i] != -1){
			print(i+1);
			cout << d[i];
		}
	}
	BigNumber operator * (int n){
		int resto = 0;
		BigNumber ans;
		int i = 0;
		for(i = 0; d[i] != -1; i++){
			resto += (n*d[i]);
			ans.d[i] = resto % 10;
			resto /= 10;
		}
		while(resto){
			ans.d[i++] = resto % 10;
			resto /= 10;
		}
		ans.d[i] = -1;
		return ans;
	}
} v[1001];
int main(){
	//freopen("entrada.in","r",stdin);
	v[0].d[0] = 1;
	v[0].d[1] = -1;
	for(int i = 1; i <= 1000; i++)
		v[i] = v[i-1]*i;
	int n;
	while(cin >> n){
		cout << n << "!" << endl;
		v[n].print(0);
		cout << endl;
	}
	return 0;
}
