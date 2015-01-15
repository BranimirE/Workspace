#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
string solve(string &a, string &b){
	int ca[257], cb[257];
	memset(ca, 0, sizeof(cb));
	memset(cb, 0, sizeof(cb));
	for(int i = 0; i < a.size(); i++)
		ca[a[i]]++;
	for(int i = 0; i < b.size(); i++)
		cb[b[i]]++;
	for(char i = 'a'; i <= 'z'; i++)
		if(ca[i] < cb[i])
			return "need tree";
	if(a.size() == b.size()){
		string sa = a;
		string sb = b;
		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());
		if(sa == sb)
			return "array";
	}
	int j = 0, i = 0;
	for(i = 0; i < b.size() && j < a.size(); i++){
		while(j < a.size() && a[j] != b[i])
			j++;
		j++;
	}
	if(i == b.size())
		return "automaton";
	return "both";
}
int main(){
	string a, b;
	cin >> a >> b;
	cout << solve(a, b) << endl;
	return 0;
}
