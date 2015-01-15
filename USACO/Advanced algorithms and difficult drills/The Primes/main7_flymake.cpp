/*
 ID: brani.e2
 PROG: prime3
 LANG: C++
*/
#include <bits/stdc++.h>

#define MAX 99999
#define MAXP 10000
#define MS 45
using namespace std;
typedef long long int Number;
bool cribe[MAX + 10];
vector<int> p[MAXP][MS];//[INI][SUM]
int total = 0;
bool inifin[5][10][10];
vector<int> IMF[10][10][10], IF[10][10], IIFF[100][100], M[10], IIM[100][10], MMM[1000];

void generatePrimes(){
  fill(cribe, cribe + MAX, true);
  cribe[0] = cribe[1] = false;

  for(int i = 4; i < MAX; i += 2)
    cribe[i] = false;

  for(int i = 3; i * i < MAX; i += 2)
    if(cribe[i])
      for(int j = i + i; j < MAX; j += i)
        cribe[j] = false;
  memset(inifin, false, sizeof(inifin));
  for(int i = 10000; i <= MAX; i++)
    if(cribe[i]){
      int dig = 0, sum = 0, cp = i, niv = 4;
      while(cp){
        sum += (cp % 10);
        cp /= 10;
      }
      if(sum != total)continue;

      int ini = i / 10000, mid = (i / 100) % 10, fin = i % 10;
      int iini = i / 1000, ffin = i % 100;
      IMF[ini][mid][fin].push_back(i);
      IF[ini][fin].push_back(i);
      IIFF[iini][ffin].push_back(mid);
      M[mid].push_back(i);
      IIM[iini][(i / 10) % 10].push_back(i);
      MMM[(i % 10000) / 10].push_back(i);
      sum = 0;
      cp = i;
      while(cp){
        dig = cp % 10;
        inifin[niv--][ini][dig] = true;
        sum += dig;
        cp /= 10;
        if(cp)
          p[cp][sum].push_back(i);
      }
    }
}
int ans[5][5];

int main(){
  freopen("prime3.in", "r", stdin);
  freopen("prime3.out", "w", stdout);
  int sum, ini;
  cin >> sum >> ini;
  total = sum;
  generatePrimes();
  if(sum < ini){
    cout << "NONE" << endl;
    return 0;
  }
  vector<pair<Number, Number> > answers;
  int tmp,d,  A, B, C, D, E, F, sa, sb, sc, sd, se, sf, f, c;  
  bool invalid;
  bool none = true;

  vector<int> &maindiag = p[ini][sum - ini];  
  for(int i = 0; i < maindiag.size(); i++){
    tmp = maindiag[i];
    for(d = 4; d >= 0; d--)
      ans[d][d] = tmp % 10, tmp /= 10;
    
    vector<int> &seconddiag = M[ans[2][2]];
    for(int j = 0; j < seconddiag.size(); j++){
      tmp = seconddiag[j];
      for(d = 4; d >= 0; d--)
        ans[4 - d][d] = tmp % 10, tmp /= 10;
      
      vector<int> &top = IF[ans[0][0]][ans[0][4]];
      for(int k = 0; k < top.size(); k++){
        tmp = top[k];
        invalid = false;
        for(d = 4; d >= 1 && !invalid; d--){
          ans[0][d] = tmp % 10, tmp /= 10;
          invalid = ans[0][d] == 0;
        }
        if(invalid) continue;

        vector<int> &secondcol = IIM[ans[0][1] * 10 + ans[1][1]][ans[3][1]];
        for(int l = 0; l < secondcol.size(); l++){
          tmp = secondcol[l];
          ans[2][1] = (tmp / 100) % 10;
          ans[4][1] = tmp % 10;

          vector<int> &fourthcol = IIM[ans[0][3] * 10 + ans[1][3]][ans[3][3]];
          for(int m = 0; m < fourthcol.size(); m++){
            tmp = fourthcol[m];
            ans[2][3] = (tmp / 100) % 10;
            ans[4][3] = tmp % 10;
            
            vector<int> &bottom = IIFF[ans[4][0] * 10 + ans[4][1]][ans[4][3] * 10 + ans[4][4]];
            for(int n = 0; n < bottom.size(); n++){
              ans[4][2] = bottom[n];

              vector<int> &thirthcol = IMF[ans[0][2]][ans[2][2]][ans[4][2]];
              for(int o = 0; o < thirthcol.size(); o++){
                tmp = thirthcol[o];
                ans[1][2] = (tmp / 1000) % 10;
                ans[3][2] = (tmp / 10) % 10;
                

                vector<int> &secondrow = MMM[ans[1][1] * 100 + ans[1][2] * 10 + ans[1][3]];
                for(int q = 0; q < secondrow.size(); q++){
                  tmp = secondrow[q];
                  ans[1][0] = tmp / 10000;
                  ans[1][4] = tmp % 10;

                  vector<int> &thirthrow = MMM[ans[2][1] * 100 + ans[2][2] * 10 + ans[2][3]];
                  for(int r = 0; r < thirthrow.size(); r++){
                    tmp = thirthrow[r];
                    ans[2][0] = tmp / 10000;
                    ans[2][4] = tmp % 10;

                    vector<int> &fourthrow = MMM[ans[3][1] * 100 + ans[3][2] * 10 + ans[3][3]];
                    for(int s = 0; s < fourthrow.size(); s++){
                      tmp = fourthrow[s];
                      ans[3][0] = tmp / 10000;
                      ans[3][4] = tmp % 10;

                      Number right, left, sumright, sumleft;
                      right = left = sumright = sumleft = 0;
                      for(d = 0; d < 5; d++){
                        right = right * 10 + ans[d][4];
                        sumright += ans[d][4];
                        left = left * 10 + ans[d][0];
                        sumleft += ans[d][0];
                      }
                      if(cribe[right] && cribe[left] && sumright == sum && sumleft == sum){

    }
    //cout << "numero de soluciones " << answers.size() << endl;
  }else
    cout << "NONE" << endl;  
  return 0;
}
