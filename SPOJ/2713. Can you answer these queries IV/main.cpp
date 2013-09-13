#include <cstdio>
#include <cmath>
using namespace std;
long long int c[100005];
long long int tree[400005];
//si es segment tree de -,* o / solo sustituir el + en init query y update
void init(int node,int a,int b) {
    if(a==b) {
        tree[node]=c[a];
        return ;
    }
    init(2*node+1,a,(a+b)/2);
    init(2*node+2,(a+b)/2+1,b);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
// consula para llamar query(0,0,n-1,desde,hasta)
long long int query(int node,int a,int b,int p,int q) {
    //la consulta se hace en el rango desde p a q, a y b son los limites del rango
    if( q<a || b<p )return 0;
    if(p<=a && b<=q) {
        return tree[node];
    }
    return query(2*node+1,a,(a+b)/2,p,q)+query(2*node+2,(a+b)/2+1,b,p,q);
}
//sustituir para llamar(0,0,n-1,posicion,valor)
void update(int node,int a,int b,int p,long long int val) {
    if(p<a || b<p)return;
    if(a==b) {
        tree[node]=val;
        c[p] = val;
        return ;
    }
    update(2*node+1,a,(a+b)/2,p,val);
    update(2*node+2,(a+b)/2+1,b,p,val);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}

int main() {
    int n,caso = 1;
    long long int aux;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i < n; i++) {
            scanf("%lld",&aux);
            c[i]=aux;
        }
        init(0,0,n-1);
        //ejemplo de sustitucion tree[a]=val
        int a,b,op;
        int m;
        scanf("%d", &m);

        printf("Case #%d:\n", caso++);
        while(m--){

            scanf("%d %d %d",&op, &a,&b);
            if(a > b){
                int tmp = a;
                a = b;
                b = tmp;
            }

            if(op == 0) {
                //a--;//solo si los subindices del problema van de 1...n
                for(int i = a - 1; i <= b-1; i++)
                    update(0,0,n-1,i,(long long int)sqrt(c[i]));
            } else {
                a--;//solo si los subindices del problema van de 1...n
                b--;//solo si los subindices del problema van de 1...n
                long long int x=query(0,0,n-1,a,b);
                printf("%lld\n",x);
            }
        }
        puts("");
    }
    return 0;
}
