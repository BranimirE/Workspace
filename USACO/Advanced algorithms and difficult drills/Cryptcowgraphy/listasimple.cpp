#include <bits/stdc++.h>

using namespace std;
struct Node{
  char c;
  Node *sig;
  Node(){
    c = ' ';
    sig = NULL;
  }
  Node(char car){
    c = car;
    sig = NULL;
  }
  void imprimir(){
    cout << c;
    if(sig != NULL)
      sig->imprimir();
    else
      cout << endl;
  }
  Node* adicionar(char car){
    Node *actual = this;
    while(true){
      if((actual->sig) != NULL)
        actual = (actual->sig);
      else{
        (actual->sig) = new Node(car);
        break;
      }
    }
    return actual->sig;
  }
};
typedef Node* Iter;
struct String{
  Node *inicio;
  Node *ultimo;
  
  String(){
    inicio = NULL;
    ultimo = NULL;
  }
  String(string cad){  
    inicio = NULL;
    ultimo = NULL;
    for(int i = 0; i < cad.size(); i++){
      push_back(cad[i]);
    }
  }
  void push_back(char car){
    if(inicio != NULL)
      ultimo = (ultimo->adicionar(car));    
    else{
      inicio = new Node(car);
      ultimo = inicio;
    } 
  }
  void push_front(char car){
    Node *newnode = new Node(car);
    (newnode->sig) = inicio;
    inicio = newnode;
  }
  void print(){
    inicio->imprimir();
  }
  Node* begin(){
    Node *cpini = inicio;
    return cpini;
  }
  Node* end(){
    Node *cpult = ultimo;
    return cpult;
  }
  bool operator == (string cad){
    Iter it = begin();
    for(int i = 0; i < cad.size(); i++){
      if(it == NULL || (it->c) != cad[i])return false;
      it = it->sig;
    }
    return (it == NULL);
  }
  bool operator != (string cad){
    return !(*this == cad);
  }
};
bool avanzar(Iter &it){
  if(it != NULL){
    it = (it->sig);
    return true;
  }
  return false;
}
void avanzar(Iter &it, int cant){
  while(cant--)
    avanzar(it);
}
void enlazar(Iter &a, Iter &b){
  a->sig = b;
}
void cambio(Iter &c, Iter &o, Iter &w){//El sig de cada Iter es el correspondiente
  
  //Normal
  Iter Cini = c;
  avanzar(Cini);
  avanzar(Cini);
  Iter Oini = o;
  avanzar(Oini);
  avanzar(Oini);
  Iter Wini = w;
  avanzar(Wini);
  avanzar(Wini);
  
  enlazar(c, Oini);
  enlazar(o, Wini);
  enlazar(w, Cini);
}
int main(){
  String micad("aaCbbOccW");
  micad.print();
  Iter c = micad.begin();
  Iter o = micad.begin();
  Iter w = micad.begin();
  avanzar(c, 1);
  avanzar(o, 4);
  avanzar(w, 7);
  
  cambio(c, o, w);
  micad.print();
  return 0;
 }
