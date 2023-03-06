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
typedef vector<vvi>vvvi;
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
int  sear(int a,vi &join){
    if(join[a] == a)return a;
    int temp = sear(join[a],join);
    join[a] = temp;
    return temp;   
}
void con(int a,int b,vi &join){
    int tempa = sear(a,join);
    int tempb = sear(b,join);
    join[tempa] = tempb;
}
int findminweight(vi& wei, vb& vis,int n){
    int pivot =1;
    int mn = INT_MAX;
    for(int i = 1;i<=n;i++){
        if(!vis[i]&&wei[i]<mn){
            mn = wei[i];
            pivot = i;
        }
    }
    return pivot;
}
void _solve(){
    vi join;
    int n,m;
    cin >>n>>m;
    vi cost(n+5);
    int pivot = -1;
    int mncost = INT_MAX;
    for(int i =1;i<=n;i++){
        cin >> cost[i];
        if(cost[i]<mncost){
            pivot = i;
            mncost = cost[i];
        }
    }
    vvpii edges(n+5);
    for(int i =1;i<pivot;i++){
        edges[i].pb({mncost+cost[i],pivot});
        edges[pivot].pb({mncost+cost[i],i});
    }
    for(int i = pivot+1;i<=n;i++){
        edges[i].pb({mncost+cost[i],pivot});
        edges[pivot].pb({mncost+cost[i],i});
    }
    for(int i =0;i<m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        edges[a].pb({c,b});
        edges[b].pb({c,a});
    }
    priority_queue<pii,vpii,greater<pii>> pq;
    vb vis(n+5);
    vis[1] = 1;
    for(int i =0;i<edges[1].size();i++){
        pq.push(edges[1][i]);
    }
    loli ans =0;
    for(int i =1;i<n;i++){
        int w = pq.top().first;
        int to = pq.top().second;
        while(vis[to]){
            pq.pop();
            w = pq.top().first;
            to = pq.top().second;
        }
        ans+=w;
        vis[to] = 1;
        for(int j =0;j<edges[to].size();j++){
            if(!vis[edges[to][j].second]){
                pq.push(edges[to][j]);
            }
        }
    }
    // for(int i = 1;i<=n;i++){
    //     int now = findminweight(wei,vis,n);
    //     vis[now] = true;
    //     for(int j =0;j<edges[now].size();j++){
    //         int w = edges[now][j].first;
    //         int to= edges[now][j].second;
    //         if(!vis[to]&&w<wei[to]){
    //             from[to] = now;
    //             wei[to] = w;
    //         }
    //     }
    // }
    cout << ans<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >>_;
    while(_--){
        _solve();   
    }

}