#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define pi pair<int,int>
#define gcd(a,b) __gcd((a),(b))
#define endl "\n"
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PI 3.1415926535897932384626433832795



int main() {

/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
	cin>>TC;
	while(TC--)
	{
	    int amount,n;
	    cin>>amount>>n;
	    int coins[n];
	    for(int i=0;i<n;i++){
	        cin>>coins[i];
	    }
		int dp[amount+1];
        
        for(int i=0;i<amount+1;i++){
            dp[i]=amount+1;
        }
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==amount+1) cout<<"No solution"<<endl;
        else cout<<dp[amount]<<endl;
	}
	return 0;
}

