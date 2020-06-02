#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair


int main(){
	int n;
	cin>>n;
	int s[n], b[n];
	int lis[n], p[n-1]={-1};
	lis[0]=1;
	int max_size=INT_MIN, last_pos=-1;
	
	for(int i=0;i<n;i++)cin>>s[i]>>b[i];
	
	for(int i=1;i<n;i++){
	    lis[i]=1;
	    for(int j=0;j<i;j++){
	        if(s[i]>s[j] && b[i]>b[j] && lis[i]<lis[j]+1){
	            lis[i]=lis[j]+1;
	            p[i]=j; //for storing the ancestors
	        }
	    }
	    if(max_size<lis[i]){
	        max_size=lis[i];
	        last_pos=i;
	    }
	}
	cout<<max_size<<'\n';
	vector<int> subseq;
	while(last_pos!=-1){
	    subseq.pb(last_pos+1);
	    last_pos=p[last_pos];
	}
	reverse(subseq.begin(), subseq.end());
	for(int i=0;i<max_size;i++)
	{
	    cout<<subseq[i]<<" ";
	}
    return 0;
}


