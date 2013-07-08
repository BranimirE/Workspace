#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		string cad ;
		cin >> cad;
		string turno = "Jennifer";
		string ganador = "Jennifer";
		int tamg = 0;
		for(int i = 0; i < (int)cad.size();){
			int tmp = 0;
			while(i < (int)cad.size() && cad[i]==':'){
				i++;
				tmp++;
			}
			while(i < (int)cad.size() && cad[i]==')'){
				i++;
				tmp++;
			}
			if(tmp > tamg)
				ganador = turno, tamg = tmp;

			if(turno == "Jennifer")
				turno = "Alan";
			else
				turno = "Jennifer";
		}
		cout << ganador << endl;
	}

	return 0;
}

/*
3
:):))
::):::)
:)))):)))):))))):)

 */
