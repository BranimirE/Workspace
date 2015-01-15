#include <iostream>
#include <cstdlib>
using namespace std;
string c, s;
bool ispal(){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
}
int main()
{
    while(getline(cin, c) && c != "DONE"){
        s = "";
        for(int i = 0; i < c.size(); i++)
            if(isalpha(c[i]))
                s = s + (char)tolower(c[i]);
        cout << ((ispal())?"You won't be eaten!":"Uh oh..") << endl;

    }
    return 0;
}
