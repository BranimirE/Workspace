#include <iostream>
#include <fstream>

#define MAXN 100
using namespace std;

int N;
int num[MAXN];
int bestrun[MAXN];
int main(int argc, char **argv) {
	ifstream in("entrada.txt");
	in >> N;
	for(int i = 0; i < N; i++){
		in >> num[i];
	}
	int i, j, highestrun = 0;
	bestrun[0] = num[N-1];
	highestrun = 1;
	for (i = N-1-1; i >= 0; i--) {
		if (num[i] < bestrun[0]) {
			bestrun[0] = num[i];
			continue;
		}
		for (j = highestrun - 1; j >= 0; j--) {
			if (num[i] > bestrun[j]) {
				if (j == highestrun - 1 || num[i] < bestrun[j+1]){
					bestrun[++j] = num[i];
					if (j == highestrun) highestrun++;
					break;
				}
			}
		}
	}
	cout << highestrun << endl;
	return 0;
}

