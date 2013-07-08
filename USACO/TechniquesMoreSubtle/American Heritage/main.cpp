/*
ID: brani.e2
PROG: heritage 
LANG: C++
*/

#include <fstream>

using namespace std;

ifstream cin("heritage.in");
ofstream cout("heritage.out");

int buscar(string &c, char car){
	for(int i = 0; i < c.size(); i++)if(c[i] == car)return i;
	return -1;
}
void solve(string &po, string &io){
	if(po.size()){
		int pos = buscar(io, po[0]);
		string ioizq, ioder, poder, poizq;
		ioizq = io.substr(0,pos);
		ioder = io.substr(pos+1, io.size()-(pos+1));
		poizq = po.substr(1,ioizq.size());
		poder = po.substr(1+ioizq.size(),ioder.size());
		solve(poizq, ioizq);
		solve(poder, ioder);
		cout << po[0];
	}
}
int main(){
	string io,po;
	cin >> io >> po;
	solve(po,io);
	cout << endl;
	return 0;
}
