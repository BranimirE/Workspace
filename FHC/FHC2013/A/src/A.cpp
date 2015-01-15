//============================================================================
// Name        : Fibo
// Author      : Branimir
// Version     : 0
// Copyright   : free source
// Description : Generate fibonnaci numbers
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int fibo(int n){
	if(n < 2)return n;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {

	return 0;
}
