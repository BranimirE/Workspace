#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAXS 1000
using namespace std;
string sum(const string &a, const string &b){
  string ans = "";
  int residuo = 0, i = 0;
  while(i < a.size() && i < b.size()){
    residuo += a[i] + b[i] - '0' - '0';
    ans = (ans + (char)('0' + (residuo % 10)));
    residuo /= 10;
    i++;
  }
  while(i < a.size()){
    residuo += a[i] - '0';
    ans = (ans + (char)('0' + (residuo % 10)));
    residuo /= 10;
    i++;
  }
  while(i < b.size()){
    residuo += b[i] - '0';
    ans = (ans + (char)('0' + (residuo % 10)));
    residuo /= 10;
    i++;
  }
  while(residuo){
    ans = (ans + (char)('0' + (residuo % 10)));
    residuo /= 10;
  }
  return ans;
}
int main(){
  vector<string> v;
  string a = "0", b = "1", c = "";
  while(a.size() <= MAXS){
    v.push_back(a);
    c = sum(a, b);
    a = b;
    b = c;
  }
  sort(v.begin(), v.end());
  int t;
  cin >> t;
  while(t--){
    string cad;
    cin >> cad;
    cad = string(cad.rbegin(), cad.rend());
    puts(binary_search(v.begin(), v.end(), cad)?"YES":"NO");
  }
  return 0;
}
