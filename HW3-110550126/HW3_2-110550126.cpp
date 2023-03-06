#include<bits/stdc++.h>
 
 
using namespace std;


#define int long long 
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
#define maxn 200005

//int a[maxn];
void shortest_path(vvpii& back,vl & ans,int source,int n){
    priority_queue<pii,vpii,greater<pii> >pq;
    pq.push({0,source});
    ans[source] =0;
    while(pq.size()){
        int go = pq.top().second;
        pq.pop();                                                                                                         
        for(auto i:back[go]){
            int w = i.first;
            int next = i.second;
            if(ans[next]==-1 || ans[next]>ans[go]+w){
                ans[next]=ans[go]+w;
                pq.push({ans[next],next});
            }
        }
    }
}
void _solve(int sub){
    int n ,m,k;
    cin >>n>>m>>k;
    vvpii back(n+5);
    for(int i =0;i<m;i++){
        int u,v,w;
        cin >> u >>v>>w;
        back[v].pb({w,u});
    }
    if(k==1){
        vl ans(n+5,-1);
        vl from(n+5,-1);
        shortest_path(back,ans,1,n);
        for(int i = 1;i<=n;i++){
            cout <<ans[i]<<" ";
        }
        cout << endl;
    }else{
        vl go1(n+5,-1);
        vl gon(n+5,-1);
        shortest_path(back,go1,1,n);
        shortest_path(back,gon,n,n);
        for(int i = 1;i<=n;i++){
            if(go1[i]!=-1&&gon[i]!=-1)
                back[n+1].pb({go1[i]+gon[i],i});
        }
        vl ans(n+5,-1);
        shortest_path(back,ans,n+1,n+1);
        for(int i =1;i<=n;i++){
            cout << ans[i]<<" ";
        }
        cout <<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1,temp;
    cin >>_>>temp;
    while(_--){
        _solve(temp);   
    }

}