#include<bits/stdc++.h>
 
 
using namespace std;
 

#define eb enplace_back
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

struct node{
    int n;
    bool fg = false;
    vector<int> nei;
    node(){

    }
};
void _solve(){
    int n ,m,k,t;
    cin >> n>>m>>k>>t;
    vector<node> nums(n+1,node());
    int ans =k;
    for(int i =0;i<m;i++){
        int a,b;
        cin >>a>>b;
        nums[a].nei.pb(b);
    }
    queue<int> q;
    for(int i =0;i<k;i++){
        int a;
        cin >>a;
        nums[a].fg = true;
        q.push(a);
    }
    /*
    for(int i =1;i<=n;i++){
        cout << i<<":";
        for(int j =0;j<nums[i].nei.size();j++){
            cout << nums[i].nei[j]<<" ";
        }
        cout << endl;
    }
    */
    for(int i =1;i<t;i++){
        if(q.empty())break;
        int nn = q.size();
        for(int i =1;i<=nn;i++){
            //cout << q.front() <<":";
            for(auto s:nums[q.front()].nei){
                //cout << s<<" ";
                if(!nums[s].fg){
                    q.push(s);
                    ans++;    
                }
            }

         //   cout << endl;
            q.pop();
        }
    }
    cout <<ans;
}
int main(){
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }

}