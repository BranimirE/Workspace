//Nota: Ya que no hacemos update del SegmentTree se puede mejorar para poder responder las querys en O(1).
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX 100005
typedef vector<int> vi;

class SegmentTree {
private:
    vi rmq, m;
    int n;
    int NEUT;

    int LEFT(int n) {return n << 1;}

    int RIGHT(int n) {return (n << 1)+1;}

    int oper(int a, int b) {
        return max(a, b);
    }

    void rmq_init(int n, int s, int e) {
        if(s+1 == e)
            rmq[n] = m[s];
        else {
            rmq_init(LEFT(n), s, (s+e)/2);
            rmq_init(RIGHT(n), (s+e)/2,e);
            rmq[n] = oper(rmq[LEFT(n)], rmq[RIGHT(n)]);
        }
    }
    void rmq_update(int n, int s, int e, int p, int v) {
        if(s+1 == e)
            rmq[n] = m[s] = v;
        else {
            if(p < (s+e)/2)
                rmq_update(LEFT(n), s, (s+e)/2, p, v);
            else
                rmq_update(RIGHT(n), (s+e)/2, e, p, v);
            rmq[n] = oper(rmq[LEFT(n)], rmq[RIGHT(n)]);
        }
    }
    int rmq_query(int n, int s, int e, int a, int b) {
        if(a >= e || b <= s)
            return NEUT;
        else if (s >= a && e <= b)
            return rmq[n];
        else {
            int l = rmq_query(LEFT(n), s, (s+e)/2, a, b);
            int r = rmq_query(RIGHT(n), (s+e)/2, e,a, b);
            return oper(l, r);
        }
    }
public:
    SegmentTree(const vi &A){
        NEUT = 0;
        m = A;
        n = A.size();
        rmq.assign(4 * n, 0);
        rmq_init(1, 0, n);
    }
    int query(int i, int j){
        if(i>j)
            return 0;
        return rmq_query(1, 0, n, i, j+1);
    }
    void update(int idx, int new_value){
        rmq_update(1, 0, n, idx, new_value);
    }
};
int grupo[MAX];
int vec[MAX];
int n,m,g;
int main() {
    while(scanf("%d", &n)==1, n){
        scanf("%d", &m);

        for(int i = 0; i < n; i++)
            scanf("%d", &vec[i]);

        vi a, ini,fin;
        vec[n] = 1<<30;
        g = 0;
        for(int i = 0; i < n; i++){
            ini.push_back(i);
            while(i < n && vec[i] == vec[i+1]){
                grupo[i] = g;
                i++;
            }
            grupo[i] = g;
            fin.push_back(i);
            a.push_back(fin[g]-ini[g] + 1);
            g++;
        }
        SegmentTree st(a);
        int i, j;
        while(m--){
            scanf("%d %d", &i, &j);
            i--, j--;
            int gi = grupo[i], gj = grupo[j];
            if(gi == gj)
                printf("%d\n", j - i + 1);
            else{
                int ans = max(fin[gi] - i + 1, j - ini[gj] + 1);
                ans = max(ans, st.query(gi+1, gj-1));
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

