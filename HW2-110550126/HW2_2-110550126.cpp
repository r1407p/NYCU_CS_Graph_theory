#include<bits/stdc++.h>
 
 
using namespace std;


//#define int long long 
#define endl '\n'
#define eb emplace_back
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
class node{
public:
    vi parent;
    vi child;
    int lay;
    node(){
        this->lay = -1;
        this->parent =vi(25,0);
    }
};
vvi nums(300005);
vector<node> nodes(300005,node());
int ans(int a,int b){
    int tmpa = a,tmpb = b;
    if(nodes[b].lay<nodes[a].lay)swap(a,b);//make b be greater
    int diff = nodes[b].lay-nodes[a].lay;
    if(diff){
        for(int i =0;i<20;i++){
            if(diff%2){
                b = nodes[b].parent[i];
            }
            diff/=2;
        }
    }
    //cout <<a<<" "<<b<<endl;
    if(a==b)return a;
    for(int i =19;i>=0;i--){
        if(nodes[a].parent[i]!=nodes[b].parent[i]){
            a = nodes[a].parent[i];
            b = nodes[b].parent[i];
        }
    }
    //cout <<nodes[a].parent[0]<<endl;;
    return nodes[a].parent[0];
    
    
}
void _solve(){
    int n;
    cin >>n;
    for(int i =1;i<n;i++){
        int a,b;
        cin >> a>>b;
        nums[a].eb(b);
        nums[b].eb(a);
    }
    queue<int> pq;
    pq.push(1);
    int sz =  1;
    int now = 0;
    nodes[1].lay = 0;
    /*
    for(int i =0;i<=n;i++){
        for(int j =0;j<nums[i].size();j++){
            cout << nums[i][j]<<" ";

        }
        cout << endl;
    }
    */
    while(sz){
        for(int i =0;i<sz;i++){
            int temp = pq.front();
            //cout << temp<<endl;;
            nodes[temp].lay = now;
            for(int j =0;j<nums[temp].size();j++){
                //cout <<"    "<<nums[temp][j]<<endl;
                if(nodes[nums[temp][j]].lay==-1){//unused
                    nodes[nums[temp][j]].parent[0] = temp;
                    pq.push(nums[temp][j]);
                    nodes[temp].child.eb(nums[temp][j]);
                }
            }
            pq.pop();
        }
        sz = pq.size();
        now++;
    }
    
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            nodes[j].parent[i] = nodes[nodes[j].parent[i-1]].parent[i-1];
        }
    }
    int k;
    cin >> k;
    while(k--){
        int a,b;
        cin >>a>>b;
        int temp  = ans(a,b);
        cout <<nodes[a].lay+nodes[b].lay-2*nodes[temp].lay<<'\n';
        //cout <<k<<endl;
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