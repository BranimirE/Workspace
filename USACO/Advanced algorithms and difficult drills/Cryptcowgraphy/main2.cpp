/*
 ID: brani.e2
 PROG: cryptcow 
 LANG: C++
 */
// Original -> "Begin the Escape execution at the Break of Dawn"
// Begin the EscCutino at the BreOape execWak of Dawn 
// Begin the EscCape execution atO the BreWak of Dawn
// segundo caso "CBegin the EscCution at the BreOape execWak of OWDawn"
// caso seis "BCC execuO the EsCinCaWCCreaOpWtiOn at OCDOcOWaOegCeWtheOW BWoWk of Wwn"
/*
 --- our output ---------
 0 0
 --- your output ---------
 1 1
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>


using namespace std;
/*---------- HASH de NealWu------------*/
#define NHASH 7900001
bitset <NHASH> hashtable;
int p [100];
inline unsigned int hash (const string &s)
{
	int len = s.length ();
	unsigned int sum = 0;

	for (int i = 0; i < len; i++)
		sum += p [i] * int (s [i]);
	return sum % NHASH;
}
/*---------- HASH ------------*/

vector<int> pos;
string cadena = "Begin the Escape execution at the Break of Dawn";
long long int bits['z'+ 5];
bool preprocesar(){
	for(int i = 0; i < 'z' + 5; i++) bits[i] = 0;
	for(long long int i = 0; i < cadena.size(); i++)
		bits[cadena[i]] |= (1LL<<i);
}
long long int elibit(int i, long long int mask){
	long long int ans;
	long long int tmp =  ((1LL << (i + 1)) - 1);
	ans = ((mask & ~tmp)>>1LL) | ((tmp>>1LL)&mask) ;
	return ans;
}
bool contiene(string &sc){
	//cout << "contiene : \"" << sc << "\" ? " << endl;
	//cout << cadena << endl;
	int tam = sc.size();
	if(tam == 0) return true;

	long long int ans = bits[sc[0]];
	for(int i = 1; i < tam && ans ; i++){
		long long int tmp = ((bits[sc[i]]>>1LL) & ans) << 1LL;
		ans = tmp;
	}
	//if(ans == 0)
	//	cout << "no encontro la cadena" << sc << endl;
	return ans;
}
bool verificar(string &c){
	//cout << "verificacion de cadena \""  << c << "\"" << endl;
	int i = 0, j = 0, tam = c.size();

	for(j = 1; j < tam; j++){
		if(c[j] == 'C' || c[j] == 'O' || c[j] == 'W'){
			string tmp = c.substr(i+1, j-1-i);
			//cout << "revisa \"" << tmp << "\"" << endl;
			if(!contiene(tmp)){
				//cout << "no contiene(asdf): \"" << tmp << "\"" << endl;
				return false;	
			}
			i = j;
		}
	}
	return true;
}
bool solve(string &c, int nivel){

	int hs = hash(c);
	if(hashtable[hs]){
		//cout << "ya estaba en la tabla" << c << endl;
		return false;
	}
	//cout << "se inserto en la tabla :  \"" << c << "\"" << endl;
	hashtable[hs] =true;

	if(!verificar(c)){
		//cout <<"\""<< c << "\" no pasa verificacion " << endl;
		return false;
	}
	if(nivel == 0 && c == cadena)
		return true;
	int tam = c.size();
	for(int i = 0; i < tam; ++i)
		if(c[i] == 'C')
			for(int j = i + 1; j < tam; ++j)
				if(c[j] == 'O')
					for(int k = j + 1; k < tam; ++k)
						if(c[k] == 'W'){
							string w,x,y,z, cut;
							w = c.substr(0, i);
							x = c.substr(i + 1,(j-1)-i);
							y = c.substr(j + 1, k-1-j);
							z = c.substr(k + 1, c.size() - 1 - k);

							//cout << w << "\\"<< x << "\\" << y << "\\" << z << endl;

							cut = w + y + x + z;

							bool tmp = solve(cut, nivel - 1);
							if(tmp)
								return true;
						}
	return false;
}
int main(){
	preprocesar();
	ifstream cin("cryptcow.in");
	ofstream cout("cryptcow.out");
	p[0] = 1;
	for (int i = 1; i < 100; i++)
		p [i] = 7 * p [i - 1];

	string cad,r, vacio = "" ;
	getline(cin, cad);
	string cop = cad;
	int c = 0, o = 0, w = 0;
	for(int i = 0; i < (int)cad.size(); ++i){
		if(cad[i] == 'C'){c++; pos.push_back(i); continue;}
		if(cad[i] == 'O'){o++; pos.push_back(i); continue;}
		if(cad[i] == 'W'){w++; pos.push_back(i); continue;}
		vacio = vacio + cad[i];
	}
	r = cadena;
	sort(r.begin(), r.end());
	sort(vacio.begin(), vacio.end());
	//cout << "cadena destino: \"" << cadena<<"\"" << endl;
	//cout << cad << endl;
	hashtable.reset();
	if(c == o && o == w && r == vacio && solve(cad, c)){
		cout << 1 << " " << c << endl;
		return 0;
	}
	cout << 0 << " " << 0 << endl;
	return 0;
}
