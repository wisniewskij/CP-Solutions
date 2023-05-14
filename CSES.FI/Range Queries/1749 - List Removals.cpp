// github.com/wisniewskij/Code
// cses.fi/problemset/task/1749
// List Removals

#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()

using namespace std;

class SegTree{
    public:
    int n;
    vector<int> tab;
    SegTree(int n){
        (this->n)=1;
        while((this->n)<n) (this->n)*=2;
        (this->tab).assign(2*(this->n), 0);
    }
    void set(int pos, int v){
        pos+=n;
        tab[pos]=v;
        for(int i=pos>>1;i>0;i>>=1){
            tab[i]=tab[i<<1]+tab[(i<<1)+1];
        }
    }
    int q(int a, int b){
        a+=n; b+=n; int sum=0;
        while(a<=b){
            if(a&1) sum+=tab[a++];
            if((b&1)^1)sum+=tab[b--];
            a>>=1;
            b>>=1;
        }
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    SegTree str(n);
    vector<int> t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
        str.set(i, 1);
    }
    
    for(int iter=0;iter<n;iter++){
        int p;
        cin>>p;
        int a=-1, b=n;
        while(a+1<b){
            int sr=(a+b)/2;
            if(str.q(0, sr)<p) a=sr;
            else b=sr;
        }
        str.set(b, 0);
        cout<<t[b]<<' ';
    }
}