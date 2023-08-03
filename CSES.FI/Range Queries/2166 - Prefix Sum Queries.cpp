// github.com/wisniewskij/Code
// cses.fi/problemset/task/2166
// Prefix Sum Queries

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
    vector<ll> pfx;
    vector<ll> sum;
    SegTree(int n){
        (this->n)=1;
        while((this->n)<n) (this->n)*=2;
        (this->pfx).assign(2*(this->n), 0);
        (this->sum).assign(2*(this->n), 0);
    }
    void set(int pos, int v){
        pos+=n;
        pfx[pos]=max(v,0);
        sum[pos]=v;
        for(int i=pos>>1;i>0;i>>=1){
            sum[i]=sum[2*i]+sum[2*i+1];
            pfx[i]=max(pfx[2*i], sum[2*i]+pfx[2*i+1]);
        }
    }
    ll q(int a, int b, int k, int x, int y){
        if(y<a||x>b) return 0;
        if(a<=x&&y<=b) return pfx[k];
        return max(q(a,b, 2*k, x, (x+y)/2), sumq(a,b,2*k,x,(x+y)/2)+q(a,b, 2*k+1, (x+y)/2+1, y));
    }
    
    ll sumq(int a, int b, int k, int x, int y){
        if(y<a||x>b) return 0;
        if(a<=x&&y<=b) return sum[k];
        return sumq(a,b, 2*k, x, (x+y)/2)+sumq(a,b, 2*k+1, (x+y)/2+1, y);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    SegTree sgt(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sgt.set(i, tmp);
    }
    while(q--){
        int x;
        cin>>x;

        if(x==1){
            int k,u;
            cin>>k>>u;
            sgt.set(k-1, u);
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<sgt.q(a-1, b-1, 1, 0, sgt.n-1)<<ndl;
        }
    }
}