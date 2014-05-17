#include <iostream>
#include <vector>
using namespace std;
typedef long long int Number;
int n;
Number v[100005];
vector<int> p;
bool check(int i, int j){
  int negatives = j - i + 1;
  int positives = (p[j] - p[i] + 1) - negatives;
  int prev = p[i] - p[i - 1] - 1;
  int next = p[j + 1] - p[j] - 1;
  return (negatives == positives || (positives < negatives && ((positives + prev + next) >= negatives)));
}
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n;
    int neg, pos;
    neg = 0;
    pos = 0;
    for(int i = 1; i <= n; i++){
      cin >> v[i];
      if(v[i] < 0)
        neg++;
      else
        pos++;
    }
    p.clear();
    p.push_back(0);
    if(neg < pos){
      for(int i = 1; i <= n; i++)
        if(v[i] < 0)
          p.push_back(i);
    }
    else{
      for(int i = 1; i <= n; i++)
        if(v[i] > 0)
          p.push_back(i);
    }
    p.push_back(n + 1);
    int ans = 0;
    for(int i = 1; i < p.size() - 1; i++)
      for(int j = i + ans; j < p.size() - 1; j++)
        if(check(i, j))
          ans = j - i + 1;
    cout << ans*2 << endl;
  }
  return 0;
}
