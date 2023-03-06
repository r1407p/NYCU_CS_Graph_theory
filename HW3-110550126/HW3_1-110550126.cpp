#include<bits/stdc++.h>
 
 
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

int  sear(int a,vi &join){
    if(join[a] == a)return a;
    return (join[a]=sear(join[a],join));
}
void con(int a,int b,vi &join){
    join[sear(a,join)] = sear(b,join);
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
    //cout <<pivot <<" "<<mncost;
    vvi edges(n+m-1);
    int now =0;
    for(int i =1;i<pivot;i++){
        edges[now++] = {mncost+cost[i],i,pivot};
    }
    for(int i = pivot+1;i<=n;i++){
        edges[now++] = {mncost+cost[i],i,pivot};
    }
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        if(a==pivot){
            if(c<=mncost+cost[b]){
                edges[now++] = {c,a,b};        
            }
        }else if(b==pivot){
            if(c<=mncost+cost[a]){
                edges[now++] = {c,a,b};        
            }
        }else{
            edges[now++] = {c,a,b};
        }
    }
    //cout <<"dsf"<<m<<endl;
    join.resize(n+5);
    for(int i =0;i<=n;i++)join[i] = i;
    m = now;
    loli ans =0;
    vi  out_wei(n+5);
    vi  out_index(n+5);
    vb used(m);
    while(1){
        int cross =0;
        for(int i =1;i<=n;i++)out_wei[i] = INT_MAX;
        for(int i =0;i<m;i++){
            int a = sear(edges[i][1],join);
            int b = sear(edges[i][2],join);
            int c = edges[i][0];
            if(a==b)continue;
            cross++;
            if(c<out_wei[a]||c==out_wei[a]&&i<out_index[a])
                out_wei[a] = c,out_index[a] = i;
            if(c<out_wei[b]||c==out_wei[b]&&i<out_index[b])
                out_wei[b] = c,out_index[b] = i;
        }
        if(!cross)break;
        // cout << "dsfsdfsdfsdf"<<endl;
        // for(int i =1;i<=n;i++){
        //     cout << out_wei[i]<<" "<<out_index[i]<<endl;

        // }
        for(int i =1;i<=n;i++){
            if(out_wei[i]!=INT_MAX){
                if(!used[out_index[i]]){
                    used[out_index[i]] = true;
                    ans+=edges[out_index[i]][0];
                }
                con(edges[out_index[i]][1],edges[out_index[i]][2],join);
            }
        }
    }
    cout << ans<<'\n';
    /*
    sort(ALL(edges));
    loli ans =0;
    int used = 0;
    for(int i =0;i<m&&used!=n-1;i++){
        if(sear(edges[i][1],join)!=sear(edges[i][2],join)){
            used++;
            con(edges[i][1],edges[i][2],join);
            ans+=edges[i][0];
        }
    }
    */
    //cout <<ans<<'\n';
    
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >>_;
    while(_--){
        _solve();   
    }

}