#include <bits/stdc++.h>
#define MAX 55
using namespace std;
int n;
vector<int> g[MAX];
vector<int> gt[MAX];
bool isInevitable(int u){
  
}
int main(){
  n = 0;
  while(true){
    int tmp;
    scanf("%d", &tmp);
    if(tmp == -1)
      break;
    if(tmp == -2)
      n++;
    if(tmp >= 0){
      g[n].push_back(tmp);
      gt[tmp].push_back(n);
    }
  }

  
  
  return 0;
}
