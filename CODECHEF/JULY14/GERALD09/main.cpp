#include <bits/stdc++.h>
typedef long long int Number;
using namespace std;
int n, m, k;
char genome[10] = "GCAT";
int vec[17][17];
int bestvec[17][17];
int bestans;
int testpercase;
void generate(){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      vec[i][j] = rand() % 4;
}
int count(){
  set<pair<pair<int,int>, Number> > s;
  int ans = 0;
  for(int i1 = 0; i1 < n; i1++)
    for(int i2 = i1; i2 < n; i2++)
      for(int j1 = 0; j1 < m; j1++)
        for(int j2 = j1; j2 < m; j2++){
          Number hash = 0;
          Number power = 0;
          for(int i = i1; i <= i2; i++)
            for(int j = j1; j <= j2; j++){
              hash += vec[i][j] * pow(4, power);
              power++;
            }
          int with = j2 - j1 + 1;
          int height = i2 - i1 + 1;
          pair<pair<int,int>, Number> element = make_pair(make_pair(with, height), hash);
          if(!s.count(element)){
            ans++;
            s.insert(element);
          }
        }
  return ans;
}
void backupvec(){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      bestvec[i][j] = vec[i][j];
}
int main(){
  testpercase = 2;
  srand(time(0));
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d%d", &n, &m, &k);
    bestans = INT_MAX;
    memset(bestvec, 0, sizeof(bestvec));
    int tpc = testpercase;
    while(tpc--){
      generate();
      int diff = count();
      if(diff < abs(bestans - k)){
        bestans = diff;
        backupvec();
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
        printf("%c", genome[bestvec[i][j]]);
      printf("\n");
    }
  }
  return 0;
}
