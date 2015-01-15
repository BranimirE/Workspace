#include <bits/stdc++.h>

using namespace std;
string cad;
char s[256];
int main(){
  int t;
  cin >> t;
  while(t--){
    for(int i = 0; i < 256; i++)
      s[i] = i;

    int rules;
    cin >> rules;
    while(rules--){
      char from, to;
      cin >> from >> to;
      s[from] = to;
    }

    cin >> cad;
    if(cad.size() == 0){
      cout << 0 << endl;
      continue;
    }
      
    for(int i = 0; i < cad.size(); i++)
      cad[i] = s[cad[i]];

    int i = 0, j = cad.size() - 1;
    while(i <= j && cad[i] == '0')
      i++;

    if(cad.find('.') != string::npos)
      while(j >= i && cad[j] == '0')
        j--;

    if(j >= i && cad[j] == '.')
      j--;
    if(i <= j)
      cout << cad.substr(i, j - i + 1) << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
