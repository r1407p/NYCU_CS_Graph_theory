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
#define maxn 1000006
ifstream fin("test.txt");
vvi nums(maxn);
bool joint[maxn];
vi ans;
unordered_map <int,vector<int>> mp;
void dfs(int pivot,int prev){
    if(joint[pivot] == true){
        if(mp[pivot].size()==2){
            ans.pb(mp[pivot][0]);
            ans.pb(mp[pivot][1]);
            return;
        }else{
            ans.pb(mp[pivot][0]);
        }
    }
    if(nums[pivot][0]!=prev){
        dfs(nums[pivot][0],pivot);
    }else{
        dfs(nums[pivot][1],pivot);
    }
}
void _solve(){
    int n ;
    cin >>n;
    for(int i =1;i<n;i++){
        int a,b;
        cin >> a>>b;
        nums[a].eb(b);
        nums[b].eb(a);
    }
    queue<int> qu; //or stack vector
    for(int i =0;i<n;i++){
        if(nums[i].size()==1){
            qu.push(i);
            
        }else if(nums[i].size()==3){
            joint[i] = true;
        }

    }



    while(qu.size()){
        int prev = qu.front();
        int temp = nums[prev][0];
        qu.pop();
        int now = 0;
        while(1){
            now++;
            if(joint[temp]){
                mp[temp].pb(now);
                nums[temp].erase(find(ALL(nums[temp]),prev));
                break;
            }
            if(nums[temp][0]==prev){
                prev = temp;
                temp = nums[temp][1];
            }else{
                prev = temp;
                temp = nums[temp][0];
            }
        }
    }
    for(auto m:mp){
        if(m.second.size()==2){
            ans.pb(m.second[0]);
            ans.pb(m.second[1]);
            dfs(nums[m.first][0],m.first);
            break;
        }
    }
    //================================
    vi sis;
    int m;
    cin >>m;
    for(int i =0;i<m;i++){
        int temp;
        cin >> temp;
        sis.pb(temp);
    }  
    bool flag = false;
    if(ans.size()== m+2){
        if(ans[0]==sis[0]||ans[1]==sis[0]){
            if(ans[m+1]==sis[m-1]||ans[m]==sis[m-1]){
                flag = true;
                for(int i =1;i<m-1;i++){
                    if(ans[i+1]!=sis[i]){
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    if(flag){
        cout <<"YES\n";
        return;
    }
    reverse(ALL(ans));
    flag = false;
    if(ans.size()== m+2){
        if(ans[0]==sis[0]||ans[1]==sis[0]){
            if(ans[m+1]==sis[m-1]||ans[m]==sis[m-1]){
                flag = true;
                for(int i =1;i<m-1;i++){
                    if(ans[i+1]!=sis[i]){
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    if(flag){
        cout <<"YES\n";
        return;
    }
    cout << "NO\n";
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