#include<bits/stdc++.h>
 
 
using namespace std;
 
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

void _solve(){
    int n,m;
    cin >> n>>m;
    //cout <<n<<m;
    vi tt(n,0);
    int mx =0;
    for(int i =0;i<n;i++){
        cin >> tt[i];
        mx = max(tt[i],mx);
    }
    //cout <<"fsd";
    for(int i =0;i<m;i++){
        int a,b;
        cin >>a>>b;
        tt[a-1]--;
        tt[b-1]--;    
    }
 //   cout <<"sdfsd";
    vi nums(mx+1,0);
    for(int i =0;i<n;i++){
        if(tt[i]<0){
            cout << "No\n";
            return;
        }
        nums[tt[i]]++;
    }
    
    int i = mx;//
    while(i){
        bool fg = false;
        if(nums[i]==0){
            i--;
            continue;
        }
        nums[i]--;
        int total = i;
        int temp =0;
        int now =0;
        int pivot = i;

       
        while(now<total){
            if(pivot==0){
                cout << "No\n";
                return;
            }
            int a = total-now;
            if(a<=nums[pivot]){
           //     cout <<"A"<<endl;
                nums[pivot]-=a;
                nums[pivot-1]+=a;
                now+=a;
                if(!fg){
                    if(nums[pivot]){
                        i= pivot;
                    }else{
                        i = pivot-1;
                    }
                }
            }else{
                now+=nums[pivot];
                swap(temp,nums[pivot]);
                if(nums[pivot]&&!fg){
                    i = pivot;
                    fg = true;
                }
                pivot--;
            }
        }
    }
    cout <<"Yes\n";   
}

int main(){
    int _ = 1;
    cin >>_;
    while(_--){
        _solve();   
    }

}