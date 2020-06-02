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


int howMany(int size,int s1,int s2,int e1,int e2,int numMoves){
    int dp[101][101][50];
    dp[s1][s2][0]=1;
    int dr[]={1,-1,0,0,1,-1,1,-1,1,1,-1,-1,2,-2,2,-2};
    int dc[]={0,0,1,-1,1,-1,-1,1,2,-2,2,-2,1,1,-1,-1};
    
    for(int i=1;i<=numMoves;i++){
        for(int r=0;r<size;r++){
            for(int c=0;c<size;c++){
                for(int k=0;k<16;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nr<size && nc>=0 && nc<size){
                        dp[nr][nc][i]+=dp[r][c][i-1];
                        //cout<<dp[nr][nc][i]<<'\n';
                    }
                }
            }
        }
    }
    
    return dp[e1][e2][numMoves];
}
int main(){
    int size;
    cin>>size;
    int s1, s2,e1,e2;
    cin>>s1>>s2>>e1>>e2;
    
   int numMoves;
   cin>>numMoves;
   cout<<howMany(size,s1,s2,e1,e2,numMoves)<<'\n';
}
