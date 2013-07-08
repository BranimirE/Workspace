/*
ID: brani.e2
PROG: ratios
LANG: C++
 */
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct mez{
	int x,y,z;
	mez(){
		x = y = z = 0;
	}
	mez(int _x,int _y, int _z){
		x = _x;
		y = _y;
		z = _z;
	}
	mez multi(int n){
		return mez(x*n,y*n,z*n);
	}
	mez unitario(){
		return mez(x?x/x:0, y?y/y:0,z?z/z:0);
	}
	bool igual(mez o){
		return (x==o.x && y==o.y && z==o.z);
	}
	bool esMultiplo(mez other){
		if(!unitario().igual(other.unitario()))return false;
		double a = 0, b = 0, c = 0;

		if(x)a = (double)other.x/x;
		if(y)b = (double)other.y/y;
		if(z)c = (double)other.z/z;

		vector<double> tmp;
		if(a)tmp.push_back(a);
		if(b)tmp.push_back(b);
		if(c)tmp.push_back(c);

		for(int i = 1; i < (int)tmp.size(); i++)
			if(tmp[i]!=tmp[i-1])
				return false;
		return true;
	}
	int multiplicidad(mez other){
		if(x)
			return other.x/x;
		if(y)
			return other.y/y;
		if(z)
			return other.z/z;
		return 0;
	}
};
mez sumar(mez a, mez b , mez c){
	return mez(a.x+b.x+c.x, a.y+b.y+c.y, a.z+b.z+c.z);
}
mez obj;
mez pro[3];
int main() {
	ifstream cin("ratios.in");
	ofstream cout("ratios.out");
	cin >> obj.x >> obj.y>> obj.z;
	for(int i = 0; i < 3; i++)
		cin >> pro[i].x >>pro[i].y >>pro[i].z;
	mez A,B,C, suma;
	int a,b,c,m;
	a = b = c = 400;

	for(int i = 0; i <= 100; i++){
		A = pro[0].multi(i);
		for(int j = 0; j <= 100; j++){
			B = pro[1].multi(j);
			for(int k = 0; k <= 100; k++){
				C = pro[2].multi(k);
				suma = sumar(A,B,C);
				if(obj.esMultiplo(suma) && obj.multiplicidad(suma))
					if(i+j+k < a+b+c){
						a = i;
						b = j;
						c = k;
						m = obj.multiplicidad(suma);
					}
			}
		}
	}
	if(a!=400)
		cout << a << " "<<b << " "<<c << " "<< m<<endl;
	else
		cout << "NONE"<<endl;
	return 0;
}
