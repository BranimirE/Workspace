#include <iostream>
#include <vector>
#include <limits.h>
#include <fstream>
#include <string.h>
#define MAXN 500005
using namespace std;
long long int sol = 0;
int array[MAXN];
int temp[MAXN];
void mergesort(int inicio, int length) {
	if(length<=1)
		return;
	mergesort(inicio, length/2);
	mergesort(inicio+length/2, length-length/2);

	int i = inicio;
	int j = inicio+length/2;
	int n = 0;
	
	while(i<inicio+length/2 && j<inicio+length)
		if(array[i] <= array[j]) {
			temp[n++] = array[i++];
		} else {
			sol += (length/2) - (i-inicio);
			temp[n++] = array[j++];
		}
	while(i<inicio+length/2) {
		temp[n++] = array[i++];
	}
	while(j<inicio+length){
		sol += (length/2) - (i-inicio);
		temp[n++] = array[j++];
	}
	memcpy(array+inicio, temp, length*sizeof(int));
}

int main(){
	int n;
	while(cin >> n && n){
		for(int i = 0; i < n; i++)
			cin >> array[i];
		sol = 0;

		mergesort(0,n);

		cout << sol << endl;
	}
	return 0;
}
