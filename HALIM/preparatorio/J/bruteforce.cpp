#include <iostream>

using namespace std;

int v[10000];
int main(){
  int casos;
  cin >> casos;
  while(casos--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> v[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
      int neg = 0, pos = 0;
      for(int j = i; j < n; j++){
        if(v[j] < 0)neg++;
        else pos++;
        if(neg == pos)
          ans = max(ans, neg+ pos);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
