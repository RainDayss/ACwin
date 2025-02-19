#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
int v[MAX],w[MAX];
int dp[MAX][MAX];

int main(){
    int n,V;
    cin>>n>>V;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=V;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) {
                dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][V]<<endl;
    //һγ
    vector<int> dp1(vector<int>(V+1));
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=V;j++){
            dp1[j]=max(dp1[j],dp1[j-w[i]]+v[i]);
        }
    }
    cout<<dp1[V]<<endl;
    return 0;
}