#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

string c,tmp;
int tam;
string m[105];
bool solve() {
    for(int i = 0; i < tam; i++)
        m[i] = c.substr(i*tam, tam);
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if(!(m[i][j]==m[j][i] && m[j][i]==m[tam-i-1][tam-j-1] && m[tam-i-1][tam-j-1]==m[tam-j-1][tam-i-1]))
                return false;

    return true;
}
int main() {
    //freopen("in", "r", stdin);
    int t;
    cin >> t;
    getline(cin , tmp);
    for(int caso = 1; caso <= t; caso++) {
        getline(cin , tmp);
        c = "";
        for(int i = 0; i < tmp.size(); i++)
            if(isalpha(tmp[i]))
                c = c + ((char)tmp[i]);
        tam = sqrt(c.size());
        cout << "Case #" << caso << ":" << endl;
        if(tam*tam == c.size() && solve())
            cout <<  tam << endl;
        else
            cout << "No magic :(" << endl;
    }
    return 0;
}
