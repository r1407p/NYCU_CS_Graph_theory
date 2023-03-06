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
//ifstream fin("test.in");
//ofstream fout("test.out");
int n ,m,k, total;
bool bfs(vector<unordered_map<int,int>> & rgraph, int s, int t, vi& parent)
{
    vb vis(total);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &m:rgraph[u]) {
            if (!vis[m.first]&& m.second> 0) {
                if (m.first == t) {
                    parent[m.first] = u;
                    return true;
                }
                q.push(m.first);
                parent[m.first] = u;
                vis[m.first] = true;
            }
        }
    }
    return false;
}
int ford(vector<unordered_map<int,int>>  &graph ,int s,int t){
    int u, v;
    vector<unordered_map<int,int>> rgraph = graph;
    vi parent(total,0);

    int max_flow = 0; 
 
    while (bfs(rgraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;

}
void _solve(){
    cin >> n>>m>>k;
    /*
    0: source 
    1: the first of hero
    2: the posion to hero
    3~n+2: heroes
    n+3~n+2+m: monsters
    2+n+m+1:  the max kill
    */
    total = n+m+4;
    vector<unordered_map<int,int>> graph(total);
    graph[0][1] = n;
    graph[0][2] = k;
    for(int i = 0,j =3;i<n;i++,j++){
        int t;
        cin >> t;
        graph[1][j] = 1;
        graph[2][j] = 1;
        for(int p =0;p<t;p++){
            int temp;
            cin >> temp;
            int mon = temp+n+2;
            graph[j][mon] = 1;
            graph[mon][total-1] = 1;
        }        
    }
    cout << ford(graph,0,n+m+3);
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