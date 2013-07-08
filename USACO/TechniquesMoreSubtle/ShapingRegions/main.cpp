/*
ID: brani.e2
PROG: rect1
LANG: C++
 */
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
#define MAXC 2501

struct Rect{
	int x1,y1, x2,y2;
	int color;
	int area;
	Rect(int _x1, int _y1, int _x2, int _y2){
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		getArea();
	}
	int getArea(){
		if(x1>=x2 || y1>=y2)return area = 0;
		return area = (x2-x1)*(y2-y1);
	}
};

Rect interseccion(Rect t, Rect r){
	int x1,y1,x2,y2;
	x1 = max(t.x1,r.x1);
	y1 = max(t.y1,r.y1);
	x2 = min(t.x2,r.x2);
	y2 = min(t.y2,r.y2);
	Rect res(x1,y1,x2,y2);
	return res;
}

int colors[MAXC]={0};
int ancho, alto,n;
vector<Rect> r;
int main() {
	ifstream cin("rect1.in");
	ofstream cout("rect1.out");
	cin >>  ancho >> alto >> n;
	Rect ini(0,0,ancho,alto);
	ini.color = 1;
	r.push_back(ini);
	while(n--){
		Rect tmp(0,0,0,0);
		int tam = r.size(), col;
		cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2 >> col;
		tmp = interseccion(tmp,ini);
		tmp.color = col;
		tmp.getArea();
		for(int i = 0; i < tam; i++){
			Rect inter = interseccion(r[i],tmp);
			if(inter.getArea()){
				Rect arr(inter.x1,inter.y2,inter.x2, r[i].y2);arr.color = r[i].color;
				Rect aba(inter.x1, r[i].y1,inter.x2,inter.y1);aba.color = r[i].color;
				Rect izq(r[i].x1,r[i].y1,inter.x1,r[i].y2);izq.color = r[i].color;
				Rect der(inter.x2,r[i].y1,r[i].x2,r[i].y2);der.color = r[i].color;
				bool remplazado = false;
				if(arr.getArea())
					if(remplazado)
						r.push_back(arr);
					else{
						r[i] = arr;
						remplazado = true;
					}
				if(aba.getArea())
					if(remplazado)
						r.push_back(aba);
					else{
						r[i] = aba;
						remplazado = true;
					}
				if(der.getArea())
					if(remplazado)
						r.push_back(der);
					else{
						r[i] = der;
						remplazado = true;
					}
				if(izq.getArea())
					if(remplazado)
						r.push_back(izq);
					else{
						r[i] = izq;
						remplazado = true;
					}
				if(remplazado == false){
					r[i] = Rect(0,0,0,0);
				}
			}
		}
		r.push_back(tmp);
	}
	for(int i = 0; i < r.size(); i++)
		if(r[i].getArea())
			colors[r[i].color] += r[i].area ;
	int sum = 0;
	for(int i = 0; i < MAXC; i++)
		if(colors[i]){
			sum += colors[i];
			cout << i << " "<<colors[i]<<endl;
		}

	return 0;
}

