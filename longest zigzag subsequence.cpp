#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair


int ZigZag(int arr[],int n){
    int z[n][2];
  //  z[0][0]=1, z[0][1]=1;
     for (int i = 0; i < n; i++) 
        z[i][0] = z[i][1] = 1; 
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && z[i][0]<z[j][1]+1){
                z[i][0]=z[j][1]+1;
            }
            if(arr[i]<arr[j] && z[i][1]<z[j][0]+1){
                z[i][1]=z[j][0]+1;
            }
        }
    }
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(largest<max(z[i][0],z[i][1])){
            largest=max(z[i][0],z[i][1]);
        }
    }
    return largest;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<ZigZag(a,n);
    return 0;
}


