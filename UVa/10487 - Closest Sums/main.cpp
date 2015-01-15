#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1003
long long int v[MAX];

int n, q, t, pos;
vector<long long int> m;

int main()
{
    int caso = 1;
    while(scanf("%d", &n)==1, n){
        m.clear();
        for(int i = 0; i < n; i++){
            scanf("%lld", &v[i]);
            for(int j = i - 1; j >= 0; j--)
                m.push_back(v[i]+v[j]);
        }
        sort(m.begin(), m.end());
        m.resize(unique(m.begin(), m.end()) - m.begin());
        scanf("%d", &q);
        printf("Case %d:\n", caso++);
        while(q--){
            long long int tmp;
            scanf("%lld", &tmp);
            pos = lower_bound(m.begin(), m.end(), tmp) - m.begin();
            printf("Closest sum to %lld is ", tmp);
            if(pos == 0)
                printf("%lld.\n", m[0]);
            else if(pos == n)
                printf("%lld.\n", m[n-1]);
            else
                if(abs(tmp - m[pos]) < abs(tmp-m[pos-1]))
                    printf("%lld.\n", m[pos]);
                else
                    printf("%lld.\n", m[pos - 1]);
        }

    }
    return 0;
}
