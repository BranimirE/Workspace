#include <iostream>
#include <fstream>

using namespace std;
void rotarH(string &c){
	char tmp = c[1];
	c[1] = c[2];
	c[2] = c[4];
	c[4] = c[3];
	c[3] = tmp;

}
void rotarV(string &c){
	char tmp = c[0];
	c[0] = c[1];
	c[1] = c[5];
	c[5] = c[4];
	c[4] = tmp;
}
int main(){
//	freopen("entrada.in","r",stdin);
	string cad;
	while(cin >> cad){
		bool sw = false;
		string a = cad.substr(0,6);
		string b = cad.substr(6,6);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j< 4; j++){
				for(int k = 0; k < 4; k++){
					for(int h = 0; h < 4; h++){
						if(a == b){
							sw = true;
							goto salir;
						}		
						rotarV(b);
					}
					rotarH(b);
				}
				rotarV(a);
			}
			rotarH(a);
		}
		salir:;
		if(sw)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}
	return 0;
}
