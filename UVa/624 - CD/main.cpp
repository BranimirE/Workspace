#include <iostream>

using namespace std;

#define MAXN 20
int N, suma, tmp, masksol;
int vec[MAXN];


int main(int argc, char **argv) {
	while(cin >> suma){
		cin >> N;

		for(int i = 0; i < N; i++)
			cin >> vec[i];
		int sol = 0;
		masksol = 0;
		for(int mask = 0; mask < (1<<N); mask++){
			tmp = 0;
			for(int i = 0; i < N; i++){
				if(mask&(1<<i)){
					tmp += vec[i];
				}
			}
			if(tmp <= suma){
				sol = max(sol,tmp);
				masksol = mask;
			}
		}
		for(int i = 0; i < N; i++){
			if(masksol&(1<<i))
				cout << vec[i]<<" ";
		}
		cout << "sum:"<<sol<<endl;
	}
	return 0;
}
/*
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2


 */

