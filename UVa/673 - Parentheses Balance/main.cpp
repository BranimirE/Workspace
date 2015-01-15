#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 150

char c[MAX];
bool solve(){
	stack<char> p;
	int tam = strlen(c);
	for(int i = 0; i < tam; i++)
		if(c[i] == '(' || c[i] == '[' )
			p.push(c[i]);
		else{
			if(p.empty()) return false;
			char t = p.top();
			p.pop();
			if((t=='(' && c[i] == ')') or (t=='[' && c[i] == ']') ) continue;
			else return false;
		}
	return p.empty(); // cola esta vacia 
}
int main(){
	int t;
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(c);
		if(solve())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

