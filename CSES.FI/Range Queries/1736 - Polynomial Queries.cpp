// github.com/wisniewskij/Code
// cses.fi/problemset/task/1736/
// Polynomial Queries

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
    vector<ll> sum, ta, tb;
    SegTree(int n){
        for(this->n=1; this->n<n; this->n<<=1);
        sum.assign(this->n<<1, 0);
        ta.assign(this->n<<1, 0);
        tb.assign(this->n<<1, 0);
    }
    void set(int pos, int val){
        pos+=n; sum[pos]=val;
        for(int i=pos/2; i>0; i/=2)
            sum[i]=sum[i*2]+sum[i*2+1];
    }
    void propagate(int k, int x, int y){
        if(!(ta[k]||tb[k])) return;
        int len=y-x+1;
        sum[k]+=len*tb[k]+((ta[k]*(y-x)*len)/2);
        if(x!=y){
            ta[k*2]+=ta[k];
            ta[k*2+1]+=ta[k];
            tb[k*2]+=tb[k];
            tb[k*2+1]+=tb[k]+(len/2)*ta[k];
        }
        ta[k]=tb[k]=0;
    }
    void add(int a, int b, int k, int x, int y){
        if(y<a||b<x) return;
        if(a<=x&&y<=b){
            ta[k]++;
            tb[k]+=(x-a+1);
        }
        else{
            propagate(k, x, y);
            int mid=(x+y)/2;
            add(a, b, k*2, x, mid);
            add(a, b, k*2+1, mid+1, y);
            propagate(k*2, x, mid);
            propagate(k*2+1, mid+1, y);
            sum[k]=sum[k*2]+sum[k*2+1];
        }
    }
    ll query(int a, int b, int k, int x, int y){
        if(y<a||b<x) return 0;
        propagate(k, x, y);
        if(a<=x&&y<=b){
            return sum[k];
        } 
        
        else{
            int mid=(x+y)/2;
            return query(a, b, k*2, x, mid) + query(a, b, k*2+1, mid+1, y);
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin>>n>>q;
    SegTree sgt(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sgt.set(i, tmp);
    }
    while(q--){
        int x,a,b;
        cin>>x>>a>>b;
        if(x==1){
            sgt.add(a-1, b-1, 1, 0, sgt.n-1);
        } 
        else{
            cout<<sgt.query(a-1, b-1, 1, 0, sgt.n-1)<<ndl;
        }
    }
}
