#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;
int fila , colum, n;

int main() {

	cin >> fila>> colum;
	cin >> fila >>  colum >> n;
	int cant[n];
	char dir[n];
	for(int i = 0; i < n; i++)
		cin >> dir[i] >> cant[i];

	for(int i = n-1; i >= 0; i--){
		if(dir[i]=='E')
			colum-= cant[i];
		if(dir[i]=='W')
			colum+= cant[i];
		if(dir[i]=='N')
			fila += cant[i];
		if(dir[i]=='S')
			fila -= cant[i];

	}
	cout << fila <<" "<< colum << endl;
	return 0;

}
