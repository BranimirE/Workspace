#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int rdtsc(){
  __asm__ __volatile__("rdtsc");
}
int main(){
  srand(rdtsc());
  int casos = 15;
  cout << casos << endl;
  int n = 100000;
  while(casos--){
    n = rand() % 100001;
    cout << n << endl;
    for(int i = 0; i < n; i++){
      int signo = rand() % 2;
      if(signo == 0)
        cout << " "<< -1;
      else
        cout << " " << 1;
    }
    cout << endl;
  }
  return 0;
}
