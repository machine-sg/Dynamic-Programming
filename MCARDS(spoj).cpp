#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair
#define INF 1e9
#define fi first
#define sc second


vector<int> v;
int c,n;

int lis(){
	int size = c*n;
	int dp[size];

	for(int i=0;i<size;i++){dp[i]=1;}
	for(int i=1;i<size;i++){
		for(int j=0;j<i;j++){
			if(v[i] > v[j]){dp[i] = max(dp[i],dp[j]+1);}
		}
	}
	int res=0;
	for(int i=0;i<size;i++){res=max(res,dp[i]);}
	return res;
}

int main(){
	
	cin>>c>>n;

	int color[c*n],num[c*n];
	for(int i=0;i<c*n;i++){
		cin>>color[i]>>num[i];
	}
	
	vector<int> per;
	for(int i=0;i<c;i++){per.push_back(i);}

	int ans = INT_MAX;
	do{
	
		int cnt=0;
		int arr[c][n];
		for(int i=0;i<c;i++){
			for(int j=0;j<n;j++){
				arr[per[i]][j]=cnt++;
			}
		}
		v.clear();
		for(int i=0;i<c*n;i++){
			v.push_back(arr[color[i]-1][num[i]-1]);
		}
	
		int x = lis();
		//cout<<x<<endl;
		ans = min(ans,c*n - x);
	}while(next_permutation(per.begin(),per.end()));
	
	cout<<ans<<endl;
}
