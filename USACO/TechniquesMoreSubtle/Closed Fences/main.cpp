/*
ID: brani.e2
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
#define EPS 1e-8
#define EPS2 1e-7
struct Point{
	double x,y;
	int pos;
	Point(){}
	Point(double a, double b){x=a; y=b;}
	string toStr(){
		stringstream ss;
		ss << x <<" "<<y;
		return ss.str();
	}
};
Point operator +(const Point &A, const Point &B){return Point(A.x+B.x,A.y+B.y);}
Point operator -(const Point &A, const Point &B){return Point(A.x-B.x,A.y-B.y);}
Point operator *(const Point &A, double k){return Point(A.x/k,A.y/k);}
Point operator /(const Point &A, double k){return Point(A.x*k,A.y*k);}
double cross(const Point &A, const Point &B){return A.x*B.y-A.y*B.x;}
double area(const Point &A, const Point &B, const Point &C){return cross(B-A,C-A);}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D){
	return A + (B - A)*(cross(C-A,D-C)/cross(B-A,D-C));
}
bool onSegment(const Point &A, const Point &B, const Point &P){
	return abs(area(A,B,P))<EPS && 
		P.x >= min(A.x, B.x) && P.x <= max(A.x, A.y) &&
		P.y >= min(A.y, B.y) && P.y <= max(A.y, A.y);
}
bool onSameLine(const Point &A, const Point &B, const Point &P){
	return abs(area(A,B,P)) < EPS;
}
bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4){
	double A1 = area(P3, P4, P1);
	double A2 = area(P3, P4, P2);
	double A3 = area(P1, P2, P3);
	double A4 = area(P1, P2, P4);

	if( ((A1>0 && A2<0) || (A1<0 && A2>0)) &&
	    ((A3>0 && A4<0) || (A3<0 && A4>0)))
		return true;
	//else if(A1 == 0 && onSegment(P3, P4, P1))return true;
	//else if(A2 == 0 && onSegment(P3, P4, P2))return true;
	//else if(A3 == 0 && onSegment(P1, P2, P3))return true;
	//else if(A4 == 0 && onSegment(P1, P2, P4))return true;
	else return false;
}

#define MAXN 200

Point v[MAXN], obs;
int n;

void reducir(Point &a, Point &b){
	if(a.x != b.x)
		if(a.x < b.x){
			a.x += EPS2;
			b.x -= EPS2;
		}else{
			a.x -= EPS2;
			b.x += EPS2;
		}
	if(b.y != a.y)
		if(a.y < b.y){
			a.y += EPS2;
			b.y -= EPS2;
		}else{
			a.y -= EPS2;
			b.y += EPS2;
		}
}
bool cmp(pair<Point,Point> a, pair<Point,Point> b){
	if(a.second.pos == b.second.pos)return a.first.pos < b.first.pos;
	return a.second.pos < b.second.pos;
}

int main(){
	ifstream cin("fence4.in");
	ofstream cout("fence4.out");
	
	cin >> n;
	cin >> obs.x >> obs.y;
	for(int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].y ;
		v[i].pos = i;
	}
	bool valid = true;
	Point A,B,C,D;
	for(int i = 0; i < n && valid; i++){
		A = v[i];
		B = v[(i+1)%n];
		for(int j = i ; j < n && valid; j++){
			C = v[j];
			D = v[(j+1)%n];
			if(i!=j && intersects(A,B, C,D))
				valid = false;
		}
	}
	if(valid){
		vector<pair<Point,Point> > salida;
		for(int i = 0; i < n; i++){
			A = v[i];
			B = v[(i+1)%n];
			if(!onSameLine(A,B,obs)){
				reducir(A,B);
				bool swA = true;
				bool swB = true;
				for(int j = 0; j < n; j++){
					C = v[j];
					D = v[(j+1)%n];
					if( i != j){
						swA &= !intersects(obs,A,C,D);
						swB &= !intersects(obs,B,C,D);
					}

				}
				if(!(swA==false && swB==false)){
					salida.push_back(make_pair(v[min(i, (i+1)%n)],v[max(i,(i+1)%n)]));

				}
			}

		}
		sort(salida.begin(), salida.end(),cmp);
		cout << salida.size() << endl;
		for(int i = 0; i < salida.size(); i++)
			cout << salida[i].first.toStr() << " " << salida[i].second.toStr() << endl;

	}
	else{
		cout << "NOFENCE"<<endl;
	}
	return 0;
}
