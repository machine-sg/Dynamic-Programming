#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair

int rob(int nums[],int n) {
       // int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int left[n],right[n];
           left[0] = nums[0];              
            right[n-1] = nums[n-1];
           left[1] = max(nums[0],nums[1]);  
            right[n-2] = max(nums[n-1],nums[n-2]); 
        
		for(int i=2;i<n-1;i++){
             left[i] = max(left[i-1],nums[i]+left[i-2]);
          }
        
		for(int i = n-3;i>0;i--){
              right[i] = max(right[i+1],nums[i]+right[i+2]); 
          }
	   
	   return (right[1]>left[n-2] ? right[1] : left[n-2]);
    }
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rob(a,n);
    return 0;
}

