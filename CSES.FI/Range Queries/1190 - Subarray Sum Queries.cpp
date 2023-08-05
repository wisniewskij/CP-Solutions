// github.com/wisniewskij/Code
// cses.fi/problemset/task/1190
// Subarray Sum Queries

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
    int n; vector<ll> sum,prefix,postfix,maxi;
    SegTree(int n){
        for(this->n=1;this->n<n;this->n<<=1);
        sum.assign(this->n<<1, 0);
        prefix.assign(this->n<<1, 0);
        postfix.assign(this->n<<1, 0);
        maxi.assign(this->n<<1, 0);
    }
    void set(int pos, int val){
        pos+=n; sum[pos]=val; prefix[pos]=max(val, 0); postfix[pos]=max(val,0), maxi[pos]=max(val, 0);
        for(int i=pos/2; i>0; i/=2){
            sum[i]=sum[i*2]+sum[i*2+1];
            prefix[i]=max(prefix[i<<1], sum[i<<1]+prefix[i<<1|1]);
            postfix[i]=max(postfix[i<<1|1], sum[i<<1|1]+postfix[i<<1]);
            maxi[i]=max({maxi[i<<1], maxi[i<<1|1], prefix[i], postfix[i], postfix[i<<1]+prefix[i<<1|1]});
        }
    }
    ll q() { return maxi[1]; }
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
        int a,b;
        cin>>a>>b;
        sgt.set(a-1,b);
        cout<<sgt.q()<<ndl;
    }
}