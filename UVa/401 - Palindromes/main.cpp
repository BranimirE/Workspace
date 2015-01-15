#include <iostream>
#include <cstring>

using namespace std;

char rev[257];
bool ispal(string &c) {
    int i = 0, j = c.size()-1;
    while(i < j) {
        if(c[i] != c[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool isespejo(string c) {
    string c2(c.rbegin(), c.rend());
    for(int i = 0; i < c2.size(); i++)
        if(rev[c2[i]])
            c2[i] = rev[c2[i]];
        else
            return false;// no puede contener caracteres que no tienen inverso

    return c==c2;
}
int main() {
    memset(rev, 0, sizeof(rev));
    rev['A'] = 'A';
    rev['H'] = 'H';
    rev['I'] = 'I';
    rev['M'] = 'M';
    rev['O'] = 'O';
    rev['T'] = 'T';
    rev['U'] = 'U';
    rev['V'] = 'V';
    rev['W'] = 'W';
    rev['X'] = 'X';
    rev['Y'] = 'Y';
    rev['1'] = '1';
    rev['8'] = '8';
    rev['E'] = '3';
    rev['3'] = 'E';
    rev['J'] = 'L';
    rev['L'] = 'J';
    rev['S'] = '2';
    rev['2'] = 'S';
    rev['Z'] = '5';
    rev['5'] = 'Z';

    string cad;
    bool sw = false;
    while(getline(cin, cad)) {
        sw = true;
        bool pal, esp;
        pal = ispal(cad);
        esp = isespejo((cad));
        cout << cad;
        if(pal && esp)
            cout << " -- is a mirrored palindrome."<< endl;
        else if(esp)
            cout << " -- is a mirrored string." << endl;
        else if(pal)
            cout << " -- is a regular palindrome." << endl;
        else
            cout << " -- is not a palindrome." << endl;
        cout << endl;
    }
    return 0;
}
