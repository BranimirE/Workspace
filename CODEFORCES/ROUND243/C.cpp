#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[220];
int n, swa;

int main(){
  cin >> n >> swa;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  vector<int> in, out;
  int ans = -2000005;
  for(int i = 0; i < n; i++){ 
    for(int j = i; j < n; j++){
      in.clear();
      out.clear();
      for(int k = 0; k < i; k++)
        out.push_back(v[k]);
      int sum = 0;
      for(int k = i; k <= j; k++){
        in.push_back(v[k]);
        sum += v[k];
      }
      for(int k = j + 1; k < n; k++)
        out.push_back(v[k]);
      sort(in.begin(), in.end());
      sort(out.begin(), out.end());
      
      int obj = min(swa, (int)min(in.size(), out.size()));
      int insize = in.size();
      int outsize = out.size();
      for(int k = 0; k <= obj; k++){
        int adi = 0, sub = 0;
        for(int l = 0; l < k; l++){
          adi += out[outsize - l - 1];
          sub += in[l];
        }
        ans = max(ans, sum + adi - sub);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
