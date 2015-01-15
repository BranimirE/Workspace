#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 5010

int T[MAXN + 1];
int v[MAXN];
int N;
int lowbit(int i) {	return (i & -i);}
int sum(int i){
	int value = 0;
	for(; i > 0; i-= lowbit(i)) 
		value += T[i];
	return value;
}
int sum(int i, int j){ return i > 1 ? sum(j) - sum(i-1) : sum(j);}

void update(int i, int value){
	for(; i <= N ; i += lowbit(i))
		T[i] += value;
}
int m;
int inversiones(int a, int b){
  swap(v[a], v[b]);
  memset(T, 0, sizeof(T));
  int ans = 0;
  for(int i = 1; i <= N; i++){
    int mayores = sum(v[i] + 1, N);
    ans += mayores;
    if(ans > m) break;
    update(v[i] + 1, 1);
  }    
  swap(v[a], v[b]);
  return ans;
}
int main(){
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> v[i];

  m = N * (N - 1) / 2;
  int cant = 0;  
  for(int i = 1; i <= N; i++)
    for(int j = i + 1; j <= N; j++){
      if(v[i] > v[j]){
        int tmp = inversiones(i, j);
        if(tmp < m){
          m = tmp;
          cant = 1;
        }else if(tmp == m)
          cant++;
      }
    }
  cout << m << " " << cant << endl;
	return 0;
}
