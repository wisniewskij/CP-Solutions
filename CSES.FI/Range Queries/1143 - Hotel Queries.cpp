// github.com/wisniewskij/Code
// cses.fi/problemset/task/1143/
// Hotel Queries

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
        for(int i=pos/2;i>0;i/=2){
            tab[i]=max(tab[i*2],tab[i*2+1]);
        }
    }
    void decrease(int pos, int v){
        pos+=n;
        tab[pos]-=v;
        for(int i=pos/2;i>0;i/=2){
            tab[i]=max(tab[i*2],tab[i*2+1]);
        }
    }
    int q(int a, int b){
        a+=n;b+=n;int maxi=0;
        while(a<=b){
            if(a&1) maxi=max(maxi, tab[a++]);
            if((b&1)^1) maxi=max(maxi, tab[b--]);
            a>>=1;
            b>>=1;
        }
        return maxi;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    SegTree str(n);
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        str.set(i, h);
    }
 
    while(m--){
        int r; 
        cin>>r;
        int a=-1, b=n;
        while(a+1<b){
            int sr=(a+b)/2;
            if(str.q(0, sr)<r) a=sr;
            else b=sr;
        }
        if(b==n) cout<<0<<' ';
        else{
            cout<<b+1<<' ';
            str.decrease(b, r);
        }
    }
    
 
}
