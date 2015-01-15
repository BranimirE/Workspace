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
      int dig = 0, sum = 0, cp = i, ini = i / 10000, niv = 4;
      while(cp){
        sum += (cp % 10);
        cp /= 10;
      }
      if(sum != total)continue;
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
  //freopen("prime3.in", "r", stdin);
  //freopen("prime3.out", "w", stdout);
  int sum, ini;
  cin >> sum >> ini;
  total = sum;
  generatePrimes();
  if(sum < ini){
    cout << "NONE" << endl;
    return 0;
  }
  vector<pair<Number, Number> > answers;
  Number right, left;
  int tmp,d,  A, B, C, D, E, F, sa, sb, sc, sd, se, sf, f, c;
  vector<int> &root = p[ini][sum - ini];
  bool invalid;
  bool none = true;
  for(int i = 0; i < root.size(); i++){
    tmp = root[i];
    invalid = false;
    for(d = 4; d >= 0 && !invalid; d--){
      ans[0][d] = tmp % 10, tmp /= 10;
      invalid = ans[0][d] == 0;
    }
    if(invalid)continue;
    for(int j = 0; j < root.size(); j++){
      tmp = root[j];
      invalid = false;
      for(d = 4; d >= 0 && !invalid; d--){
        ans[d][0] = tmp % 10, tmp /= 10;
        invalid = ans[d][0] == 0;
      }
      if(invalid) continue;

      for(int k = 0; k < root.size(); k++){
        tmp = root[k];
        for(d = 4; d >= 0; d--)
          ans[d][d] = tmp % 10, tmp /= 10;

        bool possible = true;
        for(int niv = 4; niv >= 1 && possible; niv--)
          possible = inifin[niv][ans[0][niv]][ans[niv][niv]] && inifin[niv][ans[niv][0]][ans[niv][niv]];
        if(possible == false)continue;

          A = ans[1][0] * 10 + ans[1][1]; sa = sum - ans[1][0] - ans[1][1];
          
        
          for(int q = 0; q < p[A][sa].size(); q++){

            tmp = p[A][sa][q];
        
            for(d = 4; d >= 2; d--)
              ans[1][d] = tmp % 10, tmp /= 10;
            
            B = ans[0][1] * 10 + ans[1][1]; sb = sum - ans[0][1] - ans[1][1];
        
            for(int r = 0; r < p[B][sb].size(); r++){
              tmp = p[B][sb][r];
        
              for(d = 4; d >= 2; d--)
                ans[d][1] = tmp % 10, tmp /= 10;
              
              C = ans[2][0] * 100 + ans[2][1] * 10 + ans[2][2]; sc = sum - ans[2][0] - ans[2][1] - ans[2][2];

              for(int s = 0; s < p[C][sc].size(); s++){
                tmp = p[C][sc][s];

                for(d = 4; d >= 3; d--)
                  ans[2][d] = tmp % 10, tmp /= 10;
                
                D = ans[0][2] * 100 + ans[1][2] * 10 + ans[2][2]; 
                sd = sum - ans[0][2] - ans[1][2] - ans[2][2];

                for(int t = 0; t < p[D][sd].size(); t++){
                  tmp = p[D][sd][t];
                  for(d = 4; d >= 3; d--)
                    ans[d][2] = tmp % 10, tmp /= 10;          
                  
                  E = ans[3][0] * 1000 + ans[3][1] * 100 + ans[3][2] * 10 + ans[3][3];
                  se = sum - ans[3][0] - ans[3][1] - ans[3][2] - ans[3][3];
                  for(int u = 0; u < p[E][se].size(); u++){
                    tmp = p[E][se][u];
                    for(d = 4; d >= 4; d--)
                      ans[3][d] = tmp % 10, tmp /= 10;                  
                    
                    F = ans[0][3] * 1000 + ans[1][3] * 100 + ans[2][3] * 10 + ans[3][3];
                    sf = sum - ans[0][3] - ans[1][3] - ans[2][3] - ans[3][3];
                    for(int v = 0; v < p[F][sf].size(); v++){
                      tmp = p[F][sf][v];
                      for(d = 4; d >= 4; d--)
                        ans[d][3] = tmp % 10, tmp /= 10;                  
                        
                      //--------------------------------------------------------------------
                      int diag = 0, sumdiag = 0;
                      int first = 0, sumfirst = 0;
                      int second = 0, sumsecond = 0;
                      
                      for(int w = 0; w < 5; w++){
                        diag = diag * 10 + ans[4 - w][w]; sumdiag += ans[4 -w][w];
                        first = first * 10 + ans[4][w]; sumfirst += ans[4][w];
                        second = second * 10 + ans[w][4]; sumsecond += ans[w][4];
                      }
                      if(cribe[diag] && cribe[first] && cribe[second] && sumdiag == sum && sumfirst == sum && sumsecond == sum){
                        right = left = 0;
                        for(f = 0; f < 3; f++)
                          for(c = 0; c < 5; c++)
                            left = left * 10LL + ans[f][c];
                        for(f = 3; f < 5; f++)
                          for(c = 0; c < 5; c++)
                            right = right * 10LL + ans[f][c];
                        answers.push_back(make_pair(left, right));
                      }
                      //--------------------------------------------------------------------
                    }
                  }
                }             
              }
            }
          }
        }
      }
    }
  //  }
  sort(answers.begin(), answers.end());
  Number ten = Number(1e10);
  Number five = Number(1e5);
  if(answers.size()){
    for(int i = 0; i < answers.size(); i++){
      if(i) cout << endl;
      left = answers[i].first;
      right = answers[i].second;
      cout << left / ten << endl;
      cout << (left % ten) / five << endl;
      cout << left % five << endl;
      cout << right / five << endl;
      cout << right % five << endl;
    }
    //cout << "numero de soluciones " << answers.size() << endl;
  }else
    cout << "NONE" << endl;  
  return 0;
}
