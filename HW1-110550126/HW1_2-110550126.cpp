#include<bits/stdc++.h>
 
 
using namespace std;
 #pragma GCC optimize("O2")

#define eb emplace_back
#define pb push_back
#define ALL(X) X.begin(), X.end()

typedef long long loli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;
typedef pair<pll,pll> pllll;
typedef string str;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<loli> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<str> vs;

void _solve(){
    int n ,m,k,t;
    cin >> n>>m>>k>>t;
    vb inf(n+1,false);
    vvi nei(n+1,vi());
    int ans =k;
    for(int i =0;i<m;i++){
        int a,b;
        cin >>a>>b;
        nei[a].eb(b);
    }
    queue<int> q;
    for(int i =0;i<k;i++){
        int a;
        cin >>a;
        inf[a] = true;
        q.push(a);
    }
    for(int i = 1;i<t;i++){
        int now = q.size();
        if(!now)break;
        for(int j =0;j<now;j++){
            for(auto k:nei[q.front()]){
                if(!inf[k]){
                    q.push(k);
                    inf[k] = true;
                    ans++;
                }
            }
            q.pop();
        }
    }
    cout <<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }

}