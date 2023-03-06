#include <bits/stdc++.h>
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

vs strs;
vector<vector<int>> com(20,vector<int>(20,0));
void find(int i,int j){
    if(i==j){
        com[i][j] = 0;
        return;
    }
    int a = strs[i].size();
    int b = strs[j].size();
    int mn = min(a,b);
    int mx = 0;
    for(int k =1;k<=mn;k++){
        bool flag = true;
        for(int l = 0;l<k;l++){
            if(strs[i][a-k+l]!=strs[j][l]){
                flag = false;
                break;
            }
        }
        if(flag){
            mx = k;
        }
    }
    com[i][j] = mx;
}
int main(){
    int n;
    cin >>n;
    for(int i =0;i<n;i++){
        str temp;
        cin >>temp;
        strs.eb(temp);
    }
    //============eliminate the full sub start============
    for(int i  =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==j)continue;
            if(strs[i].find(strs[j])<strs[i].size()){
                strs[j] = " ";
            }
        }
    }
    for(int i =0;i<n;i++){
        if(strs[i]==" "){
            strs.erase(strs.begin()+i);
            i--;
            n--;
        }
    }
    sort(strs.begin(),strs.end(),greater<string>());
    //===============eliminate the full sub end============
    n = strs.size();
    // dp[mask][i] : min superstring made by strings in mask,
    // and the last one is A[i]
    //======================build the complete graph start=====================
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            find(i,j);
        }
    }
    //====================== build the complete graph end=====================
    vector<vector<string>> dp(pow(2,n),vector<string>(n));
    for(int i=0; i<n; i++) dp[pow(2,i)][i] += strs[i];
    
    /*
    for(int i =0;i<pow(2,n);i++){
        for(int j =0 ; j<n;j++){
            cout <<setw(15)<<left<< dp[i][j]<<" ";
        }
        cout << endl;
    }
    */
    // 3. fill the dp
    for(int i=1; i<(pow(2,n)); ++i){
        for(int j=0; j<n; ++j){   
            if((i&(1<<j))>0){
                for(int l=0; l<n; ++l){
                    if(l!=j && (i&(int)(pow(2,l)))>0){
                        string temp = dp[i^(1<<j)][l]+strs[j].substr(com[l][j]);
                        if(dp[i][j].empty() || temp.size()<dp[i][j].size()){
                            dp[i][j] = temp;
                        }
                    }
                }
            }
        }
    }
    /*
    for(int i =0;i<(1<<n);i++){
        for(int j =0;j<n;j++){
            cout <<setw(15)<<left<<dp[i][j];
        }
        cout <<endl;
    }
    */
    /*
    for(int i = 1;i<pow(2,n);i++){
        for(int j  =0;j<n;j++){
            if(i&(pow(2,j)>0)){
                for(int l =0;l<n;l++){
                    if(j!=l && (i&(pow(2,i))>0)){
                        string temp = dp[i^(int)(pow(2,j))][l].substr(com[l][j]);
                        if(dp[i][j].empty() || temp.size()<dp[i][j].size()){
                            dp[i][j] = temp;
                        }
                    }
                }
            }
        }
    }
    */
    // 4. get the result
    int last = pow(2,n)-1;
    string res = dp[last][0];
    for(int i=1; i<n; ++i) if(dp[last][i].size()<res.size()){
        res = dp[last][i];
    }
    cout << res;
}