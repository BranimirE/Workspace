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
vector<int> IMF[10][10][10], IF[10][10], IIFF[100][100];

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
  Number right, left;
  int tmp,d,  A, B, C, D, E, F, sa, sb, sc, sd, se, sf, f, c;
  
  int begin, mid, end, sumtmp;
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
      if(inifin[ans[4][0]][ans[0][4]] == false) continue;

      for(int k = 0; k < root.size(); k++){
        tmp = root[k];
        for(d = 4; d >= 0; d--)
          ans[d][d] = tmp % 10, tmp /= 10;

        bool possible = true;
        for(int niv = 4; niv >= 1 && possible; niv--)
          possible = inifin[niv][ans[0][niv]][ans[niv][niv]] && inifin[niv][ans[niv][0]][ans[niv][niv]];
        if(possible == false)continue;

        vector<int> &diagonal = IMF[ans[4][0]][ans[2][2]][ans[0][4]];

        for(int q = 0; q < diagonal.size(); q++){
          ans[3][1] = (diagonal[q]/1000) % 10;
          ans[1][3] = (diagonal[q]/10) % 10;

          vector<int> &bottom = IF[ans[4][0]][ans[4][4]];
          for(int r = 0; r < bottom.size(); r++){
            tmp = bottom[r];
            for(d = 4; d >= 1; d--)
              ans[4][d] = tmp % 10, tmp /= 10;
            
            vector<int> &rightside = IF[ans[0][4]][ans[4][4]];
            for(int s = 0; s < rightside.size(); s++){
              tmp = rightside[s];
              for(d = 4; d >= 1;d--)
                ans[d][4] = tmp % 10, tmp /= 10;
              
              vector<int> &mid1 = IIFF[ans[1][0] * 10 + ans[1][1]][ans[1][3] * 10 + ans[1][4]];
              for(int t = 0; t < mid1.size(); t++){
                ans[1][2] = mid1[t];
                vector<int> &mid2 = IIFF[ans[3][0] * 10 + ans[3][1]][ans[3][3] * 10 + ans[3][4]];
                for(int u = 0; u < mid2.size(); u++){
                  ans[3][2] = mid2[u];
                  
                  tmp = 0, sumtmp = 0;
                  for(d = 0; d < 5; d++)
                    tmp = tmp * 10 + ans[d][2], sumtmp += ans[d][2];
                  
                  if(cribe[tmp] == false || sumtmp != sum)continue;

                  vector<int> &mid3 = IIFF[ans[0][1] * 10 + ans[1][1]][ans[3][1] * 10 + ans[4][1]];
                  for(int v = 0; v < mid3.size(); v++){
                    ans[2][1] = mid3[v];
                    vector<int> &mid4 = IIFF[ans[0][3] * 10 + ans[1][3]][ans[3][3] * 10 + ans[4][3]];
                    for(int w = 0; w < mid4.size(); w++){
                      ans[2][3] = mid4[w];
                      
                      tmp = 0, sumtmp = 0;
                      for(d = 0; d < 5; d++)
                        tmp = tmp * 10 + ans[2][d] , sumtmp += ans[2][d];

                      if(cribe[tmp] && sumtmp == sum){
                        //--------------------------------------------------------------------
                        right = left = 0;
                        for(f = 0; f < 3; f++)
                          for(c = 0; c < 5; c++)
                            left = left * 10LL + ans[f][c];
                        for(f = 3; f < 5; f++)
                          for(c = 0; c < 5; c++)
                            right = right * 10LL + ans[f][c];
                        answers.push_back(make_pair(left, right));
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
