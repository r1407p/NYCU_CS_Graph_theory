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
deque<pii> joint;
int vis[maxn];
int lll;
int rrr;
void dfs(int pivot ,bool right){
    //cout << pivot <<" "<<right<< endl;
    bool end[2];
    int length[2];
    int next[2];
    int del[2];
    for(int j =0;j<2;j++){
        int now =0;
        int temp = nums[pivot][j];
        int prev = pivot;
        //cout <<"\t"<< temp<<endl;;
        while(nums[temp].size()==2){
            //cout << temp<<endl;
            now++;
            if(nums[temp][0]==prev){
                prev = temp;
                temp = nums[temp][1];
            }else{
                prev = temp;
                temp = nums[temp][0];
            }
        }
        if(nums[temp].size()==1){
            end[j] = true;
            length[j] = now+1;
        }else{
            end[j] = false;
            next[j] = temp;
            del[j] = prev;
        }
    }
    if(end[0]){// 
        if(end[1]){ // 11
            if(right){
                joint.pb({pivot,length[0]});
                rrr = length[1];
            }else{
                joint.push_front({pivot,length[0]});
                lll = length[1];
            }
        }else{      // 1 0 
            if(right){
                joint.pb({pivot,length[0]});
                nums[next[1]].erase(find(ALL(nums[next[1]]),del[1]));
                dfs(next[1],right);
            }else{
                joint.push_front({pivot,length[0]});
                nums[next[1]].erase(find(ALL(nums[next[1]]),del[1]));
                dfs(next[1],right);
            }
        }
    }else{          // 0 1
        joint.pb({pivot,length[1]});
        nums[next[0]].erase(find(ALL(nums[next[0]]),del[0]));
        dfs(next[0],right);
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
    for(int i =0;i<n;i++){
        if(nums[i].size()==3){
           
            bool end[3];
            int length[3];
            int next[3];
            int del[3];
            for(int j =0;j<3;j++){
                int now =0;
                int temp = nums[i][0];
                int prev = i;
                nums[i].erase(nums[i].begin());
                while(nums[temp].size()==2){
                    //cout << temp<<endl;
                    now++;
                    if(nums[temp][0]==prev){
                        prev = temp;
                        temp = nums[temp][1];
                    }else{
                        prev = temp;
                        temp = nums[temp][0];
                    }
                }
                if(nums[temp].size()==1){
                    end[j] = true;
                    length[j] = now+1;
                }else{
                    end[j] = false;
                    next[j] = temp;
                    del[j] = prev;
                }
            //    cout <<end[j]<<" " <<length[j]<<" "<<next[j]<<endl;
            }
            if(end[0]){
                if(end[1]){// 1 1 0
                    joint.pb({i,length[0]});
                    lll = length[1];
                    nums[next[2]].erase(find(ALL(nums[next[2]]),del[2]));
                    dfs(next[2],true);
                }else{
                    if(end[2]){ //1 0 1
                        joint.pb({i,length[0]});
                        lll = length[2];
                        nums[next[1]].erase(find(ALL(nums[next[1]]),del[1]));
                        dfs(next[1],true);
                    }else{      //1 0 0 
                        joint.pb({i,length[0]});
                        nums[next[1]].erase(find(ALL(nums[next[1]]),del[1]));
                        nums[next[2]].erase(find(ALL(nums[next[2]]),del[2]));
                        dfs(next[1],true);
                        dfs(next[2],false);
                    }
                }
            }else{
                if(end[1]){
                    if(end[2]){//0 1 1 
                        joint.pb({i,length[2]});
                        lll = length[1];
                        nums[next[0]].erase(find(ALL(nums[next[0]]),del[0]));
                        dfs(next[0],true);
                    }else{  //0 1 0
                        joint.pb({i,length[1]});
                        nums[next[0]].erase(find(ALL(nums[next[0]]),del[0]));
                        nums[next[2]].erase(find(ALL(nums[next[2]]),del[2]));
                        dfs(next[0],true);
                        dfs(next[2],false);
                    }
                }else{ // 0 0 1
                     joint.pb({i,length[2]});
                     nums[next[1]].erase(find(ALL(nums[next[1]]),del[1]));
                     nums[next[0]].erase(find(ALL(nums[next[0]]),del[0]));
                     dfs(next[1],true);
                     dfs(next[0],false);
                }
            }
            break;
        }
    }
    //=====================end=======
    // (lll) deque (rrr)  
    vi ans;
    while(joint.size()){
        ans.pb(joint.front().second);
        joint.pop_front();
    }
    vi sis;
    cin >>n;
    for(int i =0;i<n;i++){
        int temp;
        cin >> temp;
        sis.pb(temp);
    }  
    vvi cmp(8);
    for(int i =0;i<4;i++){
        cmp[i]=vi(ALL(ans));
    }
    reverse(ALL(ans));
    for(int i =0;i<4;i++){
        cmp[4+i]=vi(ALL(ans));
    }
    cmp[0][0] = lll;
    cmp[1][0] = lll;
    cmp[1][n-1] = rrr;
    cmp[2][n-1] = rrr;
    cmp[4][0] = rrr;
    cmp[5][0] = rrr;
    cmp[5][n-1] = lll;
    cmp[6][n-1] = lll;
    //cout <<"dfs";
    for(int i =0;i<8;i++){
        if(cmp[i]==sis){
            cout <<"YES"<<'\n';
            return;
        }
    }
    cout << "NO"<<'\n';



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