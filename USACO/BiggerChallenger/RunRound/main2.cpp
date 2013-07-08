#include <iostream>
#include <cstdio>
#include <fstream>
#include <string.h>
#include <set>
using namespace std;
// 321
/*obs: el digito que es igual o multiplo al tamaño del numero no puede estar en el numero por que daria la vuelta completa
excepto el 1
*/
bool used[50];
char num[50];
set<int> s;
void leer(){
	gets(num);
	for(int i = 0; num[i]; i++)
		num[i] -= '0';
}
bool esNumeroCircular(unsigned long long int N){
	memset(used,0,sizeof used);
	int tam = 0,c=0;
	s.clear();
	while(N){
		num[tam] = N%10;
		s.insert(num[tam]);
		tam++;
		N/=10;
	}
	if(s.size()!=tam)return false;
	int i = 0, j = tam-1;
	while(i < j ){
		swap(num[i],num[j]);
		i++;j--;
	}
	i = c = 0;

	while(c<tam){
		i = (i+num[i]) % tam;
		if(used[i])
			break;
		used[i] = true;
		c++;
	}
	return (c==tam);
}
string dondeLlegara(int N){
	int tam = 0;
	while(N){
		num[tam++] = N%10;
		N/=10;
	}
	int i = 0, j = tam-1;
	while(i < j ){
		swap(num[i],num[j]);
		i++;j--;
	}
	string sal(tam,'0');
	for(i = 0; i < tam; i++)
		sal[i] = ((i+num[i])%tam)+'0';
	return sal;
}

//int main() {
	//ifstream cin("lamps.in");
	//ofstream cout("runround.out");
	/*unsigned long long int N;
	cin >> N;
	N++;
	while(!esNumeroCircular(N))
		N++;
	cout << N << endl;*/
/*
	unsigned long long int c=0;
	cout << "{";
	for(int i = 0; i <= 9682415; i++)
		if(esNumeroCircular(i)){
			cout << i << ", ";
			c++;

		}
	cout << "}"<<endl;
	cout <<endl<< c << endl;
			//cout << esNumeroCircular(i) << " " << i  <<" "<<dondeLlegara(i)<< endl;

//	cout << 81361 <<" "<<dondeLlegara(81361)<< endl;
//	cout << 81362 <<" "<<dondeLlegara(81362)<< endl;
	return 0;
}
*/
