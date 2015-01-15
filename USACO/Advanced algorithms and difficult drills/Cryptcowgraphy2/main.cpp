/*
 ID: brani.e2
 PROG: cryptcow 
 LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

struct Node{
  char c;
  Node *sig;
  Node *ant;
  Node(){
    c = '$';
    sig = NULL;
    ant = NULL;
  }
  Node(char car){
    c = car;
    sig = NULL;
    ant = NULL;
  }
  void imprimir(){
    cout << c;
    if(sig != NULL)
      sig->imprimir();
    else
      cout << endl;
  }
};
typedef Node* Iter;
void enlazar(Iter &a, Iter &b){
  if(a != NULL)
    a->sig = b;
  if(b != NULL)
    b->ant = a;
}
struct String{
  Node *inicio;
  Node *ultimo;
  
  String(){
    inicio = new Node('$');
    ultimo = new Node('$');
    enlazar(inicio, ultimo);
  }
  String(string cad){  
    inicio = new Node('$');
    ultimo = new Node('$');
    enlazar(inicio, ultimo);
    for(int i = 0; i < cad.size(); i++)
      push_back(cad[i]);
  }
  void push_back(char car){
    Iter newnode = new Node(car);
    enlazar(ultimo->ant, newnode);
    enlazar(newnode, ultimo);
  }

  Node* begin(){
    Node *cpini = inicio->sig;
    return cpini;
  }
  Node* end(){
    Node *cpult = ultimo;
    return cpult;
  }
  void print(){
    Iter it = begin();
    while(it != end()){
      cout << (it->c);
      it = (it->sig);
    }
    cout << endl;
  }
  bool operator == (string cad){
    Iter it = begin();
    for(int i = 0; i < cad.size(); i++){
      if(it == NULL || (it->c) != cad[i])return false;
      it = it->sig;
    }
    return (it == end());
  }
  bool operator != (string cad){
    return !(*this == cad);
  }
};
void cambio(Iter c, Iter o, Iter w){
  enlazar(w->ant, w->sig);
  w = w->sig;
  enlazar(o->ant, o->sig);
  o = o->sig;
  enlazar(c->ant, c->sig);
  c = c->sig;
  
  if(c == o || o == w)//Uno de los 2 grupos no tiene caracteres ya no es necesario cambiar
    return;

  Iter cant = c->ant, want = w->ant, oant = o->ant;
  enlazar(cant, o);
  enlazar(want, c);  
  enlazar(oant, w);
}
void restablecer(Iter c, Iter o, Iter w){
  enlazar(c->ant, c);
  enlazar(c, c->sig);
  
  enlazar(o->ant, o);
  enlazar(o, o->sig);
  
  enlazar(w->ant, w);
  enlazar(w, w->sig);
}
/*------------------------------------------  Lista Doble Enlazada ----------------------------------------------- */

String cad("COccCdOeeWfWg");
string target = "Begin the Escape execution at the Break of Dawn";
int targetsize;

/*---------- HASH de NealWu------------*/
#define NHASH 7900001
bitset <NHASH> hashtable;
int p [100];
inline unsigned int hash (){
  unsigned int sum = 0;
  int i = 0;
  for (Iter it = cad.begin(); it != cad.end(); it = (it->sig), i++)
    sum += p [i] * int (it->c);
  return sum % NHASH;
}
/*---------- HASH ------------*/


long long int bits[260];
void preprocesar(){
  memset(bits, 0, sizeof(bits));
  for(long long int i = 0; i < target.size(); i++)
    bits[target[i]] |= (1LL<<i);
}
bool contiene(Iter a, Iter b){//b no esta incluido
  if(a == b)return true;
  long long int ans = bits[a->c];
  a = a->sig;
  while(a != b){
    long long int tmp = ((bits[a->c] >> 1LL) & ans) << 1LL;
    ans = tmp;
    a = a->sig;
  }
  return ans;
}
bool verificar(){
  Iter a = cad.begin(), b;
  while(a != cad.end()){
    while(a != cad.end() && ((a->c) == 'C' || (a->c) == 'O' || (a->c) == 'W'))
      a = a->sig;
    
    if(a != cad.end())
      b = a->sig;
    else
      b = a;
    
    while(b != cad.end() && !((b->c)=='C' || (b->c)=='O' || (b->c)=='W'))
      b = b->sig;
    if(!contiene(a, b))
      return false;

    if(b == cad.end())
      a = b;
    else
      a = b->sig;
  }
  return true;
}
bool solve(int tam){
  
  unsigned int hs = hash();
  if(hashtable[hs])
    return false;
  hashtable[hs] = true;
  
  if(tam == targetsize)
    return (cad == target);
  
  if(!verificar())
    return false;

  Iter c = cad.begin();
  while(c != cad.end()){
    if((c->c) == 'C'){
      Iter o = c;
      while(o != cad.end()){
        if((o->c) == 'O'){
          Iter w = o;
          while(w != cad.end()){
            if((w->c) == 'W'){
              cambio(c, o, w);
              if(solve(tam - 3))
                return true;
              restablecer(c, o, w);
            }
            w = w->sig;
          }
        }
        o = o->sig;
      }
    }
    c = c->sig;
  }
  return false;
}

int main(){
  preprocesar();
  p[0] = 1;
  for (int i = 1; i < 100; i++)
    p [i] = 7 * p [i - 1];
  ifstream cin("cryptcow.in");
  ofstream cout("cryptcow.out");
  string encrypted;
  getline(cin, encrypted);
  string withoutcow = "";
  int C, O, W;
  C = O = W = 0;
  for(int i = 0; i < encrypted.size(); i++){
    char car = encrypted[i];
    if(car == 'C')
      C++;
    else if(car == 'O')
      O++;
    else if(car == 'W')
      W++;
    else
      withoutcow.push_back(car);
  }
  sort(withoutcow.begin(), withoutcow.end());
  string copy = target;
  sort(copy.begin(), copy.end());
  if(C == O && O == W && copy == withoutcow){
    targetsize = target.size();
    cad = String(encrypted);
    if(solve(encrypted.size()))
      cout << 1 << " " << C << endl;
    else
      cout << "0 0" << endl;
  }else
    cout << "0 0" << endl;
  return 0;
}
