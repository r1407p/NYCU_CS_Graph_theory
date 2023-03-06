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
vvi nums(maxn);
bool used[maxn];
vvi ans(maxn,vi({-1,0}));
int height =0;
queue<int> qu;
void build(int pivot,int parent){
    ans[pivot][1] = parent;
    used[pivot] = true;
    bool flag = true;
    for(int i=0;i<nums[pivot].size();i++){
        
        if(!used[nums[pivot][i]]){
            build(nums[pivot][i],pivot);
            flag = false;
        }
        
    }
    if(flag)qu.push(pivot);
}
void hei(){
    while(qu.size()){
        int now = qu.front();
        int height = 0;
        while(1){
            //cout << now<<" ";
            if(now == -1)break;
            if(ans[now][0]>=height){
                break;
            }else{
                ans[now][0] = height;
            }
            now = ans[now][1];
            height++;
        }
        qu.pop();
    }
}
void _solve(){
    int n; cin >>n;
    for(int i =1;i<n;i++){
        int a ,b;
        cin >> a>>b;
        nums[a].eb(b);
        nums[b].eb(a);
    }
    build(1,-1);
    

    hei();
    for(int i =1;i<=n;i++){
        cout << ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}
signed main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }

}