#include <iostream>

using namespace std;

int main(){
	string a,b;
	while(cin >> a >> b){
		int i = 0,j=0;
		while(i < a.size() && j < b.size()){
			if(a[i]==b[j])
				cout << a[i++];
			else
				if(a[i] == 'W')
					cout << a[i++];
				else
					cout << b[j++];
		}
		while(i < a.size())cout << a[i++];
		while(j < b.size())cout << b[j++];
		cout << endl;
	}
	return 0;
}
