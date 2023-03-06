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
#define maxn 200005
//int a[maxn];
int total;
int nums =0;
int dist[200],work[200];
struct Edge{
    int to,rev;
    int flow, cap;
};
inline void adde(vector<vector<Edge>> &indexs,int s,int t,int cap){
    Edge a = {t, (int)indexs[t].size(), 0, cap};
    Edge b = {s, (int)indexs[s].size(), 0, 0};
    indexs[s].push_back(a);
    indexs[t].push_back(b);
}
bool bfs(vector<vector<Edge>> &rgraph,int s,int t){
    fill(dist, dist + total, -1);
    dist[s] = 0;
    int qt = 0;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int u = q.front();q.pop();
        for (int j = 0; j < (int) rgraph[u].size(); j++) {
        Edge &e = rgraph[u][j];
        int v = e.to;
            if (dist[v] < 0 && e.flow < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] >= 0;
}
int dfs(vector<vector<Edge>> &rgraph,int s,int t,int mx){
   
    if (s == t)return mx;
    for (int &i = work[s]; i < (int) rgraph[s].size(); i++) {
        Edge &e = rgraph[s][i];
        if (e.cap <= e.flow) continue;
        int v = e.to;
        if (dist[v] == dist[s] + 1) {
        int df = dfs(rgraph,v,t, min(mx, e.cap - e.flow));
        if (df > 0) {
            e.flow += df;
            rgraph[v][e.rev].flow -= df;
            return df;
        }
        }
    }
    return 0;
}

int ford(vector<vector<Edge>>  &indexs ,int s,int t){
    vector<vector<Edge>> rgraph = indexs;
    int max_flow = 0;
    while(bfs(rgraph,s,t)){
        memset(work,0,sizeof(work));
        while(true){
            int path_flow = dfs(rgraph,s,t,INT_MAX);
            if(!path_flow)break;
            max_flow+=path_flow;
           // cout << max_flow;
        }
    }
    //cout <<s << " "<<t <<" "<<max_flow <<endl;
    return max_flow;
}
void _solve(){
    int n ,m;cin >> n>> m;
    total = 2*n+1;
    vector<vector<Edge>> graph(2*n+1);
    for(int i =1;i<=n;i++){
        adde(graph,2*i-1,2*i,1);
    }
    for(int i = 0;i<m;i++){
        int a,b;cin >> a>>b;
        //a -> 2*a-1 2*a
        //b -> 2*b-1 2*b
        adde(graph,2*a,2*b-1,1000);
        adde(graph,2*b,2*a-1,1000);
    }
    //while(n==4&&m==4)cout <<"?"<<endl;
    if(2*m == n*(n-1)){
        cout <<n-1<<endl;
        return;
    }
    // for(int i = 1;i<2*n+1;i++){
    //     for(int j =0;j<graph[i].size();j++){
    //         cout << graph[i][j].to<<" "<<graph[i][j].cap<<endl;;
    //     }
    //     cout <<endl;
    // }
    int mn = INT_MAX;
    for(int i =1;i<=n;i++){
        for(int j =i;j<=n;j++){
            mn = min(mn,ford(graph,2*i,2*j-1));
        }
    }
    cout <<mn<<endl;
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