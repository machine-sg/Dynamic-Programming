#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair


int LIS( ll arr[], ll n )  
{  
    ll lis[n]; 
   
    lis[0] = 1;    
  
    
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
  ll largest=INT_MIN;
  for(int i=0;i<n;i++){
      if(largest<lis[i]){
          largest=lis[i];
      }
      
  }
  return largest;
}  
int main(){
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll arr[2*n+1];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        arr[i+n]=arr[i];
	    }

	    
	    cout<<LIS(arr,2*n)<<'\n';
	}
	
    return 0;
}


