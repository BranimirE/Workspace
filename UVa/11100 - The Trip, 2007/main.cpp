#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 10005
using namespace std;
int v[MAX];
int main(){
    int n;
    bool enter = false;
    while(scanf("%d", &n), n){

        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        sort(v, v + n );
        int igu = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            for(j = i; j < n; j++)
                if(v[j] != v[i])
                    break;
            igu = max(igu, j - i);
            i = j - 1;
        }
        vector<int> ans[igu];
        for(int i = 0; i < n; i++)
            ans[i%igu].push_back(v[i]);

        if(enter)puts("");
        enter = true;
        printf("%d\n", igu);
        for(int i = 0; i < igu; i++){
            for(int j = 0; j < ans[i].size(); j++)
                printf("%s%d", (j?" ":""), ans[i][j]);
            puts("");
        }
    }
    return 0;
}
