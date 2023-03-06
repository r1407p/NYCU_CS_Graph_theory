#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main(){
    int n ,a,b,c;
    cin >> n>>a>>b>>c;
    for(int i =0;i<n;i++){
        int temp =0;
        for(int j =0;j<n;j++){
            int result;
            cin >> result;
            if(i==j)continue;
            if(result==0)
                temp +=b;
            else if (result ==1)
                temp +=a;
            else if (result==2)
                temp +=c;
            
        }
        cout << temp << " ";
    }
    

}