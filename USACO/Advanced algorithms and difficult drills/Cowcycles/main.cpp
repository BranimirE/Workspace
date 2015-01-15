/*
 ID: brani.e2
 PROG: cowcycle
 LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int f, r;
int f1, f2, r1, r2;
double F[5], R[10], ansF[5], ansR[10];
double razon[55];
double dif[55];
double ans;
double calculate(){
  int n = 0;
  double mini = INT_MAX, maxi = -INT_MAX;
  for(int i = 0; i < f; i++)
    for(int j = 0; j < r; j++){
      razon[n] = F[i] / R[j];
      mini = min(mini, razon[n]);
      maxi = max(maxi, razon[n]);
      n++;
    }
  if(maxi >= (3.0 * mini)){
    sort(razon, razon + n);
    
    if(n == 1){
      dif[0] = razon[0];
    }else{
      for(int i = 0; i < n - 1; i++)
        dif[i] = razon[i + 1] - razon[i];
      n--;
    }
    double varianza = 0;
    double mediana = 0;
    for(int i = 0; i < n; i++){
      mediana += dif[i];
      varianza += (dif[i] * dif[i]);
    }
    mediana /= double(n);
    varianza /= double(n);
    varianza -= (mediana * mediana);
    return varianza;
  }
  return INT_MAX;
}
void solveR(int desdeR, int hastaR, int cantR){
  if(cantR == 0){
    double varianza = calculate();
    if(varianza < ans){
      ans = varianza;
      for(int i = 0; i < f; i++)
        ansF[i] = F[i];
      for(int i = 0; i < r; i++)
        ansR[i] = R[i];
    }
    return ;
  }

  R[r - cantR] = desdeR;
  solveR(desdeR + 1, hastaR, cantR - 1);
  if((hastaR - desdeR) >= cantR)
    solveR(desdeR + 1, hastaR, cantR);
}
void solveF(int desdeF, int hastaF, int cantF){
  if(cantF == 0){
    solveR(r1, r2, r);
    return;
  }
  //Tomo el actual
  F[f - cantF] = desdeF;
  solveF(desdeF + 1, hastaF, cantF - 1);
  //No lo tomo
  if((hastaF - desdeF) >= cantF)
    solveF(desdeF + 1, hastaF, cantF);
  
}
int main(){
  freopen("cowcycle.in", "r", stdin);
  freopen("cowcycle.out", "w", stdout);
  cin >> f >> r;
  cin >> f1 >> f2 >> r1 >> r2;
  ans = INT_MAX;
  solveF(f1, f2, f);
  for(int i = 0; i < f; i++){
    if(i)cout << " ";
    cout << ansF[i];
  }
  cout << endl;

  for(int i = 0; i < r; i++){
    if(i)cout << " ";
    cout << ansR[i];
  }
  cout << endl;
  return 0;
}
