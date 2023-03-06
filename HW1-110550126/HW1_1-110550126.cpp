#include<bits/stdc++.h>
 
 
using namespace std;
 

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
    int n ,m;
    cin >> n>>m;
    vvi mp(n,vi(n,0));
    vpii inout(n);
    for(int i =0;i<m;i++){
        int a,b,c;
        cin >> a >>b>>c;
        mp[a-1][b-1] = c;
        inout[a-1].second++;
        inout[b-1].first++;
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout <<mp[i][j]<<" ";
        }
        cout <<"\n";
    }
    for(auto [a,b]:inout){
        cout <<a<<" "<<b <<'\n';
    }
}
int main(){
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }

}
