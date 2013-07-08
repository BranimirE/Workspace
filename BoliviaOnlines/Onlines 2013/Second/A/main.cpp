#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define INF 1<<30
#define MAXN 100100

#define PI acos(-1)

using namespace std;

struct Rect{
	long long int x1,y1, x2,y2;
	long long int area;
	Rect(long long int _x1, long long int _y1, long long int _x2, long long int _y2){
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		getArea();
	}
	long long int getArea(){
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
int main(){
	int t,n, x,y;
	cin >> t;
	vector<Rect> r;
	while(t--){
		cin >> n;
		r.clear();
		r.push_back(Rect(0,0, 1000000,1000000));
		while(n--){
			cin >> x >> y;
			Rect tmp(0,0,x,y);
			int tam = r.size();
			for(int i = 0; i < tam; i++){
				Rect inter = interseccion(tmp,r[i]);

				if(inter.getArea()){
					Rect arr(inter.x1,inter.y2,inter.x2, r[i].y2);
					Rect der(inter.x2,r[i].y1,r[i].x2,r[i].y2);
					bool reemplazado = false;
					if(arr.getArea())
						if(reemplazado)
							r.push_back(arr);
						else{
							r[i] = arr;
							reemplazado = true;
						}
					if(der.getArea())
						if(reemplazado)
							r.push_back(der);
						else{
							r[i] = der;
							reemplazado = true;
						}
				}
			}
		}
//		cout << "rectangulos"<<endl;
//		for(int i = 0; i < r.size(); i++)
//			cout << r[i].x1 << " "<<r[i].y1<<" "<<r[i].x2<<" "<<r[i].y2<< " area = " <<r[i].getArea()<<endl;

		unsigned long long int nd = 0;
		for(int i = 0; i < r.size(); i++)
			nd += r[i].getArea();
		long long int ans = ((long long int)1000000*(long long int)1000000)-nd;
		cout << ans << endl;
	}
	return 0;
}
/*
2
3
1 3 1 6 1 4
4
1 6 3 4 4 3 6 1

 */

