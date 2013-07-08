#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
int main(){
	int n;
	while(cin >> n && n){
		queue<int> c;
		for(int i = 1; i <= n; i++)
			c.push(i);
		cout << "Discarded cards:";
		bool sw = false;
		while(n > 1){
			if(sw)cout << ",";
			sw = true;
			cout << " "<< c.front();
			c.pop();
			n--;
			int tmp = c.front();
			c.pop();
			c.push(tmp);
		}
		cout << endl;
		cout << "Remaining card: " << c.front() << endl;
		
	}
	return 0;
}
