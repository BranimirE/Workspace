#include <cstdio>
#include <vector>

using namespace std;
vector<int> ans;
int main()
{
    int n, tmp;
    while(scanf("%d", &n), n){
        ans.clear();
        while(n--){
            scanf("%d", &tmp);
            if(tmp)
                ans.push_back(tmp);
        }
        for(int i = 0; i < ans.size(); i++)
            printf("%s%d", (i?" ":""), ans[i]);
        if(ans.size() == 0)
            printf("0");
        puts("");
    }
    return 0;
}
