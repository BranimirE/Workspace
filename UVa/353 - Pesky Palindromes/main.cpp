#include <iostream>
#include <set>
#include <fstream>

using namespace std;
set<string> s;
string c;
bool ispal(string &cad){
    int i = 0, j = cad.size()-1;
    while(i < j){
        if(cad[i] != cad[j])
            return false;
        i++, j--;
    }
    return true;
}
int main()
{
    //freopen("in", "r", stdin);
    while(getline(cin, c)){
        s.clear();

        for(int i = 0; i < c.size(); i++)
            for(int j = 1; j <= c.size() - i; j++){
                string tmp = c.substr(i, j);
                if(ispal(tmp))
                    s.insert(tmp);
            }
        cout << "The string '" << c << "' contains "<<s.size() << " palindromes." << endl;
    }
    return 0;
}
