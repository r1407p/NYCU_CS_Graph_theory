#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

int main(){
    map<int,int> mp;
    int _;
    cin >>_;
    while(_--){
        int temp;
        cin >>temp;
        mp[temp]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto m:mp){
        pq.push(make_pair(m.second,m.first));
    }
    cout << pq.top().second <<" "<< pq.top().first<<endl;
}
