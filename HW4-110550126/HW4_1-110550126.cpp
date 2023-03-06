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
class node{
public:
    int time = -1;
    int status = 0;
};
void _solve(){
    int n ,m,p,q,t,T;
    cin >> n>>m>>p>>q>>t>>T;
    vector<node>status(n+1);
    vvpii inf(n+1);
    vvi pro(n+1);
    for(int i =0;i<m;i++){
        int a,b,w;
        cin >>a>>b>>w;
        inf[a].pb({w,b});
        pro[a].pb(b);
    }
    queue<pii> start;
    for(int i=0;i<p;i++){
        int temp;
        cin >>temp;
        start.push({temp,0});
    }
    queue<int> save;
    for(int i =0;i<q;i++){
        int temp;
        cin >> temp;
        save.push(temp);
    }
    for(int i = t;i<=T;i++){
        int now = save.size();
        for(int j =0;j<now;j++){
            int temp = save.front();
            save.pop();
            if(status[temp].time==-1){
                status[temp].status = 1;
                status[temp].time = i;
                for(auto r:pro[temp])save.push(r);
            }
        }
    }
    // for(int i =1;i<=n;i++){
    //     cout << status[i].status<<" "<<status[i].time<<endl;
    // }
    while(!start.empty()){
        auto now = start.front();
        start.pop();
        if(!status[now.first].status||status[now.first].time>now.second&&now.second<=T){
            status[now.first].time = now.second;
            status[now.first].status = -1;
            for(auto s:inf[now.first]){
                start.push({s.second,s.first+now.second});
            }
        }
    }
    // cout <<"dsfds\n";
    // for(int i =1;i<=n;i++){
    //     cout << status[i].status<<" "<<status[i].time<<endl;
    // }
    int ans =0;
    for(int i =1;i<=n;i++){
        if(status[i].status==-1)ans++;
    }
    cout << ans;



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