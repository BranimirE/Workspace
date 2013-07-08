#include <iostream>
#include <fstream>
#include <vector>
#define MAX 1000000
using namespace std;
bool criba[MAX]={false};
vector<int> p;
int i,j,n;
int main(){
	//freopen("entrada.in","r",stdin);

	criba[0] = criba[1] = true;
	for(i = 4; i < MAX; i += 2)
		criba[i] = true;
	for(i = 3; i * i < MAX; i += 2)
		if(!criba[i])
			for(j = i + i; j < MAX; j += i)
				criba[j] = true;
	for(int i = 2; i < MAX; ++i)
		if(!criba[i])
			p.push_back(i);
	p.push_back(1000000);
	bool sw = true;
	while(cin >> n && n){
	//for(n = 6; n < 100; n++){
		sw = true;
		for(int i = 0; p[i]<=(n-p[i]); i++)
			if(!criba[n-p[i]]){
				cout << n << " = " << p[i] << " + " << (n-p[i]) << endl;
				sw = false;
				break;
			}
		if(sw)
			cout << "Goldbach's conjecture is wrong."<<endl;
	}
	return 0;
}

