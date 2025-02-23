#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e3+10;
int v[MAX],w[MAX];
int dp[MAX][MAX];

int main(){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
        for(int i=0;i<=n;i++) {dp[0][i]=0;dp[i][0]=0;}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=v[i]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
                } 
            }
        }
    cout<<dp[n][m]<<endl;

 //----------------------一维优化
    int dp1[MAX]={0};
    for(int i=1;i<=n;i++){
        // for(int j=m;j>=1;j--){
        //     if(j>=v[i]) dp1[j]=max(dp1[j],dp1[j-v[i]]+w[i]);
        // }
        for(int j=m;j>=v[i];j--) dp1[j]=max(dp1[j],dp1[j-v[i]]+w[i]);
    }
    cout<<dp1[m]<<endl;

    return 0;
}
