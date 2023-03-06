#include<bits/stdc++.h>
 
 
using namespace std;


//#define int long long 

#define endl '\n'
#define eb emplace_back
#define pb push_back
#define ALL(X) X.begin(), X.end()
#define rALL(X) X.rbegin(), X.rend()
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
#define maxn 100005
//int a[maxn];
ifstream fin("test.in");
ofstream fout("test.out");
int n ,m;
vvi road;
int first[maxn*2],to[maxn*2],next_[maxn*2];
int total =0;
int dfn[maxn],low[maxn];
int num =0,sum =0,root;
bool cut[maxn];
void addedge(int a,int b){
       
    next_[++total] = first[a];
    first[a] = total;
    to[total] = b;
}
void tarjan(int x){
  //  cout <<x<<endl;
    int ans =0;
    num++;
    dfn[x] = num;
    low[x] = num;
    for(int i = first[x];i;i = next_[i]){
        int j = to[i];
        if(!dfn[j]){
            tarjan(j);
            if(low[j]<low[x])low[x] = low[j];
            if(low[j]>=dfn[x]){
                ans++;
                if(x!=root || ans>=2) cut[x] = true;
            } 
            
        }else if(dfn[j]<low[x]){
            low[x] = dfn[j];
        }
    }
}
void _solve(){
    cin >>n>>m;
    road.resize(n+1);
    for(int i =0;i<m;i++){
        int a,b;
        cin >> a>> b;
        addedge(a,b);
        addedge(b,a);
    }
    for(int i = 1;i<=n;i++){
        //cout <<i<<endl;
        if(!dfn[i]){
            root = i;
            tarjan(i);
        }
    }
    for(int i = 1;i<=n;i++)if(cut[i])sum++;
    cout <<sum<<'\n';
    for(int i = 1;i<=n;i++){
        if(cut[i])cout << i<<" ";
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }
}