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

int n;
pi a[10000001];
bool sortbyw(const pi &a, 
              const pi &b) 
{ 
    if(a.fi==b.fi)
        return a.sc<b.sc;
    return (a.fi > b.fi); 
} 

void go(){
    vector<pi> LIS;
    LIS.pb(a[0]);
    for(int i=1;i<n;i++){
        int low=0, high=LIS.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(LIS[mid].sc<=a[i].sc){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(low==LIS.size()){
            LIS.pb(a[i]);
        }
        else{
            LIS[low].fi=a[i].fi;
            LIS[low].sc=a[i].sc;
        }
    }
    cout<<LIS.size()<<'\n';
}

int main(){
	int t;
	cin>>t;
	while(t--){
	   cin>>n;
	   for(int i=0;i<n;i++){
	       cin>>a[i].fi>>a[i].sc;
	   }
	   sort(a,a+n, sortbyw);
	   go();
	}
	
    return 0;
}


