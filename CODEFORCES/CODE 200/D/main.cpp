#include <iostream>
#include <vector>


using namespace std;
bool reducir(string &c) {
    string v = "";
    int n = c.size();
    if(c[n-1] == '+')
        c.push_back('-');
    else
        c.push_back('+');
    bool ans = false;
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        for(j = i + 1; j < n; j++)
            if(c[i] != c[j])
                break;
        int cant = j - i;
        i = j - 1;


        if(cant > 1)ans = true;
        if(cant % 2 != 0)
            if(c[i] == '+') v = v + '+';
            else v = v + '-';
    }
    c = v;
    return ans;
}
int main() {
    string c;
    int n;
    while(cin >> c) {
        while(reducir(c) && !c.empty())
            ;
        if(c.size())
            cout << "No" << endl;
        else
            cout << "Yes" << endl;



    }
    return 0;
}
