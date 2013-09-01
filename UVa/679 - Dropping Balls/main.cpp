#include <iostream>

using namespace std;
int niveles;
int solve(int niv, int I, int actual){
	if(niv == niveles)
		return actual;
	if(I % 2 == 0)//a la derecha
		return solve(niv + 1, I/2, actual * 2 + 1);
	else // a la izquierda
		return solve(niv + 1, (I+1)/2, actual * 2     );
}
int main(){
	int t;
	int I;
	while(cin >> t && t!=-1)
		while(t--){
			cin >> niveles >> I;
			cout << solve(1, I, 1) << endl;
		}
	return 0;
}
