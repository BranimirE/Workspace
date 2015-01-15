#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long int Number;
string c;
string ord;
int v[10], n;
Number fact(Number a){
  Number ans = 1;
  for(Number i = 2; i <= a; i++)
    ans *= i;
  return ans;
}
Number solve(int tam){// tam! / a! b! ... c!
  Number num = fact(tam);
  for(int i = 0; i < 10; i++)
    num /= fact(v[i]);
  return num;
}
Number calcular(){
  Number ans = 0;
  for(int i = 0; i < n - 1; i++){
    int j = 0;
    while(c[i] != ord[j]){
      int cabeza = ord[j] - '0';
      if(v[cabeza]){//Ini de permutacion
        v[cabeza] -= 1;
         ans += solve(n - i - 1);//Cuantas permutaciones????
        v[cabeza] += 1;
      }
      j++;
    }   
    v[c[i] - '0']--;
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> c;
    memset(v, 0, sizeof(v));
    n = c.size();
    for(int i = 0; i < n; i++)
      v[c[i] - '0']++;
    string tmp = c;
    sort(tmp.begin(), tmp.end());
    ord = "";
    ord = ord + tmp[0];
    for(int i = 1; i < tmp.size(); i++)
      if(tmp[i] != tmp[i - 1])
        ord += tmp[i];
    cout << calcular() + 1 << endl;
  }  
  return 0;
}
