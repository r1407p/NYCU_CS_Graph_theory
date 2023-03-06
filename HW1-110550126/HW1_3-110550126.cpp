#include<bits/stdc++.h>
 
using namespace std;
 
#define eb emplace_back
#define pb push_back
#define ALL(X) X.begin(), X.end()
#define int long long

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

bool comp(int i ,int j){
    return i>j;
}
int bs(vi&nums,int i ,int j,int target){
    int ans = i-1;

    while(i<=j){
        int mid = (i+j)/2;
        if(nums[mid]>=target){
            i = mid+1;
            ans = mid;
        }else{
            j = mid-1;
        }
    }
    return ans;
}

void _solve(){
    int n,m;
    cin >> n>>m;
    vi tt(n,0);
    for(int i =0;i<n;i++){
        cin >> tt[i];
    }
    //cout <<"fsd";
    for(int i =0;i<m;i++){
        int a,b;
        cin >>a>>b;
        tt[a-1]--;
        tt[b-1]--;    
    }
    vi nums;
    int sum =0;
    for(int i =0;i<n;i++){
        if(tt[i]<0||tt[i]>=n){
            cout << "No\n";
            return;
        }if(tt[i]!=0){
            nums.eb(tt[i]);
            sum+=tt[i];
        }
    }
    if(sum%2){
        cout << "No\n";
        return;
    }
    sort(ALL(nums),comp);
    nums.insert(nums.begin(),0);
    // for(int i =0;i<nums.size();i++){
    //     cout<<nums[i]<<" ";
    // }cout<<'\n';
    
    // for(int i =0;i<nums.size();i++){
    //     cout<<total[i]<<" ";
    // }cout<<'\n';
    int limit =0;
    int now;
    int sz = nums.size();
    vi total(nums.size()+5,0);
    for(int i = nums.size()-1;i>=0;i--){
        total[i] = total[i+1]+nums[i];
    }
    for(int i =1;i<sz;i++){
        int pivot = upper_bound(nums.begin()+i+1,nums.end(),i,greater<int>())-nums.begin();
        limit+=nums[i];
        now = (i)*(pivot-1);
        now +=total[pivot+1];
        if(limit>now){
            cout <<"No\n";
            return;
        }
    }
//     for(int i =nums.size()-1;i>=0;i--){
//         int limit = total[i];
//         int now = (nums.size()-i)*(nums.size()-i-1);
//         int pivot = upper_bound(nums.begin(),nums.begin()+i,nums.size()-i)-nums.begin();
//         now+=total[0]-total[pivot];
//         now+=(i-pivot)*(nums.size()-i);
//    //     cout <<limit <<" "<<now<<'\n';
//         if(limit>now){
//             cout <<"No\n";
//             return;
//         }
//     }
    cout << "Yes\n";
    return;

}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int _ = 1;
    cin >>_;
    while(_--){
        _solve();   
    }

}