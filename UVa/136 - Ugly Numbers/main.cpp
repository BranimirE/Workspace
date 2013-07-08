#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
long long int f[] ={2,3,5};
vector<long long int> v;
void calcular(int i, long long int prod){
	if(i == 3)
		v.push_back(prod);
	else	
		for(int p = 0; prod*pow(f[i], p) < INT_MAX; p++)
			calcular(i+1,prod*(long long int)pow(f[i],p));
}
int main(){
	/*calcular(0,1);
	sort(v.begin(),v.end());
	cout << "The 1500'th ugly number is "<< v[1500 - 1]  << "."<<endl;*/

	cout << "The 1500'th ugly number is 859963392." << endl;
	return 0;
}
