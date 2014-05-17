#include <iostream>

using namespace std;
string rle(string &c){
  string ans = "";
  int i = 0, j , n = c.size();
  while(i < n){
    j = i;
    while(j < n && c[j] == c[i])
      j++;
    ans.push_back('0' + j - i);
    ans.push_back(c[i]);
    i = j;
  }
  return ans;
}
string invrle(string &c){
  string ans = "";
  for(int i = 0; i < c.size(); i += 2)
    ans = ans + string(c[i] - '0', c[i + 1]);
  return ans;
}
int main(){
  string cad;
  for(int i = 0; i < 10; i++){
    cin >> cad;
    cout << rle(cad) << endl;
  }
  for(int i = 0; i < 10; i++){
    cin >> cad;
    cout << invrle(cad) << endl;
  }
  return 0;
}
