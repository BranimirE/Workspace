#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int y, n;
	while(cin >> y){
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		vector<int>::iterator ini = v.begin(), fin = v.end(), enc, it;
		int sol = 0, a = 0, b = 0;
		for(it =  ini; it != fin; it++){
			int futuro = (*it) + y -1 ;
			enc = upper_bound(ini, fin, futuro);
			//cout << "revisa " << (*it) <<"("<< futuro << ") encuentra  " << (*enc)  << " con sol =  "<<  (enc-it) << endl;
			if( enc-it > sol ){
				sol = enc-it;
				a = (*it);
				b = (*(enc-1));
			}
		}
		cout << sol << " " << a << " " << b << endl;
	}

	return 0;
}
