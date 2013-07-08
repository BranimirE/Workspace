/*
ID: brani.e2
PROG: spin
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;
struct Rueca{
	int velocidad;
	int nmarcas;
	vector<int> tam,angulo;
};
Rueca r[5];
int v[360];
void interseccion(int &ax,int &ay, int bx,int by){
	int a=0, b=0,Mx,My,mx,my;
	ay += ax;
	by += bx;
	if((ay<360 && by<360) || (ay>=360 && by>=360)){//caso normal como si fueran rectas
		a = max(ax,bx);
		b = min(ay,by);
		if(a<=b){
			ax = a;
			ay = b - a;
		}else{//no hay interseccion
			ax = 0;
			ay = -1;
		}
		return ;
	}else
	if(by >= 360 && ay < 360){
		Mx = bx; My = by;
		mx = ax; my = ay;
	}else
	if(ay >= 360 && by < 360){
		Mx = ax; My = ay;
		mx = bx; my = by;
	}

	if(My%360 >= mx){
		a = mx;
		b = min(My%360,my);
	}else{
		a = max(Mx,mx);
		b = my;
	}
	if(a<=b){
		ax = a;
		ay = b - a;
	}else{//no hay interseccion
		ax = 0;
		ay = -1;
	}
}

bool estanAlineadas(){
	int ang,tam;
	for(int a = 0; a < r[0].nmarcas; a++){
		ang = r[0].angulo[a];tam = r[0].tam[a];
		for(int b = 0; b < r[1].nmarcas; b++){
			interseccion(ang,tam,r[1].angulo[b], r[1].tam[b]);
			if(tam != -1 )
				for(int c = 0; c < r[2].nmarcas; c++){
					interseccion(ang,tam,r[2].angulo[c], r[2].tam[c]);
					if(tam != -1)
						for(int d = 0; d < r[3].nmarcas; d++){
							interseccion(ang,tam,r[3].angulo[d], r[3].tam[d]);
							if(tam != -1)
								for(int e= 0; e < r[4].nmarcas; e++){
									interseccion(ang,tam,r[4].angulo[e], r[4].tam[e]);
									if(tam != -1 )return true;
								}
						}
				}
		}
	}
	return false;
}
bool verificar(){
	memset(v,0,sizeof v);
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < r[i].nmarcas; j++){
			int a = r[i].angulo[j];
			int b = (r[i].angulo[j]+r[i].tam[j])%360;
			if(a<=b)
				for(int k = a; k <= b; k++)v[k]++;
			else{
				for(int k = 0; k<=b; k++)v[k]++;
				for(int k = a; k<=359;k++)v[k]++;
			}
		}
	}
	for(int i = 0; i < 360; i++)
		if(v[i]>=5)return true;
	return false;
}
void avanzarseg(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < r[i].nmarcas; j++){
			r[i].angulo[j]+=r[i].velocidad;
			r[i].angulo[j]%=360;
		}
	}
}
int main(){
	ifstream cin("spin.in");
	ofstream cout("spin.out");
	for(int i = 0; i < 5; i++){
		cin >> r[i].velocidad >> r[i].nmarcas;
		for(int j = 0; j < r[i].nmarcas; j++){
			int ang,dist;
			cin >> ang >> dist;
			r[i].angulo.push_back(ang);
			r[i].tam.push_back(dist);
		}
	}
	int sol = 0, lim = 5*360 + 1;

	while(!verificar() && sol < lim){//&& sol < 10){
		sol++;
		avanzarseg();
	}
	if(sol== lim)
		cout << "none"<<endl;
	else
		cout << sol << endl;
	return 0;
}
