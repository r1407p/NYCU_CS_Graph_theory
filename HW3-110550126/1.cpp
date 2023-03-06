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
void countsort(vvi&edges,int now){
    vvi temp(edges.size());
    int count[1000] = {0};
    for(auto e:edges){
        count[(e[0]/now)%1000]++;
    }
    for(int i =1;i<1000;i++){
        count[i]+=count[i-1];
    }
    for(int i = edges.size()-1;i>=0;i--){
        temp[count[(edges[i][0]/now)%1000]-1] = edges[i];
        count[(edges[i][0]/now)%1000]--;
    }
    for(int i =0;i<edges.size();i++){
        edges[i] = temp[i];
    }

}
void radix_sort(vvi& edges){
    int now =1;
    countsort(edges,now);
    for(int i =0;i<2;i++){
        now*=1000;
        countsort(edges,now);
        
    }
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
    vvi edges;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        int temp = c-mncost;
        if(a==pivot){
            cost[b] = min(cost[b],temp);
        }else if(b==pivot){
            cost[a] = min(cost[a],temp);
        }else{
            if(temp<=cost[a]||temp<=cost[b])
                edges.pb({c,a,b});
        }
    }
    for(int i =1;i<pivot;i++){
        edges.pb({mncost+cost[i],i,pivot});
    }
    for(int i = pivot+1;i<=n;i++){
        edges.pb({mncost+cost[i],i,pivot});
    }
    m = edges.size();
    sort(ALL(edges));
    //radix_sort(edges);
    join.resize(n+5);
    for(int i =0;i<=n;i++)join[i] = i;
    loli ans =0;
    int used = 0;
    for(int i =0;i<m&&used!=n-1;i++){
        if(sear(edges[i][1],join)!=sear(edges[i][2],join)){
            used++;
            con(edges[i][1],edges[i][2],join);
            ans+=edges[i][0];
        }
    }
    cout << ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >>_;
    while(_--){
        _solve();   
    }

}