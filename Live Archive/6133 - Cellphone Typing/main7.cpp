#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

const int ALPH_SIZE = 58;  // tamaño del alfabeto

struct Node{
    int words;              // número de palabras que terminan en el nodo
    int prefixes;           // número de palabras que tienen como prefijo el camino al nodo
    vector<Node*> links;    // enlaces a los nodos hijos

    int hijos;
    Node();
};

Node::Node(){
    words = prefixes = 0;
    links.resize(ALPH_SIZE,NULL);
    hijos = 0;
}

class Trie{
    public :
    
    Trie();
    
    bool contains(const string& s) const;
    int nodeCount() const;
    int countWords(const string& s) const;
    int countPrefixes(const string& s) const;
    int countRepeated() const;
    void printAllWords() const;
    
    void insert(const string s);
    Node* myRoot;       // raíz del trie    
    private :
    

    int myCount;        // # nodos del trie
    
    int countRepeated(Node* t) const;
    void printAllWords(const Node* t, const string& s) const;
};

Trie::Trie(){
    myRoot = new Node();
    myCount = 1;
}

bool Trie::contains(const string& s) const{
    Node* t = myRoot;
    int len = s.size();
    
    for(int k=0;k<len;++k){
        if(t==NULL) return false;
        t = t->links[s[k]];
    }
    
    return (t->words > 0);
}

int Trie::nodeCount() const{
    return myCount;
}

int Trie::countWords(const string& s) const{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'A']==NULL) return 0;
        t = t->links[s[k]-'A'];
    }
    
    return t->words;
}

int Trie::countPrefixes(const string& s) const{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'A']==NULL) return 0;
        t = t->links[s[k]-'A'];
    }
    
    return t->prefixes;
}

void Trie::printAllWords(const Node* t, const string& s) const{
    if(t->words > 0) cout<<s<<endl;
    
    for(int k=0;k<ALPH_SIZE;++k)
        if(t->links[k]) printAllWords(t->links[k],s+char(k+'A'));
}

void Trie::printAllWords() const{
    printAllWords(myRoot,"");
}

void Trie::insert(const string s){
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'A']==NULL){
            t->links[s[k]-'A'] = new Node();
            ++myCount;
	    (t->hijos)++;
        }
        t = t->links[s[k]-'A'];
        ++(t->prefixes);
    }
    ++(t->words);
}

int Trie::countRepeated(Node* t) const{
    int aux = 0;
    
    if((t->words)>1) ++aux;
    
    for(int k=0;k<ALPH_SIZE;++k)
        if(t->links[k]) aux += countRepeated(t->links[k]);
    
    return aux;
}

int Trie::countRepeated() const{
    return countRepeated(myRoot);
}
int solve (Node* t, int acu = 0, bool isroot = true) {
  int ans = 0;
  if (t->words) ans = acu;
  if ( (t->hijos) > 1 || isroot || (t->words) > 0) acu++;
  for (int k = 0; k < ALPH_SIZE; ++k)
    if (t->links[k])
      ans += solve(t->links[k], acu, false);
  return ans;
}
char buf[90];
int main(){
      //  ios_base::sync_with_stdio(false);
  int n;
  while (scanf("%d", &n) != EOF) {
    Trie* myTrie;
    myTrie = new Trie();
   
    string s;
    forn (_, n) {
      scanf("%s", buf);
      s = string(buf);
      myTrie->insert(s);
    }
    //    myTrie->printAllWords();
    printf("%.2lf\n", double(solve(myTrie->myRoot)) / n);
    delete myTrie;
  }
    return 0;   
}
