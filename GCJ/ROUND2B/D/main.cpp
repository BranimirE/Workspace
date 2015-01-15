#include <bits/stdc++.h>

using namespace std;
char s[100000][81];
int trie[1000000][26];
int mask[1000000];
bool terminal[1000000];
int node;
void add(char *s){
	int p=0;
	for(int i = 0; i < strlen(s); i++){
		mask[p]|=(1<<(s[i]-'a'));
		if(trie[p][s[i]-'a']==0)
			p=trie[p][s[i]-'a']=++node;
		else
			p=trie[p][s[i]-'a'];
	}
	terminal[p] = 1;
}
char v[10][15];
int n, ser;
int cant[15];
void solve(int i, int disp){
	if(i == ser){
		cout << "contar" << endl;
		for(int j = 0; j < ser; j++)
			cout << cant[j] << " ";
		cout << endl;
		return;
	}
	for(int j = 0; j <= disp; j++){
		cant[i] = j;
		solve(i + 1, disp - j);
		cant[i] = 0;
	}
}
int main() {

	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n >> ser;
		memset(trie, 0, sizeof(trie));
		memset(mask, 0, sizeof(mask));
		memset(terminal, 0, sizeof(terminal));
		node = 0;

		for(int i = 0; i < n; i++)
			scanf("%s", v[i]);

		sort(v, v + n);
		solve(0, ser);
	}
	return 0;
}

