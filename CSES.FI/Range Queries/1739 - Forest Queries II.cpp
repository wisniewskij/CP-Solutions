// github.com/wisniewskij/Code
// cses.fi/problemset/task/1739
// Forest Queries II
 
#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1e18
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

class Seg2DTree{
    public:
    int n;
    vector<vector<int>> t;
    Seg2DTree(int n){
        for(this->n=1; this->n<n; this->n<<=1);
        t.assign(this->n<<1, vector<int>(this->n<<1,0));
    }
    void set(int y, int x, int val){
        for(int i=y+n;i>0;i/=2)
            for(int j=x+n;j>0;j/=2)
                t[i][j]+=val;
    }
    int subquerry(int y, int a, int b){
        int ans=0; a+=n; b+=n;
        while(a<=b){
            if(a%2==1) ans+=t[y][a++];
            if(b%2==0) ans+=t[y][b--];
            a/=2; b/=2;
        }
        return ans;
    }
    int query(int yl, int xl, int yr, int xr){
        int ans=0; yl+=n; yr+=n;
        while(yl<=yr){
            if(yl%2==1) ans+=subquerry(yl++, xl, xr);
            if(yr%2==0) ans+=subquerry(yr--, xl, xr);
            yr/=2; yl/=2;
        }
        return ans;
    }
};
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<vector<bool>> trees(n, vector<bool>(n, 0));
    Seg2DTree sgt(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            if(c=='*') sgt.set(i, j, 1);
            trees[i][j]=(c=='*'?1:0);
        }
    while(q--){
        int k;
        cin>>k;
        if(k==1){
            int y, x;
            cin>>y>>x;
            trees[y-1][x-1]=!trees[y-1][x-1];
            sgt.set(y-1, x-1, (trees[y-1][x-1]?1:-1)); 
        }
        else{
            int yl, xl, yr, xr;
            cin>>yl>>xl>>yr>>xr;
            cout<<sgt.query(yl-1, xl-1, yr-1, xr-1)<<ndl;
        }
    }
}