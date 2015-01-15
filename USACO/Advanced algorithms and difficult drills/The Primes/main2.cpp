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
void generatePrimes(){
  fill(cribe, cribe + MAX, true);
  cribe[0] = cribe[1] = false;

  for(int i = 4; i < MAX; i += 2)
    cribe[i] = false;

  for(int i = 3; i * i < MAX; i += 2)
    if(cribe[i])
      for(int j = i + i; j < MAX; j += i)
        cribe[j] = false;
  //  int add = 0;
  for(int i = 10000; i <= MAX; i++)
    if(cribe[i]){
      
      int dig = 0, sum = 0, cp = i;
      while(cp){
        sum += (cp % 10);
        cp /= 10;
      }
      if(sum != total)continue;
      sum = 0;
      cp = i;
      while(cp){
        dig = cp % 10;
        sum += dig;
        cp /= 10;
        if(cp){
          assert(cp < MAXP);
          p[cp][sum].push_back(i);
          // add++;
        }
      }
    }
  //  cout << "adicionado = " << add << endl;
}
int ans[5][5];
int d, dig, i, j, k, l, m, n, o, q, r, s, f, c;
int ini1, ini2, ini3, ini4, ini5, ini6, ini7, ini8, ini9;
int sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9;
int diag1, diag2, s1, s2;
int main(){
  //freopen("prime3.in", "r", stdin);
  //freopen("prime3.out", "w", stdout);
  int sum, ini;
  cin >> sum >> ini;
  total = sum;
  generatePrimes();
  int cant = 0;
  int sum1 = sum - ini;
  int tmp;
  bool none = true;
  bool zero;
  vector<pair<Number, Number> > answers;
  Number right, left;
  if(sum1 >= 0){
    for(i = 0; i < p[ini][sum1].size(); i++){
      tmp = p[ini][sum1][i];
      zero = false;
      for(d = 4; d >= 0 && !zero; d--){
        dig = tmp % 10;
        zero = (dig == 0);
        ans[0][d] = dig;
        tmp /= 10;
      }
      if(zero)continue;
      for(j = 0; j < p[ini][sum1].size(); j++){
        tmp = p[ini][sum1][j];
        zero = false;
        for(d = 4; d >= 1 && !zero; d--){
          dig = tmp % 10;
          zero = (dig == 0);
          ans[d][0] = dig;
          tmp /= 10;
        }
        if(zero) continue;
        ini2 = ans[1][0];
        sum2 = sum - ans[1][0];
        if(sum2 >= 0){
          for(k = 0; k < p[ini2][sum2].size(); k++){
            tmp = p[ini2][sum2][k];
            for(d = 4; d >= 1; d--){
              ans[1][d] = tmp % 10;
              tmp /= 10;
            }
            ini3 = ans[0][1] * 10 + ans[1][1];
            sum3 = sum - ans[0][1] - ans[1][1];
            if(sum3 >= 0){
              for(l = 0; l < p[ini3][sum3].size(); l++){
                tmp = p[ini3][sum3][l];
                for(d = 4; d >= 2; d--){
                  ans[d][1] = tmp % 10;
                  tmp /= 10;
                }
                ini4 = ans[2][0] * 10 + ans[2][1];
                sum4 = sum - ans[2][0] - ans[2][1];
                if(sum4 >= 0){
                  for(m = 0; m < p[ini4][sum4].size(); m++){
                    tmp = p[ini4][sum4][m];
                    for(d = 4; d >= 2; d--){
                      ans[2][d] = tmp % 10;
                      tmp /= 10;
                    }
                    ini5 = ans[0][2] * 100 + ans[1][2] * 10 + ans[2][2];
                    sum5 = sum - ans[0][2] - ans[1][2] - ans[2][2];
                    if(sum5 >= 0){
                      for(n = 0; n < p[ini5][sum5].size(); n++){
                        tmp = p[ini5][sum5][n];
                        for(d = 4; d >= 3; d--){
                          ans[d][2] = tmp % 10;
                          tmp /= 10;
                        }
                        ini6 = ans[3][0] * 100 + ans[3][1] * 10 + ans[3][2];
                        sum6 = sum - ans[3][0] - ans[3][1] - ans[3][2];
                        if(sum6 >= 0){
                          for(o = 0; o < p[ini6][sum6].size(); o++){
                            tmp = p[ini6][sum6][o];
                            for(d = 4; d >= 3; d--){
                              ans[3][d] = tmp % 10;
                              tmp /= 10;
                            }
                            ini7 = ans[0][3] * 1000 + ans[1][3] * 100 + ans[2][3] * 10 + ans[3][3];
                            sum7 = sum - ans[0][3] - ans[1][3] - ans[2][3] - ans[3][3];
                            if(sum7 >= 0){
                              for(q = 0; q < p[ini7][sum7].size(); q++){
                                tmp = p[ini7][sum7][q];
                                for(d = 4; d >= 4; d--){
                                  ans[d][3] = tmp % 10;
                                  tmp /= 10;
                                }
                                ini8 = ans[4][0] * 1000 + ans[4][1] * 100 + ans[4][2] * 10 + ans[4][3];
                                sum8 = sum - ans[4][0] - ans[4][1] - ans[4][2] - ans[4][3];
                                if(sum8 >= 0){
                                  for(r = 0; r < p[ini8][sum8].size(); r++){
                                    tmp = p[ini8][sum8][r];
                                    for(d = 4; d >= 4; d--){
                                      ans[4][d] = tmp % 10;
                                      tmp /= 10;
                                    }
                                    ini9 = 0;
                                    for(s = 0; s < 5; s++)
                                      ini9 = ini9 * 10 + ans[s][4];
                                    if(cribe[ini9] == false) continue;
                                    //----------------------------------------------
                                    diag1 = 0, diag2 = 0;
                                    s1 = 0, s2 = 0;
                                    for(s = 0; s < 5; s++){
                                      diag1 = diag1 * 10 + ans[s][s];
                                      diag2 = diag2 * 10 + ans[4 - s][s];
                                      s1 += ans[s][s];
                                      s2 += ans[4 - s][s];
                                    }
                                    if(cribe[diag1] && cribe[diag2] && s1 == sum && s2 == sum){                                     
                                      right = left = 0;
                                      for(f = 0; f < 3; f++)
                                        for(c = 0; c < 5; c++)
                                          left = left * 10LL + ans[f][c];
                                      for(f = 3; f < 5; f++)
                                        for(c = 0; c < 5; c++)
                                          right = right * 10LL + ans[f][c];
                                      answers.push_back(make_pair(left, right));       
                                    }
                                    //----------------------------------------------
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  
  if(answers.size()){
    sort(answers.begin(), answers.end());
    Number ten = Number(1e10);
    Number five = Number(1e5);
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
  }else
    cout << "NONE" << endl;  
  
  return 0;
}
