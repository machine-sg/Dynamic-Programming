#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair
#define INF 1e9


int a[50], b[50], c[50], d[50];
int p;

	bool isOk(int fromI, int fromJ, int toI, int toJ) 
	{
		//unsigned int x=0;
		for (int x=0; x<p;x++) {
		if( ((fromI==a[x]) && (fromJ == b[x]) && (toI == c[x]) && (toJ == d[x])) ||
			((toI==a[x]) && (toJ == b[x]) && (fromI == c[x]) && (fromJ == d[x])) )
			return false;
		}
		return true;
	}

	ll numWays(int width, int height, vector <string> bad)
	{
		memset(&a, 0, 50);
		memset(&b, 0, 50);
		memset(&c, 0, 50);
		memset(&d, 0, 50);
		p = (int)bad.size();

		long long S[101][101];// = {0};
		for(int i=0; i<101; ++i) {
			for(int j=0; j<101; ++j) {
				S[i][j] = 0;
			}
		}
		S[0][0] = 1;
		for(int i=0; i < (int)bad.size(); ++i) {
			string str = bad[i];
			istringstream iss(str);
			int a1,b1,c1,d1;
			while(iss >> a1 >>b1 >> c1 >>d1){
				//cout << "found entry " << a1<< " " << b1 << " " << c1 <<" "<<d1 <<"\n";
				a[i]=a1;
				b[i]=b1;
				c[i]=c1;
				d[i]=d1;
			}
		}
		
		for(int i=0; i<=width; ++i) {
			for(int j=0; j<=height;++j) {
				if(i>0) {
					if(isOk(i, j, i-1, j)) {
						S[i][j]  += S[i-1][j];
					}
				}
				if(j>0) {
					if(isOk(i, j, i, j-1)) {
						S[i][j] += S[i][j-1];
					}
				}
			}
			cout << endl;
		}
		return S[width][height];
	}


int main() {
vector<string> s;
s.push_back("0 0 1 0");
s.push_back("6 6 5 6");
 cout << numWays(6,6,s);

return 0;
}
